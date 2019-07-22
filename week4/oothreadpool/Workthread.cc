#include "Threadpool.h"
#include "Workthread.h"

#include <unistd.h>

#include <iostream>

using std::cout;
using std::endl;

namespace wd
{
Workthread::Workthread(Threadpool & threadpool)
    :_threadpool(threadpool)
{
    cout<<"Workthread()"<<endl;
}

Workthread::~Workthread()
{
    cout<<"~Workthread()"<<endl;
}

void Workthread::run()
{
    _threadpool.threadfunc();
}

}//end of namespace wd
