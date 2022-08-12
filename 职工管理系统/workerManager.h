#pragma once
#include<iostream>
#include"woker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
#include<fstream>
using namespace std;

#define FILENAME "empfile.txt"
class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();
	//展示菜单
	void Show_Menu();
	//退出系统
	void ExitSystem();
	//添加职工
	void Add_Emp();
	//保存文件
	void save();
	//统计人数
	int get_EmpNum();
	//初始化员工
	void initEmp();
public:
	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker** m_EmpArray;
	//判断文件是否为空的标志
	bool m_FileIsEmpty;
private:

};
