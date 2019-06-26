#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct Word       //定义结构体
{
    string word;
    size_t length;
    Word* next;
    int repnum;//repeat number 重复次数
    bool ifdel;//if delete 是否被删除
    Word(string _word, size_t _lendth = 0, Word* _next = NULL, int _repnum = 1, bool _ifdel = false) :
        word(_word), length(_lendth), next(_next), repnum(_repnum), ifdel(_ifdel){}

};
Word *head = NULL, *tail = NULL;
int size = 0;  //链表长度，即单词总个数
int delsum = 0;//delete sum 被删除的总个数

void Push(const string& str, const size_t& len)   //形成链表
{
    if (NULL == head)
    {
        head = tail = new Word(str, len, NULL, 1, false);

    }
    else
    {
        tail->next = new Word(str, len, NULL, 1, false);
        tail = tail->next;
    }
    size++;
}
void Destory()   //delete new
{
    Word* ptr = head;
    while (ptr)
    {
        Word* pt = ptr;
        ptr = ptr->next;
        delete pt;
    }
    head = tail = NULL;
    size = 0;

}
void Readin(string& mystr)   //read in  读入
{
    string temps;
    for (size_t i = 0; i < mystr.length(); i++)
    {
        if (mystr[i] >= 'a'&&mystr[i] <= 'z' || mystr[i] >= 'A'&&mystr[i] <= 'Z')
        {
            temps += mystr[i];
        }
        else
        {
            if (!temps.empty())//不空的时候返回0
            {

                Push(temps, temps.length());
                temps.erase(temps.begin(), temps.end());
            }
        }
    }
}
void DeSame()      //delete the same 删除相同的单词（不是真删，只是做标记）
{
    Word* p = head;
    while (p&&p->next)
    {
        while (p->ifdel&&p->next)
        {
            p = p->next;
        }
        Word* pt = p->next;
        while (pt)
        {
            if (!pt->ifdel&&pt->word == p->word)
            {
                p->repnum++;
                pt->ifdel = true;
                delsum++;
            }
            pt = pt->next;
        }
        p = p->next;
    }
}

void Inputp(Word* warr[])   //input point 将未被“删除”的结点的指针传入数组
{
    int i = 0;
    Word* pt = head;
    while (pt)
    {
        if (!pt->ifdel)
        {
            warr[i] = pt;
            i++;
        }
        pt = pt->next;
    }
}

void Sort(Word** warr, int start, int end)   //将指针按其指向的结点的repnum从大到小排序，快排实现
{
    int i = 0, j = 0;
    Word* key = NULL;
    key = warr[start];
    i = start;
    j = end;
    while (i<j)
    {
        while (warr[j]->repnum <= key->repnum&&i<j)j--;
        warr[i] = warr[j];
        while (warr[i]->repnum >= key->repnum&&i<j)i++;
        warr[j] = warr[i];

    }
    warr[i] = key;
    if (i - 1>start)Sort(warr, start, i - 1);
    if (end > i + 1)Sort(warr, i + 1, end);

}

void Show(Word** warr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << warr[i]->word << "  " << warr[i]->repnum << endl;
    }
}

int main()
{
    ifstream readfile("zpc.txt", ios::in);
    if (!readfile){ cout << "程序出现异常，自动退出！" << endl; return 0;  }
    string str, str1;
    while (!readfile.eof())
    {
        getline(readfile, str1);
        str += str1;
        str += ' ';
    }
    readfile.close();
    Readin(str);
    DeSame();
    cout << "单词总个数（不考虑重复）：" << size << endl;
    cout << "除去重复后的单词个数（即重复的单词按1个计）：" << size - delsum << endl;
    Word** wdarr = new Word*[size - delsum];
    Inputp(wdarr);
    Sort(wdarr, 0, size - delsum - 1);
    Show(wdarr, size - delsum);
    delete[]wdarr;
    Destory();
    return 0;

}
