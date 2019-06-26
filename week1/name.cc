#include <iostream>
//#include <stdio.h>
using std::cout;
using std::endl;

void add(int &a,int &b)
{
    int temp;
    temp=a+b;
    cout<<"add2="<<temp<<endl;
}
void add(int &a,int &b,int &c)
{
    int temp;
    temp=a+b+c;
    cout<<"add3="<<temp<<endl;
}
int main()
{
    int a=1;
    int b=2;
    int c=3;
    add(a,b);
    add(a,b,c);
    return 0;
}

