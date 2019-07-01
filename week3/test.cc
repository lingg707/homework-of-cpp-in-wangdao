#include <iostream>
using namespace std;

template <typename T, int NUM>
T fun(T a)
{
        return a * NUM;
}

//调用

int main()
{
cout << fun<int, 4>(3) << endl;
    return 0;
}

