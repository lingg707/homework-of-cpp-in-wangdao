#include <iostream>

using std::endl;
using std::cout;

class Queue
{
public:

    Queue(int size=10)
        :_size(size),_head(0),_rear(0),_base(new int[_size]())//new分配空间的时候不能进行初始化。默认初始化为0，手动初始化会报错
    {        cout<<"Queue(int)"<<endl;    }
    bool empty()
    {    return _head==_rear;    }
    bool full()
    {    return (_rear+1)%_size==_head;  }
    void push(int num)
    {   if(!full())
        {   _base[_rear]=num;_rear++; }
        else{   cout<<"满了"<<endl;    }
    }
    void pop()//注意判满判空
    {   if(!empty()){cout<<"pop:"<< _base[_head]<<endl; _head++;}
        else
        {   cout<<"空了"<<endl;    }
    }
    int front()
    {   return _base[_head];    }
    int back()
    {   return _base[_rear-1];  }

private:
    int _size;
    int _head;
    int _rear;
    int *_base;
};

int main()
{
    Queue q;
    cout<<"is empty?"<<q.empty()<<endl;
    q.push(2);
    cout<<"head:"<<q.front()<<endl;
    cout<<"after push, is empty? "<<q.empty()<<endl;
    int i=1;
    for(i=1;i<9;i++)
    {
        q.push(i);
    }
    cout<<"isfull? "<<q.full()<<endl;
    q.push(11);
    i=1;
    while(i<11)
    {  
        q.pop();i++;
    }

}
