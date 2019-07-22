#pragma once

#include "Noncopyable.h"

#include <pthread.h>

namespace wd
{
class Thread
{
public:
    Thread() {}

    void start();
    void join();

    virtual ~Thread();
private:
    virtual void run()=0;
    static void * threadfunc(void* arg);
private:
    pthread_t _pthid;
    bool _isRunning;
};
}//end of namespace wd
