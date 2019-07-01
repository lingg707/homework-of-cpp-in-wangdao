#include <iostream>
using namespace std;
//实例化问题，创建对象的过程就成为实例化的过程
//模板参数推导的机制
//模板就是一个代码生成器
//会影响执行速度
//函数模板和普通函数可以重载，函数模板之间也可以重载
//实现模板的先声明后实现
template <class T>
T add(T,T);

template <class T>
T add(T x,T y)
{
    cout<<"template"<<endl;
    return x+y;
}

int main()
{
    int x=2,y=3;
    char a='a',b=2;
    double z=3.2,c=4.3;
    cout<<add(x,y)<<endl;
    cout<<add(a,b)<<endl;
    cout<<add<double>(z,x)<<endl;
    return 0;
}

