sequencecontainer.cc:
实现了各种顺序容器：
test0：
测试了vector容器。，使用了auto关键字，begin，end，insert方法
insert接口第一个参数是迭代器，用来指示插入的位置，第二个参数是要插入的数值
实现一个容器插入另外一个容器
实现了shrink_to_fit()接口
实现了clear接口

test1（）：
deque没有capacity方法
insert的三种插入方式，两形参类型，三形参类型，另外一个容器插入类型，也是三个形参
同样也有clear和shrink_to_fit方法
是不是同一时刻一个容器只能由一个迭代器指向？？？

test3():
写了list的用法。
list同样也没有capacity方法，结构为双向链表  
不支持下标访问，只支持双向访问


list.cc
实现了sort的使用方法，sort定义在std中，可传参，传参的值为bool类型
实现了merge接口,都是list容器的接口,merge实现的不是简单的插入，而是部分有序的插入,
将寻找一个下一个元素小于待插入元素的位置，然后插入
实现reverse接口
实现了splice接口，一共两个形参，第一个形参是迭代器，第二个形参是另外一个容器，
从第二个容器里面转移元素给第一个，不复制或者移动元素，仅重指向链表节点的内部指针，
元素被插入到pos迭代器所指向的元素之前.

test.cc:验证 了splice函数的用法

remove_erase.cc:
实现了erase和remove的用法，remove_if中，使用了lambda表达式，实现了满足一定条件的
数据的删除

