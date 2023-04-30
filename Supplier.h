#include <iostream>
#ifdef Product
#include "Product.h"
#endif

using namespace std;

class Supplier
{
protected:
  string SupplierN;
  static int counter;
  Product sproduct;

public:
  void SProductDeliever(int n)
  {
    sproduct.SetQuantity(sproduct.GetQuantity() - n);
  }

  int GetSProductQuantity()
  {
    return sproduct.GetQuantity();
  }

  void SProductDisplayer()
  {
    cout << this->SupplierN << " has " << this->sproduct.GetQuantity() << " number of products ready to be delievered " << endl;
  }

  void SProductInfo()
  {
    int val;
    cout << "Enter the Quantity you want to order \n";
    cin >> val;
    while (val < 0)
    {
      cout<<"Invalid Quantity\n";
      cout << "Enter the Quantity you want to order \n";
      cin >> val;
    }

    sproduct.SetQuantity(sproduct.GetQuantity() + val);
  }

  Supplier()
  {
    this->SupplierN = "Supplier no " + to_string(counter);
    this->counter++;
  }

  Supplier(string s)
  {
    this->SupplierN = s + to_string(counter);
    this->counter++;
  }

  string GetName()
  {
    return this->SupplierN;
  }

  void SetName(string s)
  {
    this->SupplierN = s;
  }
};

int Supplier::counter = 1;