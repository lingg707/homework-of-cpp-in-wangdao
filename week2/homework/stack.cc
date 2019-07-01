#include <iostream>
using std::cout;
using std::endl;

class stack
{
public:
    explicit//表明构造函数是显式的，explicit关键字只对有一个参数的类构造函数有效
        stack(int size=10)
        :_top(-1)
         ,_size(size)
         ,_base(new int[_size]())
    {}
    bool empty()const
    {
        return _top==-1;
    }
    bool full()const
    {
        return _top==_size-1;
    }
    void push(int number)
    {
        if(!full())
        {
            _base[++_top]=number;
        }
        else
        {
            cout<<"stack full"<<endl;
        }
    }
    void pop()
    {
        if(!empty())
        {
            _top--;
            cout<<"pop:"<<_base[_top]<<endl;
        }
        else
        {
            cout<<"stack empty"<<endl;
        }
    }
    int top()
    {
        return _base[_top];
    }
private:
        int _top;
        int _size;
        int *_base;
};
int main()
{
    stack s;
    cout<<"is empty?"<<s.empty()<<endl;
    s.push(2);
    cout<<"is empty?"<<s.empty()<<endl;

    for(int idx=3;idx!=13;idx++)
    {
        s.push(idx);
    }
    cout<<"is full?"<<s.full()<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
    cout<<"is empty?"<<s.empty()<<endl;
    return 0;
}
