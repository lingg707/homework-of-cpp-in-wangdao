#pragma once

#include "Noncopyable.h"
#include <pthread.h>

namespace  wd
{
class Thread
    :Noncopyable//是不是继承了这个类，所建立的子线程就无法被复制？
{
public:
    Thread() 
    :_pthid(0),_isRunning(false)
    {}
    
    void start();
    void join();

    virtual ~Thread(); 
private:
    virtual void run()=0;//待执行的任务,run方法要在具体的线程中实现，因此要设置为纯虚函数
    static void *threadfunc(void *arg);//threadfunc是pthread_create中
    //必须要传的参数，只能传一个void *的参数，如果在类内部的空间，则会
    //自动传一个this指针，因此要用static修饰，设置到静态区，这样才能保证
    //只传一个参数

private:
pthread_t _pthid;//线程标识符，标识唯一的线程
bool _isRunning;
};
}//end of namespace wd
