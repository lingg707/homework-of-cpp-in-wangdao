//输入流迭代器
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;
//copy函数是啥，是algorithm里面的吗？
int main()
{
    vector<int> ob;                 //创建vector<int>容器ob
    istream_iterator<int,char> isi(cin);    //创建输入流迭代器osi
    copy(isi,istream_iterator<int,char>(),back_inserter(ob));       //将输入流插入到ob中
    //只作了解
    for (vector<int>::iterator it=ob.begin();it!=ob.end();it++) //遍历输出ob中的元素
    {
        cout<<(*it)<<"  ";
}
cout<<endl;
return 0;
}

