#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
    String()
    {
        _pstr=NULL;
        //_pstr=new char[0];
        cout<<"无参构造函数"<<endl;
    }
    String(const char *str)
    {
        _pstr=new char[strlen(str)+1];
        strcpy(_pstr,str);
        cout<<"有参构造函数"<<endl;
    }
    String(const String & rhs)
    {
        _pstr=new char[strlen(rhs._pstr)+1];
        strcpy(_pstr,rhs._pstr);

        cout<<"复制构造函数"<<endl;
    }
    String & operator=(const String & rhs)
    {
        delete []_pstr;
        cout<<"string operator"<<endl;
        if(!rhs._pstr)
        {
            *_pstr=0;
        }
        else
        {
            _pstr=new char[strlen(rhs._pstr)+1];
            strcpy(_pstr,rhs._pstr);
        }
        return *this;
    }
    /*String & operator=(const String & rhs)
      {
      delete []_pstr;
      strcpy(_pstr,rhs._pstr);
      return *this;
      }*/
    ~String()
    {
        if(_pstr!=NULL)
        {
            delete [] _pstr;
            _pstr=NULL;
        }
        cout<<"clean memory"<<endl;
    }
    void print()
    {
        cout<<"print函数调用:"<<endl;
        cout<<"the string is:"<<_pstr<<endl;
    }
private:
    char *_pstr;
};


int main(void)
{
    String str1;
    str1.print();
    cout<<endl;
    String str2="hello,world";
    String str3("wangdao");

    str2.print();
    cout<<endl;
    str3.print();
    cout<<endl;
    String str4=str3;
    str4.print();
    cout<<endl;
    str4=str2;
    str4.print();
    cout<<endl;
    return 0;
}

