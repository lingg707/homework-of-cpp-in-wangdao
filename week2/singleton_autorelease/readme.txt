单例设计模式的升级，就是利用嵌套类实现singleton模式的自动调用析构
1、嵌套类加静态对象；要利用线程安全实现互斥
2、静态方法destroy +atexit方法
    多线程环境下是非线程安全的
3、 atexit+ pthread_once函数的实现，
