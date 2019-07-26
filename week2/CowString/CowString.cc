#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class CowString
{
    //设计模式的代理模式
    class Proxy
    {
    public:
        Proxy(CowString & self,int idx)
            :_self(self),_idx(idx)
        {   cout<<"Proxy()"<<endl;  }
        //实现读操作,重载Proxy类的<<运算符即可
        //声明为友元的原因：要访问_idx成员
        friend std::ostream & operator<<(std::ostream & os,const Proxy & rhs);

        char & operator=(const char & ch);

    private:
        CowString & _self;
        int _idx;
    };
public:
    CowString()
        :_pstr(new char[1+4]()+4)//结构是引用计数加字符串，因此加四字节才是字符串的开始
    {
        cout<<"CowString()"<<endl;
        initRefcount();
    }
    CowString(const char * pstr)
        :_pstr(new char[strlen(pstr)+5]+4)
    {
        cout<<"CowString(const char * pstr)"<<endl;
        initRefcount();
        strcpy(_pstr,pstr);
    }
    CowString(const CowString & rhs)
        :_pstr(rhs._pstr)
    {
        cout<<"CowString(const CowString & rhs)"<<endl;
        increaseRefcount();
    }


    CowString & operator=(const CowString & rhs)
    {
        cout<<"CowString & operator=(const CowString & rhs)"<<endl;
        if(this!=&rhs){
            //if((*this)!=rhs){
            release();

            _pstr=rhs._pstr;
            increaseRefcount();
        }
        return *this;
        }

        ~CowString()
        {
            release();
        }

        int size() const
        {
            return strlen(_pstr);
        }
        const char * c_str() const
        {
            return _pstr;
        }
        int recount() const
        {
            return *(int*)(_pstr-4);
        }

        //char & operator[](int idx);//使用代理模式之后，进行读操作，返回值应该是代理
        Proxy operator[](int idx);//运算符重载，返回值是Proxy类型，进行读操作
        const char & operator[](int idx) const
        {
            cout<<"const char & operator[](int idx) const"<<endl;
            return _pstr[idx];
        }

        //下面的输出流运算符重载的实现，无法单独实现，因为Proxy类型是私有的
        //本来只重载了CowString的运算符，后来又在CowString的类里面声明Proxy
        //的重载函数为友元
        friend std::ostream & operator<<(std::ostream & os,const CowString & rhs);
        //因此，下面这个运算符重载也要写，就是为了解除Proxy类运算符重载的访问限制i
        //这个函数在两个类里面都进行了声明
        friend std::ostream & operator<<(std::ostream & os,const Proxy & rhs);

    private:
        void initRefcount()
        {   *(int*)(_pstr-4)=1; }
        void increaseRefcount()
        {   ++*(int*)(_pstr-4);     }//没有区别就用前置++，效率更高
        void decreaseRefcount()
        {   --*(int*)(_pstr-4);     }
        void release()
        {   
            decreaseRefcount();
            if(recount()==0)
            {
                delete [] (_pstr-4);
                cout<<"delete heap data"<<endl;
            }
        }

    private:
        char * _pstr;
    };

    //不清楚<<运算符，基类和代理类都实现了重载，究竟输出的时候使用的是谁的运算符？？
    std::ostream & operator <<(std::ostream & os,const CowString & rhs)
    {
        os<<rhs._pstr;
        cout<<"CowString's << operator"<<endl;
        return os;
    }

    //这个应该是读操作
    CowString::Proxy CowString::operator[](int idx)
    {
        cout<<"CowString::Proxy CowString::operator[](int idx)"<<endl;
        return Proxy(*this, idx);
    }

    //写操作
    //过程：开辟一块新的空间，把内容复制过去，引用计数初始化
    //老的内容继续保留在原来的地址上，实现写时复制
    char & CowString::Proxy::operator=(const char & ch)//写操作的运算符重载
    {
        cout<<"operator = of write"<<endl;
        if(_idx>=0&&_idx<_self.size()){
            if(_self.recount()>1){
                _self.decreaseRefcount();

                char *ptmp=new char[_self.size()+5]+4;
                strcpy(ptmp,_self._pstr);//传内容
                _self._pstr=ptmp;//传地址,_self拥有了一块新的地址，旧的内容放在ptmp里
                _self.initRefcount();
            }
            _self._pstr[_idx]=ch;
            return _self._pstr[_idx];
        }
#if 0 
        else{
            static char nullptr='\0';
            cout<<"下标越界"<<endl;
            return nullchar;//这玩意是个啥？？
        }
#endif
    }

    std::ostream & operator<<(std::ostream & os,const CowString::Proxy & rhs)
    {
        os<<rhs._self._pstr[rhs._idx];
        cout<<"Proxy's << operator"<<endl;
        return os;
    }

    int main(void)
    {
        CowString s1;//调用默认构造函数，s1里面是空的，未赋值
        CowString s2 = s1;//调用复制构造函数（括号内为类型声明的对象）
        cout << "s1 = " << s1 << endl;//输出的时候调用了CowString的<<
        cout << "s2 = " << s2 << endl;
        cout << "s1' refcount = " << s1.recount() << endl;//直接输出int型，未重载
        cout << "s2' refcount = " << s2.recount() << endl;

        //初始化构造函数可以直接使用等号赋值的形式？？
        CowString s3 = "hello,world";//调用初始化构造函数（括号内为初始化的内容）
        CowString s4 = s3;//复制构造函数
        cout << "s3 = " << s3 << endl;//CowString<<重载
        cout << "s4 = " << s4 << endl;//先输出元素，再输出函数名
        cout << "s3' refcount = " << s3.recount() << endl;
        cout << "s4' refcount = " << s4.recount() << endl;
        printf("s3's address is %p\n", s3.c_str());
        printf("s4's address is %p\n", s4.c_str());//3和4的地址相同，0x55aba232e2a4

        cout << "执行s2 = s4 之后:" << endl;
        s2 = s4;//赋值运算符
        cout << "s2 = " << s2 << endl;
        cout << "s3 = " << s3 << endl;
        cout << "s4 = " << s4 << endl;

        cout << "s2' refcount = " << s2.recount() << endl;
        cout << "s3' refcount = " << s3.recount() << endl;
        cout << "s4' refcount = " << s4.recount() << endl;
        printf("s2's address is %p\n", s2.c_str());
        printf("s3's address is %p\n", s3.c_str());
        printf("s4's address is %p\n", s4.c_str());

        cout << endl << "执行写操作：" << endl;
        //下面一个语句使用了：下标访问运算符，赋值运算符，Proxy构造函数
        //CowString::Proxy CowString::operator[](int idx)
        //char & CowString::Proxy::operator=(const char & ch)
        (s2[0] = 'H');//CharProxy().operator=(char);
        cout << "s2 = " << s2 << endl;
        cout << "s3 = " << s3 << endl;
        cout << "s4 = " << s4 << endl;
        cout << "s3' refcount = " << s3.recount() << endl;
        cout << "s4' refcount = " << s4.recount() << endl;
        printf("s2's address is %p\n", s2.c_str());//这个地址修改了，重新分配了空间
        printf("s3's address is %p\n", s3.c_str());//c_str是一个函数
        printf("s4's address is %p\n", s4.c_str());


        //读操作使用的是Proxy的<<,返回值是Proxy的[]重载
        //读操作时使用下标访问运算符，读取固定的一位
        cout << endl << "执行读操作:" << endl;
        //下标访问运算符返回的时Proxy类型，因此，<<重载也是使用的Proxy类型的 
        cout << "s3[0] = " << s3[0] << endl;// cout << CharProxy() 
        cout << "s2 = " << s2 << endl;
        cout << "s3 = " << s3 << endl;
        cout << "s4 = " << s4 << endl;
        cout << "s2' refcount = " << s2.recount() << endl;
        cout << "s3' refcount = " << s3.recount() << endl;
        cout << "s4' refcount = " << s4.recount() << endl;
        printf("s2's address is %p\n", s2.c_str());
        printf("s3's address is %p\n", s3.c_str());
        printf("s4's address is %p\n", s4.c_str());

    }

