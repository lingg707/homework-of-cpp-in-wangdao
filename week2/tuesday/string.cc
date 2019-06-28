#include <stdio.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main(void)
{
    int a = 1;
    int * p = new int(10);
    string s1 = "hello";
    string s2 = "helloworldaaaaa";//栈空间
    string s3 = "helloworldaaaaaa";//大于15个字节在堆空间

    string s4 = s1;
    string s5 = s3;//深拷贝
    cout << "sizeof(s1) = " << sizeof(s1) << endl;
    cout << "sizeof(s2) = " << sizeof(s2) << endl;
    cout << "sizeof(s3) = " << sizeof(s3) << endl;
    cout << "sizeof(s4) = " << sizeof(s4) << endl;

    cout << "s1 = " << s1 << endl;
    printf("s1's address is %p\n", s1.c_str());
    cout << "s4 = " << s4 << endl;
    printf("s4's address is %p\n", s4.c_str());
    cout << "s2 = " << s2 << endl;
    printf("s2's address is %p\n", s2.c_str());
    cout << "s3 = " << s3 << endl;
    printf("s3's address is %p\n", s3.c_str());
    cout << "s5 = " << s5 << endl;
    printf("s5's address is %p\n", s5.c_str());
    printf("&a = %p\n", &a);
    printf("p = %p\n", p);

    return 0;
}
