#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

//抽象类的第二种形式：定义了protected构造函数的类称为抽象类
class Base
{
public:
    Base(const char * base)
        : _base(new char[strlen(base) + 1]())
    {   
        cout << "Base(double)" << endl; 
        strcpy(_base, base);
    }

   // virtual
        void print() const 
        {   cout << "Base::_base = " << _base << endl;  }

    //规定: 一旦当类中定义了虚函数，都要将析构函数设为虚函数
  //  virtual
        ~Base()  //只有一个
        {
            delete [] _base;
            cout << "~Base()" << endl;
        }

private:
    char * _base;
};

class Derived
: public Base
{
public:
    Derived(const char * base, const char * derived)
        : Base(base)
          , _derived(new char[strlen(derived) + 1]())
    {
        cout << "Derived(double,double)" << endl;
        strcpy(_derived, derived);
    }

    void print() const
    {   
        Base::print();
        cout << "Derived::_derived = " << _derived << endl;
    }

    ~Derived()
    {
        delete [] _derived;
        cout << "~Derived()" << endl;
    }

private:
    char * _derived;
};
int main(void)
{
    Base * pbase = new Derived ("hello", "wolrd");
    //以下的方法是使用虚函数的机制。第二种方法是未使用虚函数机制，取消virtual标识
    //依然可以执行
   // pbase->print();
   // delete pbase;//使用虚函数机制，调用到派生类的析构函数
    
    //将基类指针强转成子类指针，然后delete子类的指针，先执行的是子类的析构函数
    //然后是基类的析构函数,这样也是一种析构对象的方法
      Derived * pderived = (Derived*) pbase;
      delete pderived;

    return 0;
}
