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
    cout << "ְ����ţ� " << this->m_Id
        << "\tְ�������� " << this->m_Name
        << "\t��λ�� " << this->getDepName()
        << "\t��λְ�� ��Ա����������" << endl;
}

string Manager::getDepName()
{
    return "����";
}
