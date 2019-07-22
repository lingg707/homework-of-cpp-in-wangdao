#include "Thread.h"

#include <iostream>

using std::cout;
using std::endl;

namespace  wd
{
void Thread::start()
{
    pthread_create(&_pthid,nullptr,threadfunc,this);//第四个参数为什么是this指针？
    _isRunning=true;
}

void* Thread::threadfunc(void* arg)
{
    Thread * pthread=static_cast<Thread*>(arg);//表示把arg强转成Thread*类型
    if(pthread)
        pthread->run();
    return nullptr;
}
void Thread::join()//用来等待一个线程的结束，线程间的同步的操作
    //该函数以阻塞的方式等待thread指定的线程结束，当函数返回时，被等待的线程的资源被
    //回收，如果线程已经结束，那么join函数会立即返回
{
    if(_isRunning)
        pthread_join(_pthid,nullptr);//第二个参数是用户定义的指针，用来存储被等待线程的返回值
    _isRunning=false;
}
Thread::~Thread()
{
    if(_isRunning)
        pthread_detach(_pthid);//pthread_detach是啥
}

}//end of namespace wd
