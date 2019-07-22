#include <iostream>
#include <string>
#include <map>
#include <memory>

using std::endl;
using std::cout;
using std::string;
using std::map;
using std::make_pair;
using std::unique_ptr;

class Student
{
public:
    Student(int id,const string & name=string())
    :_id(id),_name(name)
    {
        cout<<"Student(int,string)"<<endl;
    }
    int getid() const
    {
        return _id;
    }
    string getname() const
    {
        return _name;
    }
    void setid(int id)
    {
        _id=id;
    }
    void setname(string name)
    {
        _name=name;
    }
    ~Student()
    {
        cout<<"~Student()"<<endl;
    }
private:
    int _id;
    string _name;
};

class view
{
public:
    view(Student *stu=nullptr)
        :_stu(stu)
    {
        cout<<"view(Student *)"<<endl;
    }

    void reset(Student *student)
    {
        _stu=student;
    }
    virtual void show() const
    {
        cout<<"id:"<<_stu->getid()<<endl
            <<"name:"<<_stu->getname()<<endl;
    }
private:
    Student *_stu;
};

class controller
{
public:
    void attach(const Student & s)
    {
        _students.insert(make_pair(s.getid(),s));
    }

    void detach(int id)
    {
        _students.erase(id);
    }
    void show(view *v)
    {
        for(auto it=_students.begin();it!=_students.end();it++ )
        {
            v->reset(&(it->second));
            v->show();
            cout<<endl;
        }
    }

private:
    map<int ,Student> _students;
};
int main()
{
    controller ctrl;
    ctrl.attach(Student(2,"Mike"));
    unique_ptr<view>  v(new view());
    ctrl.show(v.get());
    return 0;
}
