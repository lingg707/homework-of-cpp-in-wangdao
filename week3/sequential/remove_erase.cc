#include <iostream>
#include <list>
#include <functional>
using namespace std;

template <class T>
void disp(T &s)
{
    auto it=s.begin();
    while(it!=s.end())
    {
        cout<<*it++<<" ";
    }
    cout<<endl;
}   

void test1()
{
    int sz[5]={1,2,3,4,5};
    list<int> a(sz,sz+5);//使用的是数组名来作为指针替代迭代器，所以数组名和迭代
//    器的结构实际上是相同的？？
    auto iter=a.begin();
    iter++;
    iter=a.erase(iter);//使用erase函数
    cout<<"a.size():"<<a.size()<<endl;
    a.clear();
    cout<<"clear()之后的容器元素个数为："<<a.size()<<endl;//clear之后容器为0
    disp(a);
}

void testremove()
{
    int x=9;
    std::list<int> a={1,100,2,4,10,11,-1,12,1};
    a.remove(1);//能够移除所有的1
    disp(a);
//    a.remove_if([](int n){  return n>9;  });//lambda表达式
    //[]里是capture list,里面只能穿形参，不能传具体数字
    a.remove_if([x](int n){  return n>x;  });//lambda表达式//x不传值则默认为0
    disp(a);
    auto func1=[](int i) {return i+4;};
    cout<<"func1:"<<func1(6)<<endl;

    //需要添加头文件#include <functional>
    std::function<int(int)> func2=[x](int i){    return i+4; };
    cout<<"func2:"<<func2(6)<<endl;
}

int main()
{
    testremove();
    return 0;
}
