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
    cout << "ְ����ţ� " << this->m_Id
        << "\tְ�������� " << this->m_Name
        << "\t��λ�� " << this->getDepName()
        << "\t��λְ�� ����׬Ǯ" << endl;
}

string Boss::getDepName()
{
    return "�ϰ�";
}
