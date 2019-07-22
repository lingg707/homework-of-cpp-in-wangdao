#pragma once

namespace  wd
{

class Noncopyable
{
protected:
    Noncopyable() {}
    ~Noncopyable() {}

//只知道是表达禁止复制，但是运算符重载的部分还有写法完全不会
    Noncopyable(const Noncopyable&)=delete;
    Noncopyable & operator=(const Noncopyable &)=delete;

};
}//end of namespace wd
