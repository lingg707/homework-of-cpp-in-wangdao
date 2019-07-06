标准库提供了三种顺序容器适配器：queue(FIFO队列)、priority_queue(优先级队列)、stack(栈)
适配器是使一种事物的行为类似于另外一种事物行为的机制
eg：stack<int,vector<int>>实现了栈的功能，但是其内部使用顺序容器vector<int>来存储数据，
相当于是vector<int>表现出了栈的行为


