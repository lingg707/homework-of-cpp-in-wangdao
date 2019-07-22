#pragma once
#include "mutexlock.h"

#include <iostream>
using std::cout;
using std::endl;

namespace wd{

class condition
{
public:
    condition(mutexlock & mutex)
        :_mutex(mutex){
            if(pthread_cond_init(&_cond,nullptr))
            {
                perror("pthread_cond_init");
            }
        }

    void wait()
    {
        if (pthread_cond_wait(&_cond,_mutex.getmutexptr()))
        {
            perror("pthread_cond_wait");
        }
    }
    void notify()
    {
        if(pthread_cond_signal(&_cond))
        {
            perror("pthread_cond_signal");
        }
    }
    void notifyall()
    {
        if(pthread_cond_broadcast(&_cond))
        {
            perror("pthread_cond_broadcast");
        }
    }

    ~condition() {
        if(pthread_cond_destroy(&_cond))
        {
            perror("pthread_cond_destroy");
        }
    }

private:
    pthread_cond_t _cond;
    mutexlock & _mutex;//与mutexlock类的连接引用
};
}//end of namespace wd
