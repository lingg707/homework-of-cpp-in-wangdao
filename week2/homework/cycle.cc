#include <iostream>
using std::cout;
using std::endl;
#define pi 3.14

class cycle
{
public:
    cycle()
        :_r(0)
    {
        cout<<"cycle()"<<endl;
    }
    cycle(double r)
        :_r(r)
    {
        cout<<"cycle(double r)"<<endl;
    }
    double getarea() const
    {
        //cout<<"getarea()";
        return pi*_r*_r;
    }
    double getperimeter() const
    {
       // cout<<"getperimeter()";
        return 2*pi*_r;
    }
    ~cycle()
    {
        cout<<"~cycle()"<<endl;
    }
    void show() const
    {
        cout<<"radius="<<_r<<endl
            <<"perimeter="<<getperimeter()<<endl
            <<"area="<<getarea()<<endl;
    }
private:
    double _r;
};

class cylinder
    :public cycle
{
    public:
        cylinder(double r,double h)
            :cycle(r)//call the create func of type cycle
             ,_h(h)
             ,_r(r)
        {
                cout<<"cylinder(double,double)"<<endl;   
        }   
        double getvolume()
        {
            return getarea()*_h;
        }
        void showvolume()
        {
            cout<<"volume of cylinder is:"<<getvolume()<<endl;
        }
        void show1()
        {
        cout<<"radius="<<_r<<endl
            <<"area="<<getarea()<<endl
            <<"height="<<_h<<endl
            <<"volume="<<getvolume()<<endl;
        }
        ~cylinder()
        {
            cout<<"~cylinder()"<<endl;
        }

    private:
        double _h;
        double _r;
};

int main()
{
    cylinder zhu(3.0,4.0);
    zhu.show();
    cout<<endl;
    zhu.show1();
    return 0;
}


