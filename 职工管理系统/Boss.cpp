#include "Boss.h"

Boss::Boss(int id, string name, int did)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DepId = did;
}

Boss::~Boss()
{
}

void Boss::showInfo()
{
    cout << "职工编号： " << this->m_Id
        << "\t职工姓名： " << this->m_Name
        << "\t岗位： " << this->getDepName()
        << "\t岗位职责： 躺着赚钱" << endl;
}

string Boss::getDepName()
{
    return "老板";
}
