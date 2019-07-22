#include <iostream>
#include <vector>
#include <list>
#include <deque>

using std::endl;
using std::cout;
using std::deque;
using std::vector;
using std::list;
#if 0
class example
{
public:
    int _data;
    class pimpl;
};
#endif
#if 1
    template <class T>
void display(const T & c)
{
    typename T::const_iterator it=c.begin();
    while(it!=c.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
}
#endif
#if 0
void display(vector<int> &a)//vector<int>是一个类，类的声明定义需要加作用域限定符
{
    vector<int>::iterator it=a.begin();//类型定义了迭代器指向同类型的内函数
    while(it!=a.end())
    {
        cout<<*it++<<" ";
    }
    cout<<endl;
}
void display(deque<int> &a)
{
    deque<int>::iterator it=a.begin();
    while(it!=a.end())
    {
        cout<<*it++<<" ";
    }
    cout<<endl;
}
#endif
void test0()
{
    cout<<"vector"<<endl;
    //  vector<int> numbers(10,1);
    vector<int> numbers{1,2,3,4,5};//vector<int>型
    display(numbers);
    cout<<"numbers capacity="<<numbers.capacity()<<endl;
    cout<<"numbers size="<<numbers.size()<<endl;//还有一种形式：sizeof(numbers)
    //vector不提倡在头部添加元素或者删除元素i
    auto it =numbers.begin();
    auto it2=numbers.insert(it,22);//在头部插入，不提倡但是可以，时间复杂度较高
    cout<<"*it="<<*it<<endl;//此时这个迭代器失效了，为啥失效？？
    cout<<"*it2="<<*it2<<endl;
    display(numbers);
    cout << "numbers[2] = " << numbers[2] << endl;//可以使用下标访问运算符
    numbers.push_back(12);//这个可以用

    display(numbers);
    numbers.pop_back();//删除最后一个元素
    display(numbers);
    numbers.insert(it2,24);//可以是三个形参，第一个形参是位置，第二个形参是个数，第三个形参时插入的数值
    display(numbers);
    cout<<"*it2="<<*it2<<endl;

    //实现两个容器回合
    it=numbers.end();
    vector<int> numbers2{42,43,44,45};
    numbers.insert(it,numbers2.begin(),numbers2.end());//实现两个容器的混合
    display(numbers);
    cout<<"numbers capacity="<<numbers.capacity()<<endl;
    cout<<"numbers size="<<numbers.size()<<endl;//还有一种形式：sizeof(numbers)
    numbers.shrink_to_fit();//回收多余的空间,一定会缩水到与numberssize相同的大小
    cout<<"numbers capacity="<<numbers.capacity()<<endl;
    cout<<"numbers size="<<numbers.size()<<endl;//还有一种形式：sizeof(numbers)
    cout<<"clear()"<<endl;
    numbers.clear();
    display(numbers);
    numbers.shrink_to_fit();
    cout<<"numbers capacity="<<numbers.capacity()<<endl;
}

void test1()
{
    int arr[5]={1,2,3,4,5};
    deque<int> numbers(10,2);
    deque<int> numbers2(arr,arr+5);
    display(numbers);
    display(numbers2);
    deque<int> numbers3{1,2,3,4,5};
    display(numbers3);
    cout<<"numbwers3[2]="<<numbers3[2]<<endl;
    auto it =numbers.begin();
    it+=1;
    cout<<"*it="<<*it<<endl;
    auto it2=numbers.insert(it,3);
    display(numbers);
    cout<<"*it2="<<*it2<<endl;

    numbers.insert(it2,2,35);
    display(numbers);
    vector<int> t={6,6,6,6,6,6};
    numbers.insert(it2,t.begin(),t.end());
    display(numbers);
    numbers.clear();
    display(numbers);
    numbers.shrink_to_fit();
    cout<<numbers.size();
}
#if 0
void display(list<int> &a)
{
    list<int>::iterator it=a.begin();
    while(it!=a.end())
    {
        cout<<*it++<<" ";
    }
    cout<<endl;
}
#endif
void test2()
{
    int arr[5]={1,2,3,4,5};
    list<int> numbers{1,2,3,4,5};//双向链表
    display(numbers);
    list<int>numbers1(10);
    list<int>numbers2(arr,arr+5);//这个是干啥的？？
    display(numbers1);
    display(numbers2);
    numbers.push_back(21); //时间复杂度为O(1)
    numbers.push_front(31);
    display(numbers);
    numbers.pop_front();
    display(numbers);

    auto it=numbers.begin();
    auto it2=numbers.insert(it,44);
    display(numbers);
    vector<int> e={9,9,9,9,9};
    numbers.insert(it2,e.begin(),e.end());
    display(numbers);
    numbers.clear();
    display(numbers);
    cout<<numbers.size();

}
int main()
{
    test2();
    return 0;
}

