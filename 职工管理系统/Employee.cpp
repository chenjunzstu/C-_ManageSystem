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
    cout <<"ְ����ţ� "<<this->m_Id
         <<"\tְ�������� "<<this->m_Name
         <<"\t��λ�� "<<this->getDepName() 
         <<"\t��λְ�� ��ɾ�����������"<<endl;
}

string Employee::getDepName()
{
    return "Ա��";
}
