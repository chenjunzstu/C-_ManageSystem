#pragma once
#include<iostream>
#include<string>
#include"woker.h"
using namespace std;

class Employee:public Worker
{
public:
    Employee(int id,string name,int did);
    ~Employee();
    
    //��ʾ������Ϣ
    virtual void showInfo();
    
    //��ȡ��λ����
    virtual string getDepName();
};

