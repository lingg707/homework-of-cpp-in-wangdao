//通过析构函数的私有化实现
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

class student
{
public:
    int id;
    char name[10];
public:
    student()
    {
        std::cout<<"studen构造函数"<<std::endl;
        printf("addr is :%p\n",this);
    }
    void destroy()
    {
        delete this;
    }
private:
    ~student()
    {
        std::cout<<"析构函数"<<std::endl;
    }
};
int main(void)
{
    student *pstu=new student;
   strcpy(pstu->name,"hello");
    pstu->id=10;
    pstu->destroy();
//    delete pstu;//calling a private destructor of class 'student'
   //应该是因为delete属于destroy类
    return 0;
}
