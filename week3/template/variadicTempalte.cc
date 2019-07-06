#include <iostream>
using std::endl;
using std::cout;

template <class ...Args>
void print(Args... args)
{
    cout<<sizeof...(Args)<<endl;
    cout<<sizeof...(args)<<endl;
}
#if 1
void display()
{
    ;
}
#endif
#if 0
template<typename T>
void display(T t)
{
    cout<<t<<endl;
}
#endif
template <class T,class ... Args>
void display(T t,Args... args)
{
    cout<<t<<endl;
    display(args...);
}
int main()
{
    display(10,2.3,"helo",'c');
    return 0;
}
