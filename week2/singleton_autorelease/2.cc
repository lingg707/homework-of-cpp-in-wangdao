#include <iostream>
using namespace std;
//atexit+static methed

class singleton
{
public:
    static singleton *getinstance()//设置静态的原因：要在类之外定义，多个对象访问同一个空间
    {
        if(_pinstance==nullptr)
        {
            _pinstance=new singleton();
            atexit(destroy);
        }
            return _pinstance;
    }
#if 1 
    static void destroy()//why static ?how will it be used??
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
};

singleton *singleton::_pinstance=getinstance();//饱汉模式
//singleton *singleton::_pinstance=nullptr;//懒汉模式


int main()
{
    singleton* p1=singleton::getinstance();
    p1->print();
    return 0;
}

