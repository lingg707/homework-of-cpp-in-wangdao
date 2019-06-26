#include "line.h"
#include <iostream>
#include <math.h>

using namespace std;
//头文件中定义整个类，文件中定义需要隐藏的嵌套类
class line::linepimpl//在隐藏的类中，嵌套定义想隐藏的类，比如point
{
    //需要隐藏line类的实现
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
        ~point()
        {
            cout<<"~point()"<<endl;
        }
    private:
        int _ix;int _iy;
    };
public:
    linepimpl(int x1,int y1,int x2,int y2)//隐藏的嵌套类的构造函数
        :_pt1(x1,y1),_pt2(x2,y2)
    {
        cout<<"linepimpl(int,int,int,int)"<<endl;     
    }
    void printline() const
    {
        _pt1.print();
        cout<<"---->";
        _pt2.print();
        cout<<endl;
    }
    ~linepimpl()
    {
        cout<<"~linepimpl()"<<endl;
    }
private:
    point _pt1;
    point _pt2;
};

line::line(int x1,int y1,int x2,int y2)//整个大类的构造函数的实现
    :_pimpl(new linepimpl(x1,y1,x2,y2))//大类定义的成员，为嵌套类类型对象
{
    cout<<"line(int,int,int,int)"<<endl;
}

line::~line()
{
    if(_pimpl)
    {
        delete _pimpl;//整个大类初始化的时候new了一下
    }
}
void line::printline() const//void和const一定要加，要不然无法编译
{
    _pimpl->printline();
}
