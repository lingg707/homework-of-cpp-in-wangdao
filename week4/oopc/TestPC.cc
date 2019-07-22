#include "Consumer.h"
#include "TaskQue.h"
#include "Producer.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;
using namespace wd;

int main()
{
    TaskQue tq(10);

    std::unique_ptr<Thread> producer1(new Producer(tq));
    std::unique_ptr<Thread> producer2(new Producer(tq));
    std::unique_ptr<Thread> consumer1(new Consumer(tq));
    std::unique_ptr<Thread> consumer2(new Consumer(tq));

    producer1->start();
    producer2->start();
    
    consumer1->start();
    consumer2->start();

    producer1->join();
    producer2->join();

    consumer1->join();
    consumer2->join();

    return 0;
}
