#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

class NumVals
{
private:
    int val;
public:
    NumVals()
    {
        val = 0;
    }
    NumVals(int j)
    {
        val = j;
    }
    bool display()
    {
        cout << val << " ";
        return true;
    }
    bool isEven()
    {
        return (bool) !(val % 2);
    }
    bool isPrime()
    {
        for (int i = 2; i <= (val / 2); i++)
        {
            if (!(val % i)) return false;
        }
        return true;
    }
};

int main()
{
    //1. 
    vector<NumVals> v1(13);
    vector<NumVals>::iterator it1;
    for (int i = 0; i < 13; i++)
    {
        v1[i] = NumVals(i + 1);
    }

    cout << "v1中的原始值为: " << endl;
    for_each(v1.begin(), v1.end(), mem_fun_ref(&NumVals::display));
    cout << endl;

    // Use of mem_fun_ref calling member function through a reference
    // remove the primes in the vector using isPrime ( )
    it1 = remove_if(v1.begin(), v1.end(), mem_fun_ref(&NumVals::isPrime));
    cout << "v1中删除质数后剩下的值为: " << endl;
    for_each(v1.begin(), it1, mem_fun_ref(&NumVals::display));
    cout << endl;
    cout << endl;

    //2.
    vector<NumVals>v2(13);
    vector<NumVals>::iterator it2;
    for (int k = 0; k < 13; k++)
    {
        v2 [k] = NumVals (k + 1);
    }

    cout << "v2中的原始值为: " << endl;
    for_each(v2.begin(), v2.end(), mem_fun_ref(&NumVals::display));
    cout << endl;

    // Use of mem_fun_ref calling member function through a reference
    // remove the even numbers in the vector v2 using isEven ( )
    it2 = remove_if(v2.begin(), v2.end(), mem_fun_ref(&NumVals::isEven));
    cout << "v2中删除偶数后剩下的值为: " << endl;
    for_each(v2.begin(), it2, mem_fun_ref(&NumVals::display));
    cout << endl;

    getchar();
    return 0;
}

