#include<iostream>
#include"workerManager.h"
#include"woker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
using namespace std;

int main()
{
    //测试代码
    /*Worker* worker = NULL;
    worker = new Manager(1, "hjc", 1);
    worker->showInfo();*/
    //实例化管理者对象
    WorkerManager wm;
    //存储用户选项
    int choice = 0;

    while (1)
    {
        //调用展示菜单成员函数
        wm.Show_Menu();
        cout << "请输入您的选项" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0://退出系统
            wm.ExitSystem();
            break;
        case 1://添加职工
            wm.Add_Emp();
            break;
        case 2://显示职工
            wm.Show_Emp();
            break;
        case 3://删除职工
            wm.Del_Emp();
            break;
        case 4://修改职工
            wm.Mod_Emp();
            break;
        case 5://查找职工
            wm.FindEmp();
            break;
        case 6://排序职工
            wm.Sort_Emp();
            break;
        case 7://清空文件
            wm.clean_File();
            break;
        default:
            system("cls");//清屏
            break;
        }
    }
    system("pause");

    return 0;
}