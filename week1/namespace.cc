#include <iostream>
using namespace std;
int number=1;
namespace wd
{
int number=10;

namespace tls
{
int number=100;
void display()
{
    cout<<"wd::tls::display()"<<endl;
}
}//end of tls
void display(int number)
{
    cout<<"形参number="<<number<<endl;
    cout<<"wd空间中的number="<<number<<endl;
    cout<<"tls空间中的number="<<number<<endl;
}
}//end of wd

int main(void)
{
    using wd::tls::display;
    display();
    return 0;
}
