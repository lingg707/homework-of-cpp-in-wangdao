//这里面是用queue容器实现的TaskQue队列，是第一次使用这种用法吗？？有点生疏
#include "TaskQue.h"

#include <iostream>

using std::cout;
using std::endl;
namespace wd
{
    
TaskQue::TaskQue(size_t queSize)
    :_queSize(queSize),_mutex(),_notFull(_mutex),_notEmpty(_mutex),_flag(true)
{}
bool TaskQue::empty() const
{
    return _que.size()==0;//_que是一个queue型容器
}
bool TaskQue::full() const
{
    return _que.size()==_queSize;//_queSize是类中初始化设置的que大小
}

//运行在生产者线程
void TaskQue::push(ElemType & elem)
{
    MutexLockGuard autolock(_mutex);
    while(full()){
        _notFull.wait();//使用while循环是为了防止出现虚假唤醒的情况
        //cout<<"生产者等待"<<endl;
    }
    _que.push(elem);
    _notEmpty.notify();
}

//运行在消费者线程
ElemType TaskQue::pop()//这里使用了RAII技术(没看出来？？？)
{
    MutexLockGuard autolock(_mutex);
    while(_flag&&empty()){
        _notEmpty.wait();
        //cout<<"消费者等待"<<endl;
    }
    if(_flag){
        ElemType elem =_que.front();
        _que.pop();
        _notFull.notify();

        return elem;
    }
    else{
        return nullptr;
    }
}

void TaskQue::wakeup()
{
    _flag=false;
    _notEmpty.notifyAll();
}

}//end of namespace wd

