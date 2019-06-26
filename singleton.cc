//要求：通过某一个类在内存中只能创建唯一的对象
//该对象不能是栈对象
//该对象只能是一个堆对象，所定义的对象均指向同一个空间、
//应用场景：
//单例模式替换全局变量
//配置文件内容可以用单例对象存储
//词典文件和网页库
#include <iostream>
using std::cout;
using std::endl;

class singleton
{
public:
    static singleton* getinstance()//静态构造函数，函数指针，返回一个类的指针
    {
        if(_pinstance==nullptr)
        {
            _pinstance=new singleton();
        }
        return _pinstance;
    }
    static void destroy()
    {
        if(_pinstance)
            delete _pinstance;//这一句会自动调用析构函数
    }
    void print() 
    {
        cout<<"singleton::data="<<_data<<endl;
    }
private:
    singleton()
        :_data(1)
    {
        cout<<"singleton()"<<endl;
    }
    ~singleton()
    {
        cout<<"~singleton()"<<endl;
    }
private:
    int _data;
    static singleton *_pinstance;//为了初始化，使用构造函数u，将其放入静态变量区
};
singleton * singleton::_pinstance=nullptr;//静态变量的初始化

int main(void)
{
//    singleton s1;//不能建立栈对象
//    singleton * p=new singleton();//这个为啥不行？
    singleton *p1=singleton::getinstance();//用静态的指针来访问赋值，给成员分配空间
    singleton *p2=singleton::getinstance();//p1和p2的空间相同，符合只能是一个堆对象的条件
    singleton::getinstance()->print();
    cout<<"p1="<<p1<<endl
        <<"p2="<<p2<<endl;
    singleton::destroy();
    return 0;
}
