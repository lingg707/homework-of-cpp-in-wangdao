文档要求实现的步骤：GameConfig、GameTime、WarcraftWorld、Headquarters、Warriors、
City
具体实现的分类是：
city.cc、city.h
gameconfig.cc   gameconfig.h
gametime.cc     gametime.h
headquarters.cc 
warcraftworld.cc
warrior.cc
weapon.cc

priority_queue  参数   < class T,
                             class Container = std::vector<T>,
                             class Compare = std::less<typename Container::value_type>

不是很清楚怎么划分文件，只知道在同一个文件里面写代码

size_t是为了增加程序的可移植性才增加的
在32位系统上是32位无符号整性，64位系统上是unsigned long
