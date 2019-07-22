#pragma once

#include <pthread.h>
#include <errno.h>

#include <iostream>
using std::endl;
using std::cout;

namespace wd
{
class mutexlock
{
public:
    mutexlock() 
    :_islock(false)
    {
        pthread_mutex_init(&_mutex,nullptr);//这个man不到啊
        perror("pthread_mutex_init");
    }
    void lock()
    {
        if(pthread_mutex_lock(&_mutex))
        {
            perror("pthread_mutex_lock");
        }
        _islock=true;
    }
//表达禁止复制的语句
    mutexlock(const mutexlock &)=delete;
    mutexlock & operator=(const mutexlock &)=delete;

    void unlock()
    {
        if(pthread_mutex_unlock(&_mutex))
        {
            perror("pthread_mutex_unlock");
        }
        _islock=false;
    }
    pthread_mutex_t * getmutexptr()
    {
        return &_mutex;
    }
    bool islock() const
    {
        return _islock;
    }
    ~mutexlock() {
        if(pthread_mutex_destroy(&_mutex))
        {
            perror("pthread_mutex_destroy");
        }
    }

private:
pthread_mutex_t _mutex;
bool _islock;
};

//这个类是干啥的不知道啊
//这个类调用结束的时候会自动调用析构函数，从而解锁，保证加锁与解锁的过程实现
class mutexlockguard
{
public:
    mutexlockguard(mutexlock & mutex)
        :_mutex(mutex)
    {
        cout<<"mutexlockguard()";
        _mutex.lock();
    }
    ~mutexlockguard()
    {
        cout<<"~mutexlockguard()";
        _mutex.unlock();
    }
private:
         mutexlock & _mutex;
};

}
