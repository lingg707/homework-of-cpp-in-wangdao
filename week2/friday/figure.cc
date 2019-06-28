#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

//面向对象设计原则
////    > 开闭原则 : 对修改关闭，对扩展开放

class Figure
{
public:
    virtual
        void display() const = 0;

    virtual 
        double area() const = 0;
};

class Rectangle
: public Figure
{
public:
    Rectangle(size_t length, size_t width)
        : _length(length)
          , _width(width)
    {}

    void display() const 
    {   cout << "rectangle";    }

    double area() const
    {   return _length * _width;    }

private:
    size_t _length;
    size_t _width;
};

class Circle
: public Figure
{
public:
    Circle(double radius)
        : _radius(radius)
    {}

    void display() const
    {   cout << "circle";   }

    double area() const
    {   return 3.14159 * _radius * _radius; }

private:
    double _radius;
};

class Triangle
: public Figure
{
public:
    Triangle(size_t a, size_t b, size_t c)
        : _a(a)
          , _b(b)
          , _c(c)
    {}

    void display() const
    {   cout << "triangle"; }

    double area() const
    {
        size_t p = (_a + _b + _c) / 2;
        return sqrt(p * (p - _a) * (p - _b) * (p - _c));
    }

private:
    size_t _a;
    size_t _b;
    size_t _c;
};

void display(Figure & fig)
{
    fig.display();
    cout << " 's area is " << fig.area() << endl;
}


int main(void)
{
    Rectangle rectangle(3, 4);
    Triangle triangle(3, 4, 5);
    Circle circle(10);
    display(rectangle);
    display(triangle);
    display(circle);

    return 0;
}
