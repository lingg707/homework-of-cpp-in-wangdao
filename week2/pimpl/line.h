#pragma once

class line
{
    class linepimpl;//line类中不再包含原有的数据成员，其所有的操作由linepimpl类实现

public:
    line(int x1,int y1,int x2,int y2); 
    ~line(); 
    void printline() const;
private:
    linepimpl *_pimpl;
};

