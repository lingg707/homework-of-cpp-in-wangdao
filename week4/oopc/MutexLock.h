#pragma once

#include "Noncopyable.h"

#include <stdio.h>
#include <errno.h>
#include <pthread.h>

#include <iostream>

using std::endl;
using std::cout;

namespace  wd
{
class MutexLock
    :private Noncopyable
{
public:
    MutexLock() {}
    ~MutexLock() {}

    void lock()
    {
#if 0
        if(pthread_mutex_lock(&_mutex)){//成功返回0.失败返回非0，进入该函数语句
            perror("pthread_mutex_lock");
        }
#endif
        pthread_mutex_lock(&_mutex);//成功返回0.失败返回非0，进入该函数语句
        _isLocking=true;
    }
    void unlock()
    {
#if 0
        if(pthread_mutex_unlock(&_mutex))
        {
            perror("pthread_mutex_unlock");
        }
#endif
        pthread_mutex_unlock(&_mutex);
        _isLocking=false;
    }

    bool isLocking() const
    {   return _isLocking;  }
    
    pthread_mutex_t * getMutexLockPtr()//提供一个外部访问的接口
    {   return &_mutex;     }

private:
    pthread_mutex_t _mutex;
    bool _isLocking;
};


//为了防止忘了解锁，就直接用类封装，自动调用析构函数之后，解锁也自动执行，防止死锁
class MutexLockGuard
{
public:
    MutexLockGuard(MutexLock & mutex)
        :_mutex(mutex)
    {
        _mutex.lock();
    }
    ~MutexLockGuard()
    {
        _mutex.unlock();
    }

private:
    MutexLock & _mutex;
};

}//end of namespace wd
