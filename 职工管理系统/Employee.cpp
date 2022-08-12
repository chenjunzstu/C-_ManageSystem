#include "Employee.h"

Employee::Employee(int id, string name, int did)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DepId = did;
}

Employee::~Employee()
{
}

void Employee::showInfo()
{
    cout <<"职工编号： "<<this->m_Id
         <<"\t职工姓名： "<<this->m_Name
         <<"\t岗位： "<<this->getDepName() 
         <<"\t岗位职责： 完成经理交代的任务"<<endl;
}

string Employee::getDepName()
{
    return "员工";
}
