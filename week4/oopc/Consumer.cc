#include "TaskQue.h"
#include "Consumer.h"

#include <unistd.h>

#include <iostream>

using std::endl;
using std::cout;

namespace wd
{
    void Consumer::run()
{
    int cnt=10;
    while(cnt--){
        int number=_que.pop();
        cout<<"Consumer thread:"<<pthread_self()<<"  cnt="<<cnt
            <<" consume a number："<<number<<endl;
        sleep(1);
    }
}

}//end of namespace wd

