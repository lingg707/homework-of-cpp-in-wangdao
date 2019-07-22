//为什么这些头文件都不需要析构函数？？？
#pragma once

#include "MutexLock.h"
#include "Condition.h"

#include <queue>
using std::queue;

namespace  wd
{
class TaskQue
{
public:
    TaskQue(size_t queSize=10);
    bool empty() const;
    bool full() const;
    void push(int number);
    int pop();

private:
    size_t _queSize;
    queue<int> _que;
    MutexLock _mutex;
    //notEmpty服务于消费者，notfull服务于生产者
    Condition _notFull;//必须初始化，为什么只有这一个成员提醒
    Condition _notEmpty;//这个和上面的Condition类，命名只是为了实现在不空或者不满
    //情况下的操作
};

}//end of namespace wd
