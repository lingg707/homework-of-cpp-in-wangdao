//取消了run的接口，使用了function方法，回调函数
#pragma once

#include "Noncopyable.h"
#include <pthread.h>
#include <functional>

using std::function;
using std::move;

namespace  wd
{
class Thread
    :Noncopyable//是不是继承了这个类，所建立的子线程就无法被复制？
{
public:
    //表示ThreadCallBack是一个类型
    using ThreadCallBack=function<void()>;//不会使用function函数。这个究竟是什么方法？？
//下面的Thread()意思是赋值函数,ThreadCallBack类型的cb赋值给Thread类
    Thread(ThreadCallBack && cb) //这里cb不就已经是右值引用了吗，为什么还要用move方法？？
        :_pthid(0),_isRunning(false),_cb(move(cb))//将左值引用强制转换成右值引用，从而使用移动语义
    {}

    void start();
    void join();

    ~Thread(); 
private:
    // virtual void run()=0;//待执行的任务,run方法要在具体的线程中实现，因此要设置为纯虚函数
    static void *threadfunc(void *arg);//threadfunc是pthread_create中
    //必须要传的参数，只能传一个void *的参数，如果在类内部的空间，则会
    //自动传一个this指针，因此要用static修饰，设置到静态区，这样才能保证
    //只传一个参数

private:
    pthread_t _pthid;//线程标识符，标识唯一的线程
    bool _isRunning;
    ThreadCallBack _cb;
};
}//end of namespace wd
