#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;
//单例对象自动释放
//方案三：具有平台相关性
//	atexit + pthread_once
class Singleton
{
public:
static Singleton * getInstance()
{
pthread_once(&_once, init);
return _pInstance;
}
static void init()
{
_pInstance = new Singleton();
atexit(destroy);
}
static void destroy()
{
if(_pInstance)
delete _pInstance;
}
void print()const
{	cout << "Singleton::print()" << endl;	}
private:
Singleton() {	cout << "Singleton()" << endl;	}
~Singleton() {	cout << "~Singleton()" << endl;	}
private:
static Singleton * _pInstance;
static pthread_once_t _once;
};
Singleton * Singleton::_pInstance = nullptr;//懒（饿）汉模式(懒加载)
//Singleton * Singleton::_pInstance = getInstance();//饱汉模式
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;
int main(void)
{
Singleton* p1 = Singleton::getInstance();
p1->print();
return 0;
}
