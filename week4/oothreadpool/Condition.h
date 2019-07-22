#pragma once

#include "MutexLock.h"
#include <iostream>

using std::endl;
using std::cout;
using namespace wd;

namespace  wd
{
class Condition
{
public:
    Condition(MutexLock & mutex) //必须显示的初始化_mutex，why？？？
        :_mutex(mutex)
    {
        if(pthread_cond_init(&_cond,nullptr))//第二个参数是condaddr，我也不知道是什么
        {   perror("pthread_cond_init");    }
    }
    //析构函数用的是destroy方法
    ~Condition() {
        if(pthread_cond_destroy(&_cond)){
            perror("pthread_cond_destroy");
        }
    }

    void wait()
    {
#if 0
        if(pthread_cond_wait(&_cond,_mutex.getMutexLockPtr())){////两个形参都是引用的形式 
            perror("pthread_cond_wait");
        }
#endif
        pthread_cond_wait(&_cond,_mutex.getMutexLockPtr());////两个形参都是引用的形式 
    }

    void notify()
    {
        if(pthread_cond_signal(&_cond)){
            perror("pthread_cond_signal");
        }
    }

    void notifyAll()
    {
        if(pthread_cond_broadcast(&_cond)){
            perror("pthread_cond_broadcast");
        }
    }

private:
    pthread_cond_t _cond;//本类内定义的成员，直接声明，类之外定义的，都要传引用，
    //因此_mutex元素传引用
    MutexLock & _mutex;
};
}//end of namespace wd
