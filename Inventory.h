#include <iostream>
#ifdef Product
#include "Product.h"
#endif

using namespace std;

class Inventory
{
private:
  Product *Products;
  int TotalSell;
  int NoofProducts;

public:
  int GetTotalSell()
  {
    return this->TotalSell;
  }

  void RefundReceiever(Product obj, int n)
  {
    for (int i = 0; i < NoofProducts; i++)
    {
      if (Products[i].GetProductName() == obj.GetProductName())
      {
        Products[i].SetQuantity(Products[i].GetQuantity() + n);
        Products[i].SetSoldQ(Products[i].GetSoldQ() - n);
        this->TotalSell -= n;
      }
    }
    cout << obj.GetProductName() << " refunded to Inventory successfully \n";
  }

  void ProductSeller(int n, int n2)
  {
    Products[n].SetQuantity(Products[n].GetQuantity() - n2);
    Products[n].SetSoldQ(Products[n].GetSoldQ() + n2);
    this->TotalSell += n2;
  }

  void ProductReportViewer(int n)
  {
    if (Products[n].GetSoldQ() > 100)
    {
      cout << "This Product has an excellent sale and the sale has reached upto " << Products[n].GetSoldQ() << " items\n";
    }

    if (Products[n].GetSoldQ() == 0)
    {
      cout << "This Product has no sales uptil now \n";
    }

    if (Products[n].GetSoldQ() < 100 && Products[n].GetSoldQ() > 0)
    {
      cout << "This Product has a normal sale of " << Products[n].GetSoldQ() << " items\n";
    }
  }

  int ProductProfitReportViewer(int n, int n2 = 2)
  {
    if (n2 > 0)
    {
      if (Products[n].GetSoldQ() > 0)
      {
        cout << "This Product has been sold in total Quantity of " << Products[n].GetSoldQ() << " and made a Profit of " << Products[n].GetSoldQ() * (2) << " Ruppees\n";
      }
      else
      {
        cout << "There is NO  Profit made by this Product\n";
      }
      return 0;
    }
    else
    {

      return Products[n].GetSoldQ();
    }
  }

  Product GetProduct(int n)
  {
    return Products[n];
  }

  void DiscountMaker(int n)
  {
    float f = float(n) / 100.0;
    for (int i = 0; i < this->NoofProducts; i++)
    {
      Products[i].SetDPrice(Products[i].GetPrice() * (f));
    }
  }

  void PriceUpdator(int n)
  {
    int n1;
    cout << "Enter the New price of " << Products[n].GetProductName() << endl;
    cin >> n1;
    while (n1 < 0)
    {
      cout << "Enter a Positive Value\n";
      cout << "Enter the New price of " << Products[n].GetProductName() << endl;
      cin >> n1;
    }
    Products[n].SetPrice(n1);
    cout << "Price of " << Products[n].GetProductName() << " successfully updated\n";
  }

  void ProductPackage(int n1, int n2)
  {
    Products[n1].SetQuantity(Products[n1].GetQuantity() + n2);
    cout << Products[n1].GetProductName() << " delievered successfully to Inventory \n";
  }

  void ProductInfo(int no)
  {
    int val;
    cout << "Enter the Quantity you want to order \n";
    cin >> val;
    while (val < 0)
    {
      cout << "Invalid Quantity\n";
      cout << "Enter the Quantity you want to order \n";
      cin >> val;
    }

    Products[no].SetQuantity(val);
  }

  bool ProductVerifier(int no)
  {
    if (Products[no].GetQuantity() >= 100)
    {
      cout << "You already have enough stock of this product\n";

      return false;
    }
    else
    {
      return true;
    }
  }

  bool ProductVerifier(int no, int n2)
  {
    if (Products[no].GetQuantity() < n2)
    {
      cout << "Sorry we don't have enough product\n";

      return false;
    }
    else
    {
      return true;
    }
  }

  void ProductDisplayer()
  {
    cout << "Products in the Inventory are " << endl;
    for (int i = 0; i < this->NoofProducts; i++)
    {
      cout << i + 1 << ": " << Products[i].GetProductName() << " Price: " << Products[i].GetPrice() << " Quantity: " << Products[i].GetQuantity() << endl;
    }
  }

  Inventory()
  {
    this->NoofProducts = 0;
    this->TotalSell = 0;
  }

  Inventory(int n1)
  {
    this->NoofProducts = n1;
    Products = new Product[n1];
    this->TotalSell = 0;
  }

  int GetNoofProducts()
  {
    return this->NoofProducts;
  }

  int GetProductQuantity(int n)
  {
    return Products[n].GetQuantity();
  }
};

class Customer
{
  string name;
  int Limit;
  Product *customerproduct;
  static int count;
  int count2;
  int TBuy;

public:
  Product Refunder(int n1, int n2)
  {
    customerproduct[n1].SetQuantity(customerproduct[n1].GetQuantity() - n2);
    this->TBuy -= n2;
    count2--;

    return customerproduct[n1];
  }

  bool Validator(int n1, int n2)
  {
    if (customerproduct[n1].GetQuantity() < n2 || customerproduct[n1].GetQuantity() < 0)
    {
      cout << "Invalid Number\n";
      return false;
    }
    else
    {

      return true;
    }
  }

  Customer()
  {
    this->name = "Customer no " + to_string(count);
    this->count++;
    count2 = 0;
    this->TBuy = 0;
  }

  bool ShowBucket()
  {
    if (count2 == 0)
    {
      cout << "The Customer Basket is Eympty \n";
      return false;
    }

    else
    {
      cout << "Products in the Customer's Basket are " << endl;

      for (int i = 0; i < count2; i++)
      {
        cout << i + 1 << ": " << customerproduct[i].GetProductName() << " Price: " << customerproduct[i].GetPrice() << " Quantity: " << customerproduct[i].GetQuantity() << endl;
      }
    }
    return true;
  }

  void BuyProduct(Product obj, int n)
  {
    if (count2 > this->Limit - 1)
    {
      cout << "Sorry,this Customer basket is full\n";
      return;
    }
    customerproduct[count2].SetQuantity(n);
    customerproduct[count2].SetPrice(obj.GetPrice());
    customerproduct[count2].SetProductName(obj.GetProductName());
    count2++;
    cout << obj.GetProductName() << " added to cart of " << this->name << " successfully\n";
    this->TBuy += n;
  }

  Customer(string s)
  {
    this->name = s + to_string(count);
    this->count++;
    this->TBuy = 0;
  }

  void SetName(string s)
  {
    this->name = s;
  }

  string GetName()
  {
    return this->name;
  }

  int getcount()
  {
    return this->count2;
  }

  int getTbuy()
  {
    return this->TBuy;
  }

  void CustomerBasketAllocator(int n)
  {
    this->Limit = n;
    customerproduct = new Product[n];
  }
};

int Customer::count = 1;
