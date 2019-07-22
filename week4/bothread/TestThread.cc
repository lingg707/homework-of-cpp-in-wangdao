#include "Thread.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <memory>

using namespace wd;
using std::cout;
using std::endl;
using std::unique_ptr;
using std::bind;

#if 0
class MyTask//Thread类里面写了禁止复制的函数
//:public wd::Thread//start和join已经实现，不需要重载，仅仅需要实现run方法
{
public:
    void run()
    {
        srand(clock());
        int cnt=20;
        while(cnt--)
        {
            int number=::rand()%100;
            cout<<"Sub thread:"<<pthread_self()<<" number="<<number<<endl;
            sleep(1);
            //::sleep(1);//::这个是什么意思啊？？？
        }
    }
};
#endif
void task_process()//函数容器的类型是function<void()>
{
    srand(clock());
    int cnt=20;
    while(cnt--)
    {
        int number=rand()%100;
        cout<<"sub thread:"<<pthread_self()
            <<"number="<<number<<endl;
        sleep(1);
    }
}

int main()
{
    //下面这句话是什么意思啊？？
    unique_ptr<Thread> thread(new Thread(task_process));
    thread->start();//start里面创造了线程，线程的传参函数是pthreadfunc，该函数里面存储了run方法
    //因此只需要执行start接口就可以了，这样可以在派生类中实现run方法，实现接口的实例化，并且隐藏了run
    thread->join();
  //  MyThread thread1;
    //MyThread thread2=thread1;//报错call to implicitly-deleted copy constructor of 'MyThread'
    return 0;
}
