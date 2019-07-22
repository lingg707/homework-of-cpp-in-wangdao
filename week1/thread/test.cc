#include "mutexlock.h"
#include "condition.h"

#include <iostream>
using std::cout;
using std::endl;

int tickets=100;
bool flag=true;
wd::mutexlock mutex;
wd::condition cond(mutex);

void * threadfunc1(void * arg)
{
    int cnt=50;
    while(cnt--)
    {
        wd::mutexlockguard autolock(mutex);//使用wd空间的mutexlockgurad对象，是一种autolock的方法
        if(!flag){
            cond.wait();
        }
        --tickets;
        cout<<"1号窗口卖出票之后，还剩余："<<tickets<<endl;
        if(flag)
            flag=false;
        cond.notify();
    }
    return nullptr;
}
void * threadfunc2(void * arg)
{
    int cnt=50;
    while(cnt--)
    {
        wd::mutexlockguard autolock(mutex);//使用wd空间的mutexlockgurad对象，是一种autolock的方法
        if(flag){
            cond.wait();
        }
        --tickets;
        cout<<"2号窗口卖出票之后，还剩余："<<tickets<<endl;
        if(!flag)
            flag=true;
        cond.notify();
    }
    return nullptr;//为啥要return nullptr
}

int main()
{
    pthread_t pthid1,pthid2;

    pthread_create(&pthid1,nullptr,threadfunc1,nullptr);
    pthread_create(&pthid2,nullptr,threadfunc2,nullptr);

    pthread_join(pthid1,nullptr);
    pthread_join(pthid2,nullptr);
    return 0;

}

