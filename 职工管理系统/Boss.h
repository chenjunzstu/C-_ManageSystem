#pragma once
#include<iostream>
#include<string>
#include"woker.h"
using namespace std;

class Boss:public Worker
{
public:
    Boss(int id, string name, int did);
    ~Boss();
    //��ʾ������Ϣ
    virtual void showInfo();
    //��ȡ��λ����
    virtual string getDepName();
};

