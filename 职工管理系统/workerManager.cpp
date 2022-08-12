#include"workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//�ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;

		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ���û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;

		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ�� " << num << endl;
	this->m_EmpNum = num;
	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ������ݴ浽������
	this->initEmp();

}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray!=NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

void WorkerManager::Show_Menu()
{
	cout << "******************************************" << endl;
	cout << "**********  ��ӭʹ��ְ������ϵͳ�� ***********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "���������ְ������" << endl;

	int addNum;
	cin >> addNum;

	if (addNum > 0)
	{
		//�¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ���ռ������ݿ������¿ռ䰡��
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "������� " << i + 1 << " ����ְ����ţ� " << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ����ְ�������� " << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ�� " << endl;
			cout << "1����ְͨ��\t2������\t3���ϰ�" << endl;
			cin >> dSelect;

			Worker* woker = NULL;
			switch (dSelect)
			{
			case 1:
				woker = new Employee(id,name,dSelect);
				break;
			case 2:
				woker = new Manager(id, name, dSelect);
				break;
			case 3:
				woker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}

			//��������ְ��ָ�뱣�浽������
			newSpace[this->m_EmpNum+i] = woker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		//�����µ�ְ������
		this->m_EmpNum = newSize;
		//����ְ����Ϊ�յı�־
		this->m_FileIsEmpty = false;
		cout << "�ɹ����" << addNum << "����ְ��" << endl;

		//��������
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//д�ļ�
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " " << this->m_EmpArray[i]->m_Name << " " << this->m_EmpArray[i]->m_DepId << endl;
	}
	//�ر��ļ�
	ofs.close();
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	int id;
	string name;
	int did;

	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>did)
	{
		num++;
	}
	return num;
}

void WorkerManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index=0;

	while (ifs>>id&&ifs>>name&&ifs>>did)
	{
		Worker* worker = NULL;

		if (did==1)
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}

	ifs.close();
}
