#pragma once

#include "TaskQue.h"

#include <vector>
#include <memory>
#include <iostream>

using std::vector;
using std::unique_ptr;
using std::endl;
using std::cout;

namespace  wd
{
class Task;
class Thread;

class Threadpool
{
    friend class Workthread;//这是什么类，为什么要设置成friend类？？？
public:
    Threadpool(size_t threadNum=4,size_t _queSize=10); 
    ~Threadpool(); 

    void start();
    void addTask(Task *task);
    void stop();

private:
    Task * GetTask();
    void threadfunc();

private:
    size_t _threadNum;//线程池中线程的数量
    size_t _queSize;//任务队列的长度
    vector<unique_ptr<Thread>> _threads;//为什么要用这个容器？？/
    TaskQue _taskque;//生产者消费者里面写过这个成员
    bool _isExit;
};

}//end of namespace wd
