map.cc:
map默认情况下是升序的方式进行排列，
不能存放关键字相同的 元素
支持下标访问运算符，时间复杂度为红黑树的访问时间复杂度
如果关键字存在，则可以对value进行修改，如果不存在，则直接以关键字创建一个元素
或者直接添加一个新元素
查找元素find/count，返回值为1或0（返回值为匹配的个数，但是容器不允许重复）size_t类型
count：仅仅能得出该元素是否存在。find： 能够返回该元素的迭代器 。
pair的两个形参，第一个是迭代器，第二个是bool

multimap.cc:
multimap的特性及用法和map完全相同，唯一的不同点是multimap允许键值重复，因此底层插入
操作采用的是红黑树的insert_equal()而非insert_unique()


两个容器被定义为std里面的class templates：
class Allocator = allocator<pair<const Key, T> > 
缺省的内存模型是allocator，由C++标准程序库提供
