#include <functional>
#include <queue>
#include <vector>
#include <iostream>

using std::priority_queue;
using std::cout;
using std::endl;
using std::vector;
using std::greater;


template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';

}

int main() {
    priority_queue<int> q;

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q.push(n);

    print_queue(q);//输出从大到小的排列
#if 1   
    priority_queue<int, vector<int>, greater<int> > q2;
    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q2.push(n);
    print_queue(q2);//输出从小到大的排列

    // 用 lambda 比较元素。
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };//^表示按位异或,其实这个语句看不太懂
    priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

   // for(int n : {1,8,5,6,3,4,0,9,7,2})
    for(int n : {0,1,2,3,4,5,6,7})
        q3.push(n);
   // print_queue(q3);//8 9 6 7 4 5 2 3 0 1
    print_queue(q3);//8 6 7 5 1,  实现的方法，每个数与1异或，结果是偶数加一，奇数减一
#endif
}
