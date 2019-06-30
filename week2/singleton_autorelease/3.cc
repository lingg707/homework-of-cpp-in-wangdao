#include <pthread.h>
#include <iostream>
using std::endl;
using std::cout;
//correlationship with paltform
//atexit+pthread_once

class singleton
{
public:
    static singleton *getinstance()//设置静态的原因：要在类之外定义，多个对象访问同一个空间
    {
        pthread_once(&_once,init);
        return _pinstance;
    }
    static void init()
    {
        _pinstance=new singleton();
        atexit(destroy);
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
    static pthread_once_t _once;//what's this????    
};

//singleton *singleton::_pinstance=getinstance();//饱汉模式
singleton *singleton::_pinstance=nullptr;//懒汉模式
pthread_once_t singleton::_once=PTHREAD_ONCE_INIT;

int main(void)
{
    singleton* p1=singleton::getinstance();
    p1->print();
    return 0;
}

