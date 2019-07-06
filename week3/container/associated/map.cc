#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::pair;

    template <class Container>
void display(const Container & c)
{
    for(auto & elem : c) 
    {
        cout << elem.first << " --> " << elem.second << endl;

    }

}

void test0()
{
    //map默认情况下按升序方式进行排列
    //
    //不能存放关键字相同的元素
    //
    map<string, string> cities{
        pair<string, string>("010", "北京"),
            pair<string, string>("021", "上海"),
            std::make_pair("0755", "深圳"),
            std::make_pair("022", "天津"),
            std::make_pair("0755", "广州")
    };
    display(cities);

    //map支持下标访问运算符, 时间复杂度为 O(logN)
    cout << cities["010"] << endl;

    //如果关键字存在，还可以对value进行修改
    cities["010"] = "南京";
    cout << cities["010"] << endl;
    display(cities);

    //如果对应的关键字不存在，则会直接以该关键字创建一个元素
    cout << cities["027"] << endl;
    display(cities);

    cout << endl;
    //如果对应的关键字不存在，则会直接添加一个新元素
    cities["023"] = "重庆";
    display(cities);

    //查找元素 find/count
    size_t cnt = cities.count("01090");
    if(cnt) {
        cout << "查找成功！" << endl;
    } else {
        cout << "查找失败" << endl;
    }

    cities["027"] = "武汉";

    //pair<map<string, string>::iterator, bool> ret = 
    pair<map<string,string>::iterator,bool> ret = cities.insert(std::make_pair("027", "成都"));
    if(ret.second) {//insert方法通过返回pair中的第二个bool型变量来判断是否插入成功
        cout << "添加元素成功!" << endl;
        cout << ret.first->first << " ---> " << ret.first->second << endl;
    } else {
        cout << "添加元素失败!" << endl;
        cout << ret.first->first << " ---> " << ret.first->second << endl;
    }
}

void test1()
{
    //map默认情况下按升序方式进行排列
    //
    //不能存放关键字相同的元素
    //
    map<string, string, std::greater<string>> cities{
        pair<string, string>("010", "北京"),
            pair<string, string>("021", "上海"),
            std::make_pair("0755", "深圳"),
            std::make_pair("022", "天津"),
            std::make_pair("0755", "广州")
    };
    display(cities);

    //map支持下标访问运算符, 时间复杂度为 O(logN)
    cout << cities["010"] << endl;

    //如果关键字存在，还可以对value进行修改
    cities["010"] = "南京";
    cout << cities["010"] << endl;
    display(cities);

    //如果对应的关键字不存在，则会直接以该关键字创建一个元素
    cout << cities["027"] << endl;
    display(cities);

    cout << endl;
    //如果对应的关键字不存在，则会直接添加一个新元素
    cities["023"] = "重庆";
    display(cities);

    //查找元素 find/count
    size_t cnt = cities.count("01090");
    if(cnt) {
        cout << "查找成功！" << endl;
    } else {
        cout << "查找失败" << endl;
    }

    cities["027"] = "武汉";

    //pair<map<string, string>::iterator, bool> ret = 
    pair<map<string,string>::iterator,bool> ret = cities.insert(std::make_pair("027", "成都"));
    if(ret.second) {
        cout << "添加元素成功!" << endl;
        cout << ret.first->first << " ---> " << ret.first->second << endl;
    } else {
        cout << "添加元素失败!" << endl;
        cout << ret.first->first << " ---> " << ret.first->second << endl;
    }
}

int main(void)
{
    //test0();
    test1();
    return 0;
}
