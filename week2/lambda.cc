#include <iostream>

using std::cout;
using std::endl;

void func1(int x)
{
    static int cnt =0;
    ++cnt;
    cout<<"func1(int) x="<<x<<endl;
    cout<<"func1 has been called :"<<cnt<<" times"<<endl;
}

struct example
{
    int operator()(int x,int y)
    {
        ++cnt;
        cout<<"operator()(int,int) has been calledi "<<cnt<<" times"<<endl;
        return x+y;
    }

    int operator()(int x,int y,int z)
    {
        return x+y+z;
    }
    int cnt=0;//函数对象携带的状态 => 闭包 => lambda表达式 => 匿名函数
};

int main()

{
#if 0
    example ex;
    int a=2,b=3,c=4;
    //重载了函数调用运算符的类创建的对象称为函数对象
    cout<<"ex(a,b)="<<ex(a,b)<<endl;
    cout<<"ex(a,b,c)="<<ex(a,b,c)
        <<endl;
    cout<<"ex(a,b,)"<<ex(a,b)<<endl;

    example ex2;
    func1(a);
    func1(a);
#endif
    auto f1=[](int number){
        cout<<"lambda expreesion"<<endl;
        cout<<"number="<<number<<endl;
    };
    int a=4;
    f1(a);//make a as a parameter trans to 
    return 0;
}
