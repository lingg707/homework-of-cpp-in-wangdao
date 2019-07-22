#pragma once
#include "singleton.h"
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
#include <memory>

using namespace std;

namespace warcraft
{
class warrior;
using warriorptr=shared_ptr<warrior>;

enum color{
    red,blue,notset
};
enum warriortype{
    dragon_type,ninja_type,iceman_type,lion_type,wolf_type
};
//为了获得某种颜色或者武士类型，得到字符串，就相当于aoti，不过这次是整型转字符串
inline string tostring (color c)
{   return (c==red)? string("red"):string ("blue");  }
inline string tostring (warriortype w)
{
    switch(w)
    {
        case dragon_type: return "dragon";
        case ninja_type: return "ninja";
        case iceman_type: return "iceman";
        case lion_type: return "lion";
        case wolf_type: return "wolf";
    }
}

class headquarters;//必须提前声明//必须提前声明.先声明后实现

class warrior
//:public std::enable_shared_from_this<warrior>//这个是文件里面写的，但是我还没看到，就先注释了
{
public:
    warrior(color c,const string name,size_t id,size_t hp,size_t force,warriortype type)
    :_color(c),_name(name),_id(id),_hp(hp),_force(force),_type(type)
    {}
    ~warrior() {}
    
    //武士的技能
    virtual void march();
    virtual void attack(warriorptr warrior);
    virtual void denfense(warriorptr warrior);

    //武士与生命元之间的操作
    void bewinner();
    void berewarded();
    void sentelementstoheadquarters(size_t elements);

    //初始化的函数蔟
    void sethp(size_t hp)
    {   _hp=hp; }
    void setcity(size_t cityid)
    {   _cityid=cityid; }
    void setheadquarters(headquarters * head)
    {   _headquarters=head; }

    //返回数据成员
    color getcolor() const {    return _color;     }
    string getname() {  return _name;   }
    size_t getid()const {   return _id;     }
    size_t gethp() const {  return _hp; }
    size_t getcityid() const {  return _cityid; }
    size_t getelements()const {     return _hp;  }//为什么是这样的
    size_t getearnelements()const {     return _earnelement;    }
    size_t getforces()const {   return _force;  }
    warriortype gettype() const     {   return _type;   }

private://为什么不用private，只用protected
protected:
    color _color;
    string _name;
    size_t _id;//编号
    size_t _hp;//声明值
    size_t _force;//攻击力
    size_t _cityid;//位于某个城市
    size_t _earnelement;//从某个城市获得生命元
    warriortype _type;
    headquarters *_headquarters;
};

class dragon
:public warrior
{
public:
    dragon(color c,size_t id,size_t hp,size_t force,float morale)
      :warrior(c,"dragon",id,hp,force,dragon_type)//继承体系里面，派生类的初始化队列中，要先初始化基类
       ,_morale(morale)
    {}
    virtual float getmorale()const {    return _morale;     }
private:
    float _morale;//这是个啥？？
};

class ninja
:public warrior
{
public:
    ninja(color c,size_t id,size_t hp,size_t force)
        :warrior(c,"ninja",id,hp,force,ninja_type)
    {}
//ninja的属性，挨打了不还手，因此要覆盖
    virtual void denfense(warriorptr warrior)override;//实现覆盖
private:
};

class iceman
:public warrior
{
public:
    iceman(color c,size_t id,size_t hp,size_t force)
        :warrior(c,"iceman",id,hp,force,iceman_type),_steps(0)
    {}
    //iceman每前进两步，在第二步完成的时候生命值会减少9，攻击力会增加20
    //如果生命值减少9之后小于等于0，生命值变成1
    //此语句需要覆盖？？为什么
    virtual void march() override;
private:
    size_t _steps;
};

class lion
:public warrior
{
public:
    lion(color c,size_t id,size_t hp,size_t force,size_t loyalty)
        :warrior(c,"lion",id,hp,force,lion_type),_loyalty(loyalty)
    {}
//声明为虚函数同时还要覆盖？？？
//    virtual size_t getloyalty() const override//这里覆盖出错，因为基类里面未定义此类函数 
    virtual size_t getloyalty() const  
    {   return _loyalty;    }
private:
    size_t _loyalty;
};

class wolf
:public warrior
{
public:
    wolf(color c,size_t id,size_t hp,size_t force)
        :warrior(c,"wolf",id,hp,force,wolf_type),_killtimes(0)
    {}
    //在一个wolf通过主动击杀敌人的次数达到偶数的时候，战斗完成之后，wolf的生命值和
    //攻击力都加倍，如果杀死的敌人是lion，则攻击力和生命值先加倍，之后才吸取
    //lion的生命值。获取总部的生命元奖励，发生在加倍之后。反击杀死敌人不会发生加倍
    
    virtual void attack(warriorptr warrior) override;//这里为什么要覆盖啊？？？
private:
    int _killtimes;//击杀次数
};

class headquarters
{
public:
    headquarters(color c,size_t elements)
        :_color(c),_elements(elements),_earnelement(0),_nextwarriorindex(0)
    {}

    virtual ~headquarters() {}
    
    //创建武士
    warriorptr create();//创建武士
    void addwinner(warriorptr warrior);//添加胜利者
    void reward();//奖励胜利者
    void increaseelements(size_t elements)//统计从城市获取的生命元
    {   _earnelement+=elements;     }
    void setelements(size_t elements){  _elements=elements;     }//设置所剩生命元的数量
    
    template <typename IT>
        void setwarriorcreatingorder(IT beg,IT end)//设置生产武士的顺序
        {
            for(;beg!=end;++beg)
            {
                _warriorcreatingorder.push_back(*beg);
            }
        }

    size_t gitid() const {  return _id; }
    void setid(size_t id) { _id=id;     }
    color getcolor() const {    return _color;  }
    size_t getelements() const {    return _elements;   }
    vector<warriorptr> & getwarriors() {    return _warriors;   }

private:
    //生产各种武士
    warriorptr createinceman(size_t id,size_t hp,size_t force);
    warriorptr createlion(size_t id,size_t hp,size_t force);
    warriorptr createninja(size_t id,size_t hp,size_t force);
    warriorptr createwolf(size_t id,size_t hp,size_t force);
    warriorptr createdragon(size_t id,size_t hp,size_t force);

    void nextwarriortype();

    warriortype getnextwarriortype()
    {   return _warriorcreatingorder[_nextwarriorindex];    }
protected:
    color _color;
    size_t _id;//编号，0代表红色司令部，N+1代表蓝色司令部
    size_t _elements;//当前司令部所剩的生命源
    size_t _earnelement;//一次战斗时刻结束之后，所有武士获得的生命元
    size_t _nextwarriorindex;//下次生产的武士下标
    vector<warriortype> _warriorcreatingorder;//武士的生产顺序

//
//下面的语句看不懂，不知道什么意思
//一次战斗之后，胜利的所有武士
    priority_queue<warriorptr,vector<warriorptr>,warriorcomparator> _winners;
    vector<warriorptr> _warriors;///生产所有的武士
//各种类型的武士的数量
    unordered_map<warriortype ,size_t> _warriortypeamounts;
};

class city
{
public:
    city(size_t id,size_t elements=0)
        :_flag(color::notset),_id(id),_elements(elements),_redwincount(0),_bluewincount(0)
    {}

    void produceelements();
    void attach(warriorptr);
    void detach(warriorptr);
    void startbattle();
    void takenby(warriorptr warrior);

    size_t getid()const {   return _id;     }
    color getflag()const {  return _flag;   }
    size_t getwarrioramount() const {
        return _redwarriors.size()+_bluewarriors.size();
    }
    vector<warriorptr> &getreswarriors()    {   return _redwarriors;    }
    vector<warriorptr> & getbluewarriors()  {   return _bluewarriors;   }

private:
    void battle(warriorptr warrior1,warriorptr warrior2);
    bool ischangingflag(warriorptr warrior);

private:
    color _flag;
    size_t _id;//城市编号
    size_t _elements;
    size_t _redwincount;
    size_t _bluewincount;
    vector<warriorptr> _redwarriors;
    vector<warriorptr> _bluewarriors;
};

}//end of namespace warcraft
