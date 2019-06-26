#include <string.h> 
#include <string>
#include <iostream>

using std::cout;
using std::endl;

class String
{
public:
    String()
        :_pstr(new char[0]())
    {
        cout<<">>String()"<<endl;

    }
    String(const char *pstr)
        :_pstr(new char[strlen(pstr)+1]())
    {
        strcpy(_pstr,pstr);
        cout<<">>String(const char *pstr)"<<endl;

    }
    String(const String &rhs)
        :_pstr(new char[strlen(rhs._pstr)+1]())
    {
        strcpy(_pstr,rhs._pstr);
        cout<<">>String(const String &rhs)"<<endl;

    }
    String & operator=(const String &rhs)
    {
        delete []_pstr;
        strcpy(_pstr,rhs._pstr);
        return *this;

    }
    ~String()
    {
        delete []_pstr;
        cout<<">>~String()"<<endl;

    }
    void print()
    {
        cout<<">>String::print()"<<endl
            <<"_pstr:"<<_pstr<<endl<<endl<<endl;

    }
private:
    char* _pstr;

};
int main()
{
    std::cout << "Hello String" << std::endl;

    cout<<">>str1"<<endl;
    String str1;
    str1.print();

    cout<<">>str2"<<endl;
    String str2 = "Hello,world";
    str2.print();

    cout<<">>str3"<<endl;
    String str3("Wangdao");
    str3.print();

    cout<<">>str4"<<endl;
    String str4=str3;
    str4.print();

    str4=str2;
    str4.print();

    return 0;

}
