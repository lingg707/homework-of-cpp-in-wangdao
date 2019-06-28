#include <iostream>
using std::cout;
using std::endl;

class data
{
public:
    data(int data =1)//这是啥初始化的方法？？
        :_data(data)
    {
        cout<<"data(int)"<<endl;
    }
    void print()const
    {
        cout<<"_data="<<_data<<endl;
    }
    ~data()
    {
        cout<<"~data()"<<endl;
    }
private:
    int _data;
};

class middlelayer
{
public:
    middlelayer(data *pdata)
        :_pdata(pdata)
    {
        cout<<"middlelayer(data *)"<<endl;
    }
//指针运算符和解引用运算符的重载
    data *operator->()
    {
        return _pdata;
    }
    data &operator *()
    {
        return *_pdata;
    }

    ~middlelayer()
    {
        cout<<"~middlelayer()"<<endl;
        if(_pdata)
        {
            delete _pdata;
        }
    }
private:
    data *_pdata;
};

class thirdlayer
{
public:
    thirdlayer(middlelayer * pml)
        :_pml(pml)
    {
        cout<<"thirdlayer(middlelayer *)"<<endl;
    }
    middlelayer & operator->()
    {
        return *_pml;
    }
    ~thirdlayer()
    {
        cout<<"~thirdlayer()"<<endl;
        if(_pml)
            delete _pml;
    }
private:
    middlelayer *_pml;
};

int main()
{
    data *pdata=new data(12);
    pdata->print();
    (*pdata).print();
    delete pdata;
    cout<<endl;

    //只能指针的雏形
    middlelayer ml(new data(10));
    ml->print();//简写
    (*ml).print();

    cout<<endl;
    return 0;


}
