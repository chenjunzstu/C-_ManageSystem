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
    
    //显示个人信息
    virtual void showInfo();
    
    //获取岗位名称
    virtual string getDepName();
};

