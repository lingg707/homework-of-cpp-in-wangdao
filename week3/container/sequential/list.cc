#include <iostream>
#include<list>
using std::endl;
using std::cout;
using std::list;

template <class T>
void disp(const T &a)
{
    for(auto & it:a)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
struct comparator
{
    bool operator()(int x,int y) const
    {
        return x>y;
    }
};
void test1()
{
    list<int> numbers1{5,2,78,1,9};
    list<int> numbers2{32,65,87,21,36};
   // numbers1.merge(numbers2);//numbers2全部插入numbers1中，numbers2消失
    disp(numbers1);
    disp(numbers2);
    comparator cmp;
    numbers1.sort(cmp);
    disp(numbers1);
    numbers1.sort();
    disp(numbers1);
    numbers1.reverse();
    disp(numbers1);

    auto start=numbers2.begin();
    auto end=numbers2.end();
    list<int>::iterator it=numbers1.begin();
    numbers1.splice(it,numbers2,start,end);
    cout<<endl<<endl;
    disp(numbers1);
    disp(numbers2);
        auto it2 = numbers1.end();
            --it2;

                numbers1.splice(numbers1.begin(), numbers1, it2);
                    cout << "numbers1:";
                        disp(numbers1);
}
int main()
{
    test1();
    return 0;
}
