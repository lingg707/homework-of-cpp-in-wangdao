#include <iostream>
#include <algorithm> //使用for_each算法要包含的头文件   
#include <functional> //使用less<>类模板要用的头文件
#include <vector>
using namespace std;
typedef vector < int > VI;
typedef vector < int > ::iterator VIP;

int main()
{
    int sz[] = {1, 2, 3, 4, 5, 6};
    VI ob(sz, sz + 6);
    less< int > lt; //创建less<int>类函数对象
    replace_if(ob.begin(), ob.end(), not1(bind2nd(lt, 3)), 7);  //1 2 7 7 7 7

    for (VIP v = ob.begin();v != ob.end();v++)
    {
        cout << (*v) << "  ";
    }
    cout << endl;
    getchar();
    return 0;
}

