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
	//չʾ�˵�
	void Show_Menu();
	//�˳�ϵͳ
	void ExitSystem();
	//���ְ��
	void Add_Emp();
	//�����ļ�
	void save();
	//ͳ������
	int get_EmpNum();
	//��ʼ��Ա��
	void initEmp();
public:
	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ��
	Worker** m_EmpArray;
	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;
private:

};
