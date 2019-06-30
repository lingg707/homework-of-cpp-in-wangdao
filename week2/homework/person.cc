#include <iostream>
using std::endl;
using std::cout;
using std::string;

class person
{
public:
    person(string name,int age)
        :_name(name)
         ,_age(age)
    {
        cout<<"person()"<<endl;
    }
    void display()const
    {
        cout<<"name:"<<_name<<endl
            <<"age:"<<_age<<endl;
    }
    ~person()
    {
        cout<<"~person()"<<endl;
    }
private:
    string _name;
    int _age;
};

class employee
:public person
{
public:
    employee(string department,double salary,string name,int age)//chushihuayidiingyaoshuru sige canshu ma 
        :person(name,age)
         ,_department(department)//field '_department' will be initialized after field '_salary'
         ,_salary(salary)
       //  ,_department(department)//field '_department' will be initialized after field '_salary'
    {
        cout<<"employee()"<<endl;
    }
    void display1() const
    {
        display();
        cout<<"department:"<<_department<<endl
            <<"salary:"<<_salary<<endl<<endl;
    }
    ~employee()
    {
        cout<<"~employee()"<<endl;
    }
private:
    double _salary;
    string _department;
};

double average(double one,double two,double three)
{
    cout<<"average salary:"<<(one+two+three)/3<<endl;;//tpye convert may be needed here
    return 0;
}

int main()
{
    employee james("sale",18.8,"james",23);
    employee lingg707("tech",34.6,"lingg707",22);
    employee lele("hr",20.1,"lele",26);
    james.display1();
    lingg707.display1();
    lele.display1();
    average(18.8,34.6,20.1);//could the average func be stated as other formate??
    return 0;
}

