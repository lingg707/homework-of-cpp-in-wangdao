#include <iostream>
#include <queue>
#include <vector>

using std::endl;
using std::cout;
using std::vector;
using std::priority_queue;

void test1()
{
    vector<int> vec{3,1,92,4,54,66,2,100};
    //priority_queue<int> numbers(vec.begin(),vec.end());
    priority_queue<int,vector<int>,std::greater<int>> numbers;
    for(auto it=vec.begin();it!=vec.end();it++)
    {
        numbers.push(*it);
        cout<<"优先级最高的元素是："<<numbers.top()<<endl;
    }
    while(!numbers.empty())
    {
        cout<<numbers.top()<<" ";
        numbers.pop();
    }
    cout<<endl;
}
int main()
{
    test1();
    return 0;
}

