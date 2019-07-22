#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace warcraft
{
class GameConfig
{
public:
    static GameConfig * getinstance()
    {
        if(_pinstance==nullptr)
        {   _pinstance=new GameConfig();    }
        return _pinstance;
    }
    static void distroy()
    {
        if(_pinstance)
        {   delete _pinstance;  }
        cout<<"destroy()"<<endl;
    }

private:
    GameConfig()
    {   cout<<"GameConfig()"<<endl;     }
    ~GameConfig()
    {   cout<<"~GameConfig()"<<endl;    }
private:
    static GameConfig *_pinstance;
};

class GetTime
{
public:
    static GetTime *getinstance()
    {
        if(_pinstance==nullptr)
        {
            _pinstance=new GetTime();
        }
        return _pinstance;
    }
    static void distroy()
    {
        if(_pinstance)
        {
            delete _pinstance;
        }
        cout<<"destroy()"<<endl;
    }

    void showtime()const;
    void updatetime();
    void reset()
    {   _hour=0;_minute=0;  }
private:
    GetTime(size_t minute=0,size_t hour=0)
        :_hour(hour),_minute(minute)
    {   cout<<"GetTime()"<<endl;    }
    ~GetTime()
    {   cout<<"~GetTime()"<<endl;   }
private:
    static GetTime * _pinstance;
    size_t _hour;
    size_t _minute;
};

}//end of namespace warcraft
