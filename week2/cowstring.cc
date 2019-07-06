//设计模式之代理模式
//我还不知道哪些运算符重载需要在类内重载，哪些运算符重载需要声明为友元
#include <string.h>
#include <iostream>
using std::endl;
using std::cout;

class cowstring
{
    class proxy
    {
    public:
        proxy(cowstring & self,int idx)
            :_self(self)
             ,_idx(idx)
        {}

        char & operator=(const char& ch);

        friend std::ostream &operator<<(std::ostream & os,const proxy & rhs);
    private:
        cowstring &_self;//这里为啥一定要加&符号？？？
        int _idx;
    };
public:
    cowstring()
        :_sptr(new char [1+4]()+4)
    {
        cout<<"cowstring()"<<endl;
        initrefcount();
    }

};
