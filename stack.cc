//在堆上生成对象，使用new关键词操作，其过程分为两阶段：
//第一阶段，使用new在堆上寻找可用内存，分配给对象；第二阶段，调用构造函数生成对象。
//将new操作设置为私有，那么第一阶段就无法完成，就不能够再堆上生成对象
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

class student
{
private:
    int _id;
    char *_name;
public:
    student(int id,const char* name)
    {
        _name=new char[strlen(name)+1]();
        _id=id;
        strcpy(_name,name);
        std::cout<<"student构造函数"<<std::endl;
        printf("addr is :%p\n",this);
    }
    void print() const
    {
        std::cout<<"(" << _id << ", " << _name << ")" << std::endl;
    }
    ~student()
    {
        delete []_name;
        std::cout<<"析构函数"<<std::endl;
    }
private:
      void *operator new(std::size_t size);//第一个参数和返回值都是固定的,老师两个地方都加了static
      void operator delete(void *pvoid);//重载new就必须重载delete，这里老师加了static，不知道有啥用
};
int main(void)
{
    student s1(101,"lili");
    s1.print();
    //student *pstu=NULL;
    //strcpy(pstu->_name,"hello");
    //pstu->_id=10;
    // delete pstu;//calling a private destructor of class 'student'
    //应该是因为delete属于destroy类
    return 0;           
}
