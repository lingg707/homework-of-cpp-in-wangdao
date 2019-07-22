#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int sz[6]={1,2,3,4,5,6};
    vector<int> ob(sz,sz+6);                    //创建vector<int>容器ob
    ostream_iterator<int,char> osi(cout," ");   //创建输出流迭代器osi, 将osi理解为容器
    copy(ob.begin(),ob.end(),osi);              //将ob复制到流中: copy是泛型算法.这个语句是输出
    cout<<endl;

//    getchar();
    return 0;

}

