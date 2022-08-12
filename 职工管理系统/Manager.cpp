#include "Manager.h"

Manager::Manager(int id, string name, int did)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DepId = did;
}

Manager::~Manager()
{

}

void Manager::showInfo()
{
    cout << "职工编号： " << this->m_Id
        << "\t职工姓名： " << this->m_Name
        << "\t岗位： " << this->getDepName()
        << "\t岗位职责： 给员工分配任务" << endl;
}

string Manager::getDepName()
{
    return "经理";
}
