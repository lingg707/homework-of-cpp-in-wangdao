#include "Threadpool.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>

using std::cout;
using std::endl;
using namespace wd;

class MyTask
:public Task
{
public:
    void process()
    {
        ::srand(::time(nullptr));
        int number=::rand()%100;
        cout<<"sub thread"<<pthread_self()
            <<"MyTask :number="<<number<<endl;
        ::sleep(1);
    }
    ~MyTask()
    {   cout<<"~MyTask()"<<endl;   }
private:

};
int main()
{
    std::unique_ptr<Task> task(new MyTask());
    Threadpool threadpool;
    threadpool.start();

    int cnt=10;
    while(cnt--){
        threadpool.addTask(task.get());
        cout<<"main thread"<<pthread_self()
            << "  cnt="<<cnt<<endl;
    }

    threadpool.stop();

    return 0;
}

