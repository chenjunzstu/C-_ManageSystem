#pragma once
#include<iostream>
#include<string>
#include"woker.h"
using namespace std;

class Manager :public Worker
{
public:
    Manager(int id, string name, int did);
    ~Manager();

    //��ʾ������Ϣ
    virtual void showInfo();

    //��ȡ��λ����
    virtual string getDepName();
};

