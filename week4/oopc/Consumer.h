#pragma once

#include "Thread.h"

namespace  wd
{
class TaskQue;

class Consumer
    :public Thread
{
public:
    Consumer(TaskQue & que)
    :_que(que)
    {}

private:
    void run();
private:
    TaskQue & _que;
};
}//end of namespace wd
