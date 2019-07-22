#include "Thread.h"
#include <iostream>

using std::endl;
using std::cout;

namespace wd
{
    
void Thread::start()
{
    pthread_create(&_pthid,nullptr,threadfunc,this);
    _isRunning=true;
}

void * Thread::threadfunc(void *a )
{
    Thread * pthread=static_cast<Thread*>(a);
    if(pthread)
        pthread->run();
    return nullptr;
}

void Thread::join()
{
    if(_isRunning)
    {   pthread_join(_pthid,nullptr);  }
}

Thread::~Thread()
{
    if(_isRunning)
        pthread_detach(_pthid);
}
}//end of namespace wd
