#include "Producer.h"
#include "TaskQue.h"

#include <unistd.h>
#include <stdlib.h>

#include <iostream>
using std::endl;
using std::cout;

namespace  wd
{
    void Producer::run()
{
    srand(time(nullptr));
    int cnt =10;
    while(cnt--)
    {
        int number=rand()%100;
        _que.push(number);
        cout<<"Producer thread:"<<pthread_self()<<"  cnt="<<cnt
            <<" produce a number:"<<number<<endl;
        sleep(1);
    }
}

}//end of namespace wd

