#include <iostream>
#include <stack>
#include <string>

using std::cout;
using std::cin; 
using std::endl;
using std::stack;
using std::string;

int main()
{
    stack<char> sta;
    string s;
    cin>>s;//cin好像不会忽略空格
//    string::iterator iter=s.begin();
    auto iter=s.begin();//string也有迭代器啊？
    while(iter!=s.end())
    {
        if(*iter!=')')
            sta.push(*iter);
        else
        {
            while(sta.top() !='('&&!sta.empty())
            {
                sta.pop();
            }
            if(sta.empty())
            {
                cout<<"'('not match!"<<endl;
            }
            else
            {
                sta.pop();
                sta.push('@');
            }
        }
        ++iter;
    }
#if 1
    //这里是为了实现将括号中的内容全部弹出之后的剩余参数打印出来
    while(!sta.empty())
    {
        cout<<sta.top()<<endl;
        sta.pop();
    }
#endif
    return 0;
}

