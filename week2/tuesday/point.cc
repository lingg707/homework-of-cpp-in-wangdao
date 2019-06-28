#include <math.h>
#include <iostream>
using std::endl;
using std::cout;
//+=运算符重载
//前置++和后置++重载
//类型转化函数

class complex
{
public:
    complex(double real,double imag)
        :_real(real),_imag(imag)
    {}

    void print () const
    {
        cout<<_real<<"+"<<_imag<<"i"<<endl;
    }

    complex & operator +=(const complex & rhs)
    {
        cout<<"complex & operator+=(const complex &rhs)"<<endl;
        _real+=rhs._real;
        _imag+=rhs._imag;
        return *this;//这句话干嘛的？？？
    }

    //前置++
    //前置返回的是引用]
    complex & operator++()
    {
        ++_real;
        ++_imag;
        return *this;
    }

    //后置++,返回的是对象
    complex operator++(int)
    {
        complex tmp (*this);
        ++_real;
        ++_imag;
        return tmp;
    }

    friend std::ostream & operator<<(std::ostream & os,const complex & rhs);

private:
    double _real;
    double _imag;
};

class point 
{
public:
    point(int ix=0,int iy=0)
        :_ix(ix),_iy(iy)
    {
        cout<<"point(int,int)"<<endl;
    }

    void print() const
    {
        cout<<"("<<_ix<<","<<_iy<<")"<<endl;
    }
//类型转换函数：
    operator int()
    {
        cout<<"operator int()"<<endl;
        return _ix;
    }
    operator double()
    {
        cout<<"operator double()"<<endl;
        return _ix*_iy;
    }
    operator complex()
    {
        return complex(_ix,_iy);
    }

    friend std::ostream & operator<<(std::ostream &os,const point & rhs);

private:
    int _ix;
    int _iy;
};

std::ostream & operator<<(std::ostream & os,const point & rhs)
{
    os<<"("<<rhs._ix<<","<<rhs._iy<<")"<<endl;
    return os;
}
#if 1
//如果不对complex类进行输出流运算符重载，则会报错：undefined reference to `operator<<(std::ostream&, complex const&)`
std::ostream & operator<<(std::ostream & os,const complex & rhs)
{
    os<<rhs._real<<"+"<<rhs._imag<<"i"<<endl;
    return os;
}
#endif
int main(void)
{
    point pt1(1,2);
    cout<<"pt1="<<pt1<<endl;//输出的是输出流运算符重载的格式
    pt1=10;//输出point(int,int),这为啥是个构造函数啊？？？
    cout<<"pt1="<<pt1<<endl;

    int x;
    x=pt1;//调用类型强转,类比int d=1.2，结果d=1；因此pt1是坐标，x是int型第一个值10
    cout<<"x="<<x<<endl;
    cout<<"pt1="<<pt1 <<endl;

    double y=pt1;//double类型强转定义的是返回两坐标乘积
    cout<<"y="<<y <<endl;
    cout<<"pt1="<<pt1 <<endl;

    complex c=pt1;
    cout<<"c="<<c;
    return 0;
}
