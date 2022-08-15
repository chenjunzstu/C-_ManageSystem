#include"workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;

		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在，且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;

		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在，并且记录数据
	int num = this->get_EmpNum();
	cout << "职工人数为： " << num << endl;
	this->m_EmpNum = num;
	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中数据存到数组中
	this->initEmp();

}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray!=NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]!=NULL)
			{
				delete this->m_EmpArray[i];
			}
		}

		delete[] this->m_EmpArray;
	}
}

void WorkerManager::Show_Menu()
{
	cout << "******************************************" << endl;
	cout << "**********  欢迎使用职工管理系统！ ***********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量" << endl;

	int addNum;
	cin >> addNum;

	if (addNum > 0)
	{
		//新空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原来空间下数据拷贝到新空间啊下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "请输入第 " << i + 1 << " 个新职工编号： " << endl;
			cin >> id;
			while (this->IsExit(id)!=-1)
			{
				cout << "编号已存在，请重新输入" << endl;
				cin >> id;
			}
			cout << "请输入第 " << i + 1 << " 个新职工姓名： " << endl;
			cin >> name;
			cout << "请选择该职工岗位： " << endl;
			cout << "1、普通职工\t2、经理\t3、老板" << endl;
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

			//将创建的职工指针保存到数组中
			newSpace[this->m_EmpNum+i] = woker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更新新的职工人数
		this->m_EmpNum = newSize;
		//更新职工不为空的标志
		this->m_FileIsEmpty = false;
		cout << "成功添加" << addNum << "名新职工" << endl;

		//保存数据
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//写文件
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " " << this->m_EmpArray[i]->m_Name << " " << this->m_EmpArray[i]->m_DepId << endl;
	}
	//关闭文件
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

void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

void WorkerManager::Del_Emp()
{
	int id;
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "请输入您想要删除的职工编号： " << endl;
	cin >> id;
	int index = IsExit(id);
	if (index!=-1)
	{
		if (index != this->m_EmpNum-1)
		{
			for (int i = index; i < this->m_EmpNum; i++)
			{
				//数据前移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
		}

		else
		{
			this->m_EmpNum--;
		}
		//更新数组人员个数
		if (!this->m_EmpNum)
		{
			this->m_FileIsEmpty = true;
		}
		//数据同步更新到文件中
		this->save();
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "该职工不存在！" << endl;
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

int WorkerManager::IsExit(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空！" << endl;
	}
	else
	{
		cout << "请输入要修改的职工编号" << endl;
		int id;
		cin >> id;
		int ret = this->IsExit(id);
		if (ret != -1)
		{
			//查找到编号的职工
			delete this->m_EmpArray[ret];
			int newid;
			string newname;
			int dselect;
			cout << "查到: " << id << "号职工，请输入新职工号: " << endl;
			cin >> newid;
			cout << "请输入新姓名" << endl;
			cin >> newname;
			cout << "请输入新职工岗位： " << endl;
			cout << "1、普通职工\t2、经理\t3、老板" << endl;
			cin >> dselect;

			Worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new Employee(newid, newname, dselect);
				break;
			case 2:
				worker = new Manager(newid, newname, dselect);
				break;
			case 3:
				worker = new Boss(newid, newname, dselect);
				break;
			default:
				break;
			}

			this->m_EmpArray[ret] = worker;

			cout << "修改成功！" << endl;
			this->save();
		}
		else
		{
			cout << "职工不存在" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::FindEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		cout << "请选择你的查找方式： " << endl;
		cout << "1、按职工编号查找\t2、按姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入你要查找的职工编号： " << endl;
			cin >> id;

			int ret = this->IsExit(id);
			if (ret != -1)
			{
				cout << "查找成功！" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查无此人！" << endl;
			}
		}
		if (select == 2)
		{
			string name;
			cout << "请输入你要查找的职工姓名： " << endl;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查无此人！" << endl;
			}
		}
		else
		{
			cout << "输入选项有误！" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1、职工号升序\t2、职工号降序" << endl;
		int select;
		cin >> select;
		//选择排序
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minormax = i;
			for (int j=i+1;j<this->m_EmpNum;j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minormax]->m_Id>this->m_EmpArray[j]->m_Id)
					{
						minormax = j;
					}
				}
				else//降序
				{
					if (this->m_EmpArray[minormax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minormax = j;
					}
				}
			}
			if (i != minormax)
			{
				Worker* tmp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minormax];
				this->m_EmpArray[minormax] = tmp;
			}
		}

		cout << "排序成功" << endl;
		this->save();
		this->Show_Emp();
	}
}

void WorkerManager::clean_File()
{
	cout << "是否确定要清空?" << endl;
	cout << "1、确认\t2、返回" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		//清空文件，trunc方式
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//删除堆区每个职工对象
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}
