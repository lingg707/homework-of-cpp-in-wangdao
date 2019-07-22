#pragma once
#include "Thread.h"

namespace wd
{

class Threadpool;

class Workthread
    :public Thread
{
public:
   // Workthread(Threadpool & threadpool) {}//这样写是一个完整的函数，下面的写法是函数声明
   // 该写法会报错
    //Workthread(Threadpool & threadpool); 
    Workthread(Threadpool & threadpool);
    ~Workthread(); 

    void run();
private:
    Threadpool & _threadpool;
};

}//end of namespace wd
