#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::multimap;
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
	//multimap默认情况下按升序方式进行排列
	//
	//能存放关键字相同的元素
	//
	multimap<string, string> cities{
		pair<string, string>("010", "北京"),
		pair<string, string>("021", "上海"),
		std::make_pair("0755", "深圳"),
		std::make_pair("022", "天津"),
		std::make_pair("0755", "广州")
	};
	display(cities);

	//multimap不支持下标访问运算符, 时间复杂度为 O(logN)
	//cout << cities["010"] << endl;
    
	//查找元素 find/count
	size_t cnt = cities.count("010");
	if(cnt) {
		cout << "查找成功！" << endl;
	} else {
		cout << "查找失败" << endl;
	}
	
	//pair<multimap<string, string>::iterator, bool> ret = 
	auto ret = cities.insert(std::make_pair("027", "成都"));
	cout << ret->first << " ---> " << ret->second << endl;
}
 
void test1()
{
	//multimap默认情况下按升序方式进行排列
	//
	//能存放关键字相同的元素
	//
	multimap<string, string, std::greater<string>> cities{
		pair<string, string>("010", "北京"),
		pair<string, string>("021", "上海"),
		std::make_pair("0755", "深圳"),
		std::make_pair("022", "天津"),
		std::make_pair("0755", "广州")
	};
	display(cities);

	//multimap不支持下标访问运算符, 时间复杂度为 O(logN)
	//cout << cities["010"] << endl;

	//查找元素 find/count
	size_t cnt = cities.count("01090");
	if(cnt) {
		cout << "查找成功！" << endl;
	} else {
		cout << "查找失败" << endl;
	}
	
	auto ret = cities.insert(std::make_pair("027", "成都"));
		cout << ret->first << " ---> " << ret->second << endl;
}

int main(void)
{
	test0();
	//test1();
	return 0;
}
