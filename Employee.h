#include <iostream>

using namespace std;

class Employee
{
protected:
  string EmployeeN;
  int EmployeeId;

public:
  Employee()
  {
    this->EmployeeId = 0;
    this->EmployeeN = "";
  }

  Employee(string n, int id)
  {
    this->EmployeeId = id;
    this->EmployeeN = n;
  }

  string GetName()
  {
    return this->EmployeeN;
  }

  void SetName(string s)
  {
    this->EmployeeN = s;
  }

  int GetId()
  {
    return this->EmployeeId;
  }

  void SetId(int a)
  {
    this->EmployeeId = a;
  }
};