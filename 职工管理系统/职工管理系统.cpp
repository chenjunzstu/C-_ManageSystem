#include<iostream>
#include"workerManager.h"
#include"woker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
using namespace std;

int main()
{
    //���Դ���
    /*Worker* worker = NULL;
    worker = new Manager(1, "hjc", 1);
    worker->showInfo();*/
    //ʵ���������߶���
    WorkerManager wm;
    //�洢�û�ѡ��
    int choice = 0;

    while (1)
    {
        //����չʾ�˵���Ա����
        wm.Show_Menu();
        cout << "����������ѡ��" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0://�˳�ϵͳ
            wm.ExitSystem();
            break;
        case 1://���ְ��
            wm.Add_Emp();
            break;
        case 2://��ʾְ��
            wm.Show_Emp();
            break;
        case 3://ɾ��ְ��
            wm.Del_Emp();
            break;
        case 4://�޸�ְ��
            wm.Mod_Emp();
            break;
        case 5://����ְ��
            wm.FindEmp();
            break;
        case 6://����ְ��
            wm.Sort_Emp();
            break;
        case 7://����ļ�
            wm.clean_File();
            break;
        default:
            system("cls");//����
            break;
        }
    }
    system("pause");

    return 0;
}