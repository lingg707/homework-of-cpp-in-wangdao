#include <iostream>
using namespace std;
//成员函数形式的函数模板
//非模板的类
class example
{
public:example(double data)
       :_data(data)
    {}

       //函数模板的成员函数形式
       template <class T>//模板声明
           T typecast()//这个函数没见过
           {
               return T(_data);
           }
private:
       double _data;
};
int main()
{
    example e(11.11);
    cout<<e.typecast()<<endl;
    //cout<<e.typecast<int>()<<endl;
    return 0;
}

