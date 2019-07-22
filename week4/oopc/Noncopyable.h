//不知道=delete的用法，不知道为什么只能用protected来修饰，感觉private好像也可以
#pragma once
    
namespace wd
{
class Noncopyable
{
protected:
    Noncopyable() {}
    ~Noncopyable() {}
    
    //=delete表达式的意思还不是很懂，用法就是删除复制构造运算符和赋值运算符
    Noncopyable & operator=(const Noncopyable &)=delete;//复制构造函数
    Noncopyable(const Noncopyable &)=delete;//赋值函数
};
}//end of namespace wd
