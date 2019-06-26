#include<iostream>   
#include<string>
#include<fstream>   
#include<map>
#include<set> 
#include<cctype>//tolower()函数和ispunct函数  
#include<algorithm> //remove_if函数 
using namespace std;
int main(int argc, char**argv)
{ //map的定义  
    map<string, size_t> word_count;
    fstream in("bible.txt");//定义一个输入流 
    string word;
    set<string> exclude = {"a","the","to","or"};
    while (in >> word) 
    {
        string::iterator it1; //转为小写 
        for (it1 = word.begin(); it1 != word.end(); ++it1)
        {   
            *it1 = tolower(*it1); 
        } //去除标点符号 
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end()); //若在排除词库中，则不统计 
        if (exclude.find(word) != exclude.end()) 
            continue;
        ++word_count[word];
    } //输出统计结果 
    map<string, size_t>::iterator mapi;
    for (mapi = word_count.begin();
         mapi != word_count.end(); ++mapi) 
    {
        cout << mapi->first << " "; 
        cout << mapi->second << " " << endl;
    
    }
    return 0;
}
