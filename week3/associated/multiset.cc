#include <math.h>
#include <iostream>
#include <set> 
#include <string>
using std::cout;
using std::endl;
using std::multiset;
using std::string;

    template <class Container>
void display(const Container & c)
{
    for(auto & elem : c) {
        cout <<  elem << " ";
    }
    cout << endl;
}

void test0()
{
    //默认情况下按升序方式进行排列
    //
    //multiset中不能存放关键字相同的元素
    //multiset的底层实现采用的是红黑树 ==> 近似的平衡二叉树(AVL树)
    //      ==> 查找元素的时间复杂度为O(logN)  ==> 二分查找
    //
    //红黑树的特点:
    //  1. 节点不是红色就是黑色
    //  2. 根节点是黑色的
    //  3. 叶子节点都是黑色
    //  4. 不能有两个连续的红色节点
    //  5. 从根节点到任意一个叶子节点的路径上，黑色节点数目相同
    //
    multiset<int> numbers{4, 1, 2, 7, 9, 6, 5, 1, 3, 2, 1, 9, 8};
    display(numbers);

    //multiset不支持下标访问运算符
    //cout << numbers[0] << endl; //error

    multiset<int>::iterator it = numbers.begin();
    cout << "*it = " << *it << endl;

    //multiset中的元素不能进行修改, 是只读的
    //*it = 10;//error

    //查找元素
    //count用来判断元素是否在multiset之中
    size_t cnt = numbers.count(1);// 时间复杂度为 O(logN)
    cout << "1 是否存在: " << cnt << endl;

    cnt = numbers.count(10);
    cout << "10 是否存在: " << cnt << endl;

    //find查找到了返回的是迭代器，还可以访问元素
    multiset<int>::iterator it2 = numbers.find(2);// 时间复杂度为 O(logN)
    if(it2 != numbers.end()) {
        cout << " 查找到了关键字 2" << endl;
        cout << "*it2 = " << *it2 << endl;
    }

    it2 = numbers.find(10);
    if(it2 == numbers.end()) {
        cout << "没有查找到关键字10" << endl;
    }

    //添加新元素
    auto ret = numbers.insert(2);
    cout << *ret << endl;

    //范围查找
    auto it1 = numbers.lower_bound(1);
    it2 = numbers.upper_bound(1);
    while(it1 != it2) {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;

    auto ret2 = numbers.equal_range(2);
    cout << *ret2.first << endl;
    cout << *ret2.second << endl;
}

void test1()
{
    std::pair<int, string> pairs(100, "Jackie");
    cout << pairs.first << " --> " << pairs.second << endl;
}

void test2()
{
    multiset<int, std::greater<int>> numbers{4, 1, 2, 7, 9, 6, 5, 1, 3, 2, 1, 9, 8};
    display(numbers);

    //multiset不支持下标访问运算符
    //cout << numbers[0] << endl; //error

    multiset<int>::iterator it = numbers.begin();
    cout << "*it = " << *it << endl;

    //multiset中的元素不能进行修改, 是只读的
    //*it = 10;//error

    //查找元素
    //count用来判断元素是否在multiset之中
    size_t cnt = numbers.count(1);// 时间复杂度为 O(logN)
    cout << "1 是否存在: " << cnt << endl;

    cnt = numbers.count(10);
    cout << "10 是否存在: " << cnt << endl;

    //find查找到了返回的是迭代器，还可以访问元素
    multiset<int>::iterator it2 = numbers.find(2);// 时间复杂度为 O(logN)
    if(it2 != numbers.end()) {
        cout << " 查找到了关键字 2" << endl;
        cout << "*it2 = " << *it2 << endl;
    }

    it2 = numbers.find(10);
    if(it2 == numbers.end()) {
        cout << "没有查找到关键字10" << endl;
    }
}

class Point
{
public:
    Point(int ix, int iy)
        : _ix(ix)
          , _iy(iy)
    {   cout << "Point(int,int)" << endl;   }


    Point(const Point & rhs)
        : _ix(rhs._ix)
          , _iy(rhs._iy)
    {
        cout << "Point(const Point &)" << endl;
    }

    ~Point() {  cout << "~Point()" << endl; }

    double getDistance() const
    {
        return sqrt(_ix * _ix + _iy * _iy);
    }

    friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
private:
    int _ix;
    int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
    os << "(" << rhs._ix
        << "," << rhs._iy
        << ")";
    return os;
}

bool operator<(const Point & lhs, const Point & rhs)
{
    return lhs.getDistance() < rhs.getDistance();
}

struct Comparator
{
    bool operator()(const Point & lhs, const Point & rhs) const
    {
        return lhs.getDistance() > rhs.getDistance();
    }
};


void test3()
{
    multiset<Point, Comparator> points{
        Point(1, 2),
            Point(3, 4),
            Point(4, 5),
            Point(-1, 3),
            Point(-2, -4),
            Point(1, 2)
    };

    display(points);
}

int main(void)
{
    test3();
    //test1();
    //test2();
    //test3();
    return 0;
}
