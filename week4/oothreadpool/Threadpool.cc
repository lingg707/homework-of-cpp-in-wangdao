#include "Threadpool.h"
#include "Workthread.h"

#include <unistd.h>

#include <iostream>

using  std::cout;
using std::endl;

namespace wd
{
    Threadpool::Threadpool(size_t threadNum,size_t queSize)//头文件中已经设置了默认初始值
        //但是只是函数声明，并不是实现
        :_threadNum(threadNum),_queSize(queSize),_taskque(queSize),_isExit(false)
{
    _threads.reserve(_threadNum);//这里使用了容器的方法，究竟是干什么的？？？
}

Threadpool::~Threadpool()
{
    if(!_isExit)
        stop();
}
void Threadpool::start()
{
    for(size_t idx=0;idx!=_threadNum;idx++)
    {
        std::unique_ptr<Thread> thread(new Workthread(*this));
        _threads.push_back(std::move(thread));
    }

    for(auto & thread:_threads){
        thread->start();
    }
}

void Threadpool::stop()
{
    if(!_isExit){
        while(!_taskque.empty()){
            ::sleep(1);//这里表示全局函数
        }
        _isExit=true;
        _taskque.wakeup();
        for(auto & thread :_threads){
            thread->join();
        }
    }
}

void Threadpool::addTask(Task * task){
    _taskque.push(task);
}

Task * Threadpool::GetTask(){
    return _taskque.pop();
}

void Threadpool::threadfunc()
{
    while(!_isExit)
    {
        Task * task=GetTask();
        if(task)
            task->process();//当任务执行的速度过快，还有没将_isExit设置为true之前
        //每一个子线程已经阻塞在了gettask之后
    }
}

}//end of namespace wd
