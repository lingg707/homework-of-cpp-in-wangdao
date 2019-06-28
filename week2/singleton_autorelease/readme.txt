单例设计模式的升级，就是利用嵌套类实现singleton模式的自动调用析构
1、嵌套类加静态对象；要利用线程安全实现互斥
    实现细节：使用饱汉模式，在类创建的时候就实现隐藏类，
    第一步：singleton构造函数，创建一个autorelease类和pinstance指针对象
    第二部：用getinstance成员函数给pinstance指针对象分配空间，autorelease自动调用构造函数
    第三步：:
2、静态方法destroy +atexit方法
    多线程环境下是非线程安全的
3、 atexit+ pthread_once函数的实现，
