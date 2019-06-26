#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::vector;
using std::endl;

vector<string> file;//定义一个string类型的以file为name的容器
void test0()//打开文件，以string的形式向容器里面填充
{
    ifstream ifs;
    ifs.open("io.cc");
    if(!ifs.good()) 
    {
        cout<<"ifstream open func failed!"<<endl;
        return ;
    }
    string line;
    while(std::getline(ifs,line))
    {
        //cout<<line<<endl;
        file.push_back(line);//在尾部加入一个数据,这一步不会输出，注释掉对结果无影响
    }
    ifs.close();
}
void test1()//仅显示pos=0的效果
{
    test0();
    ofstream ofs("test.txt",std::ios::out);//打开文件做写操作，会删除原有数据
    if(!ofs)
    {
        cout<<"ofstream error"<<endl;
        return ;
    }
    cout<<"pos= "<<ofs.tellp()<<endl;
    ofs<<"that is new line!"<<endl;
#if 0//表示以下代码不会被编译
    for(auto & line:file)
    {
        ofs<<line<<"\n";
    }
#endif
    ofs.close();
}
void test2()//ate模式针对输入流起作用
{
    ifstream ifs("test.txt",std::ios::ate);//打开文件后立即定位到文件尾
    if(!ifs)
    {
        cout<<"ifstream open error!"<<endl;
        return;
    }
    cout<<"pos= "<<ifs.tellg()<<endl;
    ifs.close();
}
void printstatus(fstream & fs)
{
    ;
}
void test4()
{
    string filename="vector.cc";
    ifstream ifs(filename,std::ios::ate);
    if(!ifs)
    {
        cout<<"ifstream open file"<<filename<<"error"<<endl;
        return ;
    }
    int lenth =ifs.tellg();
    cout<<"lenth="<<lenth<<endl;
    char *buf=new char[lenth+1]();
    ifs.seekg(std::ios::beg);
    ifs.read(buf,lenth);
    string content(buf);
    cout<<"content:-----------"<<endl
        <<content
        <<"--------"<<endl;
    delete []buf;
    ifs.close();
}

int main()
{
    test4();
    return 0;
}
