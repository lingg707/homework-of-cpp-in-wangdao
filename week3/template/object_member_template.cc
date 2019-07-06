#include <iostream>
using namespace std;

template<class T>
class outside
{
public:


    template<class R>
        class inside//inside类模板的访问权限为public，因此可以调用
        //outside<int>::inside<double>obin(3.5)
        {
        public:
            inside(R x)
            {
                cout<<"inside(R x)"<<endl;
                r=x;
            }
            void disp()
            {
                cout<<"inside:"<<r<<endl;
            }
        private:
            R r;
        };


    outside(T x)
        :t(x)
    {
        cout<<"outside(T x)"<<endl;
    }

    void disp()//模板类的成员函数可以在定义外实现，但必须是所有类定义的外面，不能放在outside内inside外实现
    {
        cout<<"outside:";
        t.disp();//调用inside的disp()函数
    }

private:
    inside<T>t;
};
int main()
{
    outside<int>::inside<double> obin(3.5);//声明inside类对象obin
    obin.disp();
    outside<int> obout(2);//创建outside类对象obout
    obout.disp();
    getchar();
    return 0;
}
