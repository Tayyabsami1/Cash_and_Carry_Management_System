#include <iostream>
#include <string>

using namespace std;

class Product
{
private:
  string ProdcutName;
  int Quantity = 0;
  int Price;
  int RPrice;
  static int count;
  int SoldQ;

public:

  Product()
  {
    this->ProdcutName = "Product no " + to_string(count);
    this->Quantity = 0.0;
    this->Price = 0;
    this->RPrice=0;
    this->SoldQ=0;
    count++;
  }

  Product(string name, int q, int p)
  {
    this->ProdcutName = name + to_string(count);
    this->Quantity = q;
    this->Price = p;
    this->RPrice=p;
    count++;
  }

  int GetPrice()
  {
    return this->Price;
  }

  void SetSoldQ(int a)
  {
    this->SoldQ=a;
  }

  int GetSoldQ()
  {
    return this->SoldQ;
  }

  void SetPrice(int a)
  {
    this->Price = a;
    this->RPrice=a;
  }

  void SetDPrice(int a)
  {
    this->Price=a;
  }

  void RemDiscount()
  {
    this->Price=this->RPrice;
  }

  string GetProductName()
  {
    return this->ProdcutName;
  }

  void SetProductName(string s)
  {
    this->ProdcutName = s;
  }

  int GetQuantity()
  {
    return this->Quantity;
  }

  void SetQuantity(int a)
  {
    this->Quantity = a;
  }
};

int Product::count = 1;