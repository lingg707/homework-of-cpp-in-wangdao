//实现run方法，初始任务队列
#pragma once

#include "Thread.h"

#include <iostream>

using std::endl;
using std::cout;

namespace wd
{
class TaskQue;
class Producer
    :public Thread
{
public:
    Producer(TaskQue & que)//不加引用会报错
    :_que(que)
    {}

private:
    void run();
private:
    TaskQue & _que;
};

}//end of namespace wd
