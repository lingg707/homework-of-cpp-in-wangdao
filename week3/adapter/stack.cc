#include <iostream>
#include <stack>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::stack;
using std::string;

int main()
{
    stack<string> words;
    string s;
    cout<<"enter words:(结束输入轻按ctrl+d)"<<endl;
    while (cin>>s)
    {
        words.push(s);
    }
    while(!words.empty())
    {
        cout<<words.top()<<endl;
        words.pop();
    }
    cout<<endl;
    return 0;
}

