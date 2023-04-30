#include <iostream>
using namespace std;

class Data
{
public:
  int NoOfEmp, NoOfProducts,NoOfCustomer;

  Data()
  {
    this->NoOfEmp = 1;
    this->NoOfProducts = 1;
    this->NoOfCustomer=1;
  }

  void Reader()
  {
    cout << "Enter the Number of Employees you want " << endl;
    cin >> this->NoOfEmp;
    cout << "Enter the number of Products you want " << endl;
    cin >> this->NoOfProducts;
    cout << "Enter the number of Customers you want " << endl;
    cin >> this->NoOfCustomer;
  }
};