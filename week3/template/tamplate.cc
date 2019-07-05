#include <iostream>
using namespace std;

//普通类模板
template <class T1,class T2>
class convert
{
public:
    T2 f(T1 data)
    {
        return T2(data);
    }
};
#if 1
//嵌套了模板函数的类模板
template <class T1>
class test
{
public:
    template<class T2>
        T1 f(T2 b)
        {
            return T1( b);//将b由T2类型强转成T1类型
        }
};
#endif
#if 0
template<class T1>
template<class T2>
T1 Test<T1>::f(T2 b)            //模板成员函数的实现
{
        return T1(b);           //将b由T2类型强制转换成T1类型
}

#endif
int main()
{
    convert<char,int>(c1);//这个c1外加不加括号都可以，应该和容器一样，最后一个树都是传参
    cout<<c1.f('A')<<endl;
    convert<int,short>c3;
    cout<<hex<<showbase<<c3.f(0x7fffffff)<<endl<<dec;

    //嵌套模板类的使用：
    test<int>t;
    cout<<t.f(3.14f)<<endl;
    getchar();

    return 0;
}

