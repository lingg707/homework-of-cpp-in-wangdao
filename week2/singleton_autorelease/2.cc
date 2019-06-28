#include <iostream>
using namespace std;
//嵌套类+静态对象

class singleton
{
    class autorelease//释放隐藏成员的析构函数是一个类
    {
    public:
        autorelease()
        {   cout<<"autorelease()"<<endl;  }
        ~autorelease()
        {
            if(_pinstance)
            {
                delete _pinstance;
            cout<<"~autorelease()"<<endl;
            }
        }
    };
public:
    static singleton *getinstance()//设置静态的原因：要在类之外定义，多个对象访问同一个空间
    {
        if(_pinstance==nullptr)
        {
            _pinstance=new singleton();
        }
            return _pinstance;
    }
#if 1 
    static void destroy()
    {
        if(_pinstance)
            delete _pinstance;
        cout<<"destroy()"<<endl;
    }
#endif
    void print() const
    {
        cout<<"singleton::print()"<<endl;
    }
private:
    singleton()
    {
        cout<<"singleton()"<<endl;
    }
    ~singleton()
    {
        cout<<"~singleton()"<<endl;
    }
private:
    static singleton * _pinstance;//non-const static data member must be initialized out of line
    static autorelease _autorelease;
};

//singleton *singleton::_pinstance=getinstance();//饱汉模式
singleton *singleton::_pinstance=nullptr;//懒汉模式

singleton::autorelease singleton::_autorelease;//singleton的autorelease方法初始化类中的_autorelease成员

int main()
{
    singleton* p1=singleton::getinstance();
    p1->print();
    return 0;
}

