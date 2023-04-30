/*
    Tayyab_Kamran_22i2505
*/

#include <iostream>
#include <windows.h>
#include "Data.h"
#include "Employee.h"
#include "Product.h"
#include "Supplier.h"
#include "Inventory.h"

using namespace std;

struct Discounts
{
  string Couponcode = "TAYYAB100";
  int StudentDiscount = 20;
  int RamadanDiscount = 50;
  int PromotionalDsicount = 30;
  int VolumeDsicount = 30;
  int VolumeDsicountQ = 100;
};

void Validator(int &a)
{
  if (a < 0 || a > 100)
  {
    while (a < 0 || a > 100)
    {
      cout << "Enter value again\n";
      cin >> a;
    }
  }
}

//? To validate the amount of Products
bool AmmountValidator(int n, Supplier obj)
{
  if (n < 0 || n > obj.GetSProductQuantity())
  {
    cout << "Invalid Number \n";
    return false;
  }
  return true;
}

//? To check if products ordered are valid
bool AmmountValidator(int n, Data *obj)
{
  if (n < 1 || n > obj->NoOfProducts)
  {
    cout << "Invalid Number \n";
    return false;
  }
  return true;
}

bool ValidatorBasic(int n)
{
  if (n < 0)
  {
    return false;
  }
  return true;
}
//? To check if the relevant supplier is called
bool ProductSync(int n1, int n2)
{
  if (n1 != n2)
  {
    cout << "This Supplier dont supply the following product" << endl;
    return false;
  }
  return true;
}

class Manager
{
private:
  string ManagerN;

public:
  Manager()
  {
    ManagerN = "";
  }

  Manager(string s)
  {
    this->ManagerN = s;
  }
};

class ManagementSystem
{
private:
  Data *MyData;
  Discounts MyDiscount;
  string MyName;
  Inventory *MyInventory;
  Employee *MyEmployee;
  Manager *MyManager;
  Supplier *Suppliers;
  Customer *MyCustomer;
  int Option, Role, Number, Number2, Number3;

public:
  ManagementSystem()
  {
    this->MyName = "";
  }

  //? To update the value of Coupon code
  void CCUpdater()
  {
    string s;
    cout << "Enter the new Coupon code you want to set " << endl;
    cin.ignore();
    getline(cin, s);
    MyDiscount.Couponcode = s;
    cout << "Updated Successfully\n";
  }

  //? To update the value of Student Discount
  void SDUpdater()
  {
    int a;
    cout << "Enter the new Student Discount you want to set " << endl;
    cin >> a;
    Validator(a);
    MyDiscount.StudentDiscount = a;
    cout << "Updated Successfully\n";
  }

  //? To update the value of Ramadan Discount
  void RDUpdater()
  {
    int a;
    cout << "Enter the new Ramadan Discount you want to set " << endl;
    cin >> a;
    Validator(a);
    MyDiscount.RamadanDiscount = a;
    cout << "Updated Successfully\n";
  }

  //? To update the value of Promotional Discount
  void PDUpdater()
  {
    int a;
    cout << "Enter the new Promotional Discount you want to set " << endl;
    cin >> a;
    Validator(a);
    MyDiscount.PromotionalDsicount = a;
    cout << "Updated Successfully\n";
  }

  //? To update the value of Volume Discount
  void VDUpdater()
  {
    int a, b;
    cout << "Enter the new Volume Discount you want to set " << endl;
    cin >> a;
    Validator(a);
    MyDiscount.VolumeDsicount = a;
    cout << "Enter the new quantity on which Volume Discount will be enabled" << endl;
    cin >> b;
    while (b < 0)
    {
      cout << "Enter a Positive Number \n";
      cout << "Enter the new quantity on which Volume Discount will be enabled" << endl;
      cin >> b;
    }
    MyDiscount.VolumeDsicountQ = b;
    cout << "Updated Successfully\n";
  }

  //? To update the quantity of Product of the supplier
  void GiveOrder(int n)
  {
    Suppliers[n].SProductInfo();
    cout << "Product Order placed to " << Suppliers[n].GetName() << " successfully\n";
  }

  //? To Display all the suppliers of the Management System
  void SupplierDisplayer()
  {
    cout << "The Suppliers are " << endl;
    for (int i = 0; i < MyData->NoOfProducts; i++)
    {
      cout << i + 1 << ": " << Suppliers[i].GetName() << endl;
    }
  }

  //? To Display the Customers of the Management System
  void CustomerDisplayer()
  {
    cout << "You have following Customers in this Management System " << endl;
    for (int i = 0; i < MyData->NoOfCustomer; i++)
    {
      cout << i + 1 << ": " << MyCustomer[i].GetName() << endl;
    }
  }

  // ? Module 1 F2
  void ProductTake()
  {
    for (int i = 0; i < MyData->NoOfProducts; i++)
    {
      cout << i + 1 << ". ";
      Suppliers[i].SProductDisplayer();
    }
    cout << "\nEnter the Number of Supplier you want to take the product from\n";
    cin >> this->Number;

    while (!AmmountValidator(this->Number, MyData))
    {
      cout << "\nEnter the Number of Supplier you want to take the product from\n";
      cin >> this->Number;
    }

    cout << "Enter the amount of product you want to take \n";
    cin >> this->Number2;

    while (!AmmountValidator(this->Number2, Suppliers[this->Number - 1]))
    {
      cout << "Enter the amount of product you want to take \n";
      cin >> this->Number2;
    }

    Suppliers[this->Number - 1].SProductDeliever(this->Number2);

    MyInventory->ProductPackage(this->Number - 1, this->Number2);
  }

  // ? Module 1 F1
  void ProductOrder()
  {
    MyInventory->ProductDisplayer();
    this->SupplierDisplayer();

    cout << "Enter the Product Number you want to Order " << endl;
    cin >> this->Number;

    while (!AmmountValidator(this->Number, MyData) && this->Number < 1)
    {
      cout << "Enter the Product Number you want to Order " << endl;
      cin >> this->Number;
    }

    cout << "Enter the Supplier from which you want to Order " << endl;
    cin >> this->Number2;

    while (!AmmountValidator(this->Number2, MyData) && this->Number2 < 1)
    {

      cout << "Enter the Supplier from which you want to Order " << endl;
      cin >> this->Number2;
    }

    while (!ProductSync(this->Number, this->Number2))
    {
      cout << "Enter the Product Number you want to Order " << endl;
      cin >> this->Number;
      cout << "Enter the Supplier from which you want to Order " << endl;
      cin >> this->Number2;
    }

    if (MyInventory->ProductVerifier(this->Number - 1))
    {
      this->GiveOrder(this->Number - 1);
    }
  }

  //? Discount Apply Functions

  void Dcouponcode()
  {
    string s;
    cout << "Enter the Coupon code you have\n";
    cin.ignore();
    getline(cin, s);
    if (s == MyDiscount.Couponcode)
    {
      cout << "Coupon activated successfully\n";
      cout << "You got 50% Discont on all products" << endl;
      MyInventory->DiscountMaker(50);
    }
    else
    {
      cout << "Invalid Coupon\n";
    }
  }

  void StudentDiscount()
  {
    MyInventory->DiscountMaker(MyDiscount.StudentDiscount);
    cout << "Student Discount of " << MyDiscount.StudentDiscount << " % applied successfully\n";
  }

  void RamadanDiscount()
  {
    MyInventory->DiscountMaker(MyDiscount.RamadanDiscount);
    cout << "Ramadan Discount of " << MyDiscount.RamadanDiscount << " % applied successfully\n";
  }

  void PromotionalDiscount()
  {
    MyInventory->DiscountMaker(MyDiscount.PromotionalDsicount);
    cout << "Promotional Discount of " << MyDiscount.PromotionalDsicount << " % applied successfully\n";
  }

  void VolumeDiscount()
  {
    MyInventory->DiscountMaker(MyDiscount.VolumeDsicount);
    cout << "Congrats Volume Discount of " << MyDiscount.VolumeDsicount << " % applied successfully\n";
  }

  void DcouponcodeMaker()
  {
    cout << "What you want to do " << endl;
    cout << "1. View Coupon Code\n";
    cout << "2. Update Coupon Code\n";
    cin >> this->Number;
    switch (this->Number)
    {
    case 1:
      cout << "Your Coupon code is " << MyDiscount.Couponcode << endl;
      break;
    case 2:
      this->CCUpdater();
      break;
    default:
      break;
    }
  }

  void StudentDiscountMaker()
  {
    cout << "What you want to do " << endl;
    cout << "1. View Student Discount\n";
    cout << "2. Update Student Discount\n";
    cin >> this->Number;
    switch (this->Number)
    {
    case 1:
      cout << "Discount for Students is " << MyDiscount.StudentDiscount << endl;
      break;
    case 2:
      this->SDUpdater();
      break;
    default:
      cout << "Invalid Option\n";
      break;
    }
  }

  void RamadanDiscountMaker()
  {
    cout << "What you want to do " << endl;
    cout << "1. View Ramadan Discount\n";
    cout << "2. Update Ramadan Discount\n";
    cin >> this->Number;
    switch (this->Number)
    {
    case 1:
      cout << "Discount in the month of Ramadan is " << MyDiscount.RamadanDiscount << endl;
      break;
    case 2:
      this->RDUpdater();
      break;
    default:
      cout << "Invalid Option\n";
      break;
    }
  }

  void PromotionalDiscountMaker()
  {
    cout << "What you want to do " << endl;
    cout << "1. View Promotional Discount\n";
    cout << "2. Update Promotional Discount\n";
    cin >> this->Number;
    switch (this->Number)
    {
    case 1:
      cout << "Promotional Discount is " << MyDiscount.PromotionalDsicount << endl;
      break;
    case 2:
      this->PDUpdater();
      break;
    default:
      cout << "Invalid Option\n";
      break;
    }
  }

  void VolumeDiscountMaker()
  {
    cout << "What you want to do " << endl;
    cout << "1. View Volume Discount\n";
    cout << "2. Update Volume Discount\n";
    cin >> this->Number;
    switch (this->Number)
    {
    case 1:
      cout << "Volume Discount is " << MyDiscount.VolumeDsicount << " on the purchase of " << MyDiscount.VolumeDsicountQ << "or more items" << endl;
      break;
    case 2:
      this->VDUpdater();
      break;
    default:
      cout << "Invalid Option\n";
      break;
    }
  }

  void changePrice()
  {
    MyInventory->ProductDisplayer();
    cout << "Enter the Product Number you want to Update Price" << endl;
    cin >> this->Number;

    while (!AmmountValidator(this->Number, MyData))
    {
      cout << "Enter the Product Number you want to update price" << endl;
      cin >> this->Number;
    }

    MyInventory->PriceUpdator(this->Number - 1);
  }

  // ? Module 1 F3
  void PriceManage()
  {
    cout << "What you want to Manage \n";
    cout << "1. Update Price " << endl;
    cout << "2. Manage Coupon Code " << endl;
    cout << "3. Manage Student Discount" << endl;
    cout << "4. Manage Ramadan Discount" << endl;
    cout << "5. Manage Promotional Discount" << endl;
    cout << "6. Manage Volume Discount" << endl;
    cin >> this->Option;
    switch (this->Option)
    {
    case 1:
      changePrice();
      break;
    case 2:
      DcouponcodeMaker();
      break;
    case 3:
      StudentDiscountMaker();
      break;
    case 4:
      RamadanDiscountMaker();
      break;
    case 5:
      PromotionalDiscountMaker();
      break;
    case 6:
      VolumeDiscountMaker();
      break;
    default:
      cout << "Invalid Option \n";
      break;
    }
  }

  void AddToCart()
  {
    this->CustomerDisplayer();

    cout << "Enter the Number of Customer for which you want to add to cart\n";
    cin >> this->Number;
    while (this->Number > MyData->NoOfCustomer || this->Number < 1)
    {
      cout << "Please Enter the correct number\n";
      cout << "Enter the Number of Customer for which you want to add to cart\n";
      cin >> this->Number;
    }

    MyInventory->ProductDisplayer();
    cout << "Enter the number of the Product you want to buy \n";
    cin >> this->Number2;

    while (!AmmountValidator(this->Number2, MyData))
    {
      cout << "Enter the number of the Product you want to buy \n";
      cin >> this->Number2;
    }
    cout << "Enter  the Quantity of Product you want to add to cart \n";
    cin >> this->Number3;

    while (this->Number3 < 1)
    {
      cout << "Amount of Product cannot be negative or zero\n";
      cout << "Enter  the Quantity of Product you want to add to cart \n";
      cin >> this->Number3;
    }

    while (!MyInventory->ProductVerifier(this->Number2 - 1, this->Number3))
    {
      cout << "Enter  the Quantity of Product you want to add to cart \n";
      cin >> this->Number3;
    }

    if (this->Number3 >= MyDiscount.VolumeDsicountQ)
    {
      this->VolumeDiscount();
    }
    MyCustomer->BuyProduct(MyInventory->GetProduct(this->Number2 - 1), this->Number3);
    MyInventory->ProductSeller(this->Number2 - 1, this->Number3);
  }

  void ApplyDiscount()
  {
    cout << "Which discount you want to apply\n";
    cout << "1. Coupon Code " << endl;
    cout << "2. Student Discount" << endl;
    cout << "3. Ramadan Discount" << endl;
    cout << "4. Promotional Discount" << endl;
    cin >> this->Option;
    switch (this->Option)
    {
    case 1:
      Dcouponcode();
      break;
    case 2:
      StudentDiscount();
      break;
    case 3:
      RamadanDiscount();
      break;
    case 4:
      PromotionalDiscount();
      break;
    default:
      cout << "Invalid Option \n";
      break;
    }
  }

  void IssueRefund()
  {
    this->CustomerDisplayer();
    cout << "Enter the Customer you want to Issue Refunds\n";
    cin >> this->Option;
    while (this->Option > MyData->NoOfCustomer && this->Option < 1)
    {
      cout << "Incorrect\n";
      cout << "Enter the Customer you want to Issue Refunds\n";
      cin >> this->Option;
    }
    if (!MyCustomer[this->Option - 1].ShowBucket())
    {
      return;
    }
    cout << "Enter the Number of Product you want to issue refund " << endl;
    cin >> this->Number2;
    cout << "Enter the Quantity of Product you want to refund \n";
    cin >> this->Number3;
    while (this->Number3 < 1)
    {
      cout << "Enter again value cannot be negative or zero\n";
    }
    while (!MyCustomer[this->Option - 1].Validator(this->Number2 - 1, this->Number3))
    {
      cout << "Enter the Quantity of Product you want to refund \n";
      cin >> this->Number3;
    }

    Product temp = MyCustomer[this->Option - 1].Refunder(this->Number2 - 1, this->Number3);
    MyInventory->RefundReceiever(temp, Number3);
  }

  void SRByProduct()
  {
    MyInventory->ProductDisplayer();

    cout << "Enter the number of Product you want to see the Report\n";

    cin >> this->Number;
    while (!AmmountValidator(this->Number, MyData))
    {
      cout << "Enter the number of Product you want to see the Report\n";

      cin >> this->Number;
    }

    MyInventory->ProductReportViewer(this->Number - 1);
  }

  void SRBYDay()
  {
    if (MyInventory->GetTotalSell() > 0)
    {
      cout << "The total number of  products sold today are " << MyInventory->GetTotalSell() << endl;
    }
    else
    {
      cout << "No Sales made today uptil now\n";
    }
  }

  void SRBYCustomer()
  {
    this->CustomerDisplayer();
    cout << "Enter the number of the Customer you want to see the Report\n";
    cin >> this->Number2;

    while (this->Number2 > MyData->NoOfCustomer || this->Number2 < 1)
    {
      cout << "Invalid Number\n";
      cout << "Enter the number of the Customer you want to see the Report\n";
      cin >> this->Number2;
    }
    if (MyCustomer[this->Number2 - 1].getTbuy() > 0)
    {
      cout << "This Cutomer has bought a total of " << MyCustomer[this->Number2 - 1].getTbuy() << " products\n";
    }
    else
    {
      cout << "This Customer has no record of sales yet\n";
    }
  }

  void IRBYProduct()
  {
    MyInventory->ProductDisplayer();
    cout << "Enter the Number of Product you want to see the Report\n";
    cin >> this->Number2;

    while (!AmmountValidator(this->Number2, MyData))
    {
      cout << "Enter the number of Product you want to see the Report\n";

      cin >> this->Number2;
    }

    if (MyInventory->GetProductQuantity(this->Number2 - 1) > 0)
    {
      cout << "This Product is stocked in the Inventory in the quantity of " << MyInventory->GetProductQuantity(this->Number2 - 1) << endl;
    }
    else
    {
      cout << "This Product is not Availiable in the Inventory\n";
    }
  }

  void IRBYLocation()
  {
    MyInventory->ProductDisplayer();
    cout << "Enter the Number of Product you want to see the Location\n";
    cin >> this->Number2;

    while (!AmmountValidator(this->Number2, MyData))
    {
      cout << "Enter the Number of Product you want to see the Location\n";

      cin >> this->Number2;
    }

    if (MyInventory->GetProductQuantity(this->Number2 - 1) > 0)
    {
      cout << "This Product is stored in the warehouse of " << this->MyName << endl;
    }
    else
    {
      cout << "This Product is not found in this Inventory\n";
    }
  }

  void IRBYSupplier()
  {
    this->SupplierDisplayer();
    cout << "Enter the Number of Supplier you want to see the Report\n";
    cin >> this->Number3;

    while (!AmmountValidator(this->Number3, MyData))
    {
       cout << "Enter the Number of Supplier you want to see the Report\n";

      cin >> this->Number3;
    }
    Suppliers[this->Number3 - 1].SProductDisplayer();
  }

  void PRBYProduct()
  {
    MyInventory->ProductDisplayer();
    cout << "Enter the Number of Product you want to see the Profit Report\n";
    cin >> this->Number2;

    while (!AmmountValidator(this->Number2, MyData))
    {
      cout << "Enter the Number of Product you want to see the Profit Report\n";

      cin >> this->Number2;
    }
    MyInventory->ProductProfitReportViewer(this->Number2 - 1);
  }

  void PRBYDay()
  {
    MyInventory->ProductDisplayer();
    cout << "Enter the Number of Product you want to see the Profit Report of this Day\n";
    cin >> this->Number2;
    int temp = MyInventory->ProductProfitReportViewer(this->Number2 - 1, -1);
    if (temp > 0)
    {
      cout << "This Product has made a Profit of " << temp * 2 << " on this Day\n";
    }
    else
    {
      cout << "No Profit is made on this day by this Product\n";
    }
  }

  void PRBYCustomer()
  {
    this->CustomerDisplayer();

    cout << "Enter the Number of Customer you want to see the Profit Report\n";
    cin >> this->Number2;

    while (this->Number2 > MyData->NoOfCustomer || this->Number2 < 1)
    {
      cout << "Invalid Number\n";
      cout << "Enter the number of the Customer you want to see the Report\n";
      cin >> this->Number2;
    }

    if (MyCustomer[this->Number2 - 1].getTbuy() > 0)
    {

      cout << "This Customer has helped the System make " << MyCustomer[this->Number2 - 1].getTbuy() * 2 << " Ruppees of Profit\n";
    }
    else
    {
      cout << "This Customer didn't help making any Profit\n";
    }
  }

  void SalesReport()
  {
    cout << "Welcome to Sales Report\n";
    cout << "1. Sales by Product\n";
    cout << "2. Sales by Day\n";
    cout << "3. Sales by Customer\n";
    cin >> this->Option;

    switch (this->Option)
    {
    case 1:
      this->SRByProduct();
      break;
    case 2:
      this->SRBYDay();
      break;
    case 3:
      this->SRBYCustomer();
      break;
    default:
      cout << "Invalid Option\n";
      break;
    }
  }

  void InventoryReport()
  {
    cout << "Welcome to Inventory Report\n";
    cout << "1. Inventory by Product\n";
    cout << "2. Inventory by Location\n";
    cout << "3. Inventory by Supplier\n";

    cin >> this->Option;

    switch (this->Option)
    {
    case 1:
      this->IRBYProduct();
      break;
    case 2:
      this->IRBYLocation();
      break;
    case 3:
      IRBYSupplier();
      break;

    default:
      break;
    }
  }

  void ProfitReport()
  {
    cout << "Welcome to Profile Report\n";
    cout << "1. Profit by Product\n";
    cout << "2. Profit by Day\n";
    cout << "3. Profit by Customer\n";

    cin >> this->Option;

    switch (this->Option)
    {
    case 1:
      this->PRBYProduct();
      break;
    case 2:
      this->PRBYDay();
      break;
    case 3:
      this->PRBYCustomer();
      break;

    default:
      break;
    }
  }

  void InventoryManagementModule()
  {
    cout << "\nWhat you want to perform " << endl;
    cout << "1.Product Ordering " << endl;
    cout << "2.Product Take " << endl;
    cout << "3.Price Management " << endl;
    cin >> this->Option;
    switch (this->Option)
    {
    case 1:
      this->ProductOrder();
      break;
    case 2:
      this->ProductTake();
      break;
    case 3:
      this->PriceManage();
      break;
    default:
      cout << "Invalid Option\n";
    }
  }

  void PointofSaleModule()
  {
    cout << "\nWhat you want to perform " << endl;
    cout << "1.Add to Cart" << endl;
    cout << "2.Apply Discounts" << endl;
    cout << "3.Issue Refunds " << endl;
    cin >> this->Option;
    switch (this->Option)
    {
    case 1:
      this->AddToCart();
      break;
    case 2:
      this->ApplyDiscount();
      break;
    case 3:
      this->IssueRefund();
      break;
    default:
      cout << "Invalid Option\n";
    }
  }

  void ReportingModule()
  {
    cout << "\nWhat you want to perform " << endl;
    cout << "1.Sales Report" << endl;
    cout << "2.Inventory Report " << endl;
    cout << "3.Profit Report " << endl;
    cin >> this->Option;
    switch (this->Option)
    {
    case 1:
      this->SalesReport();
      break;
    case 2:
      this->InventoryReport();
      break;
    case 3:
      this->ProfitReport();
      break;
    default:
      cout << "Invalid Option\n";
    }
  }

  void ModuleSelector()
  {
    cout << "\nEnter the Module you want to use " << endl;
    cout << "1.Inventory Management Module " << endl;
    cout << "2.Point of Sale Module " << endl;
    cout << "3.Reporting Module " << endl;
    cout << "4.Exit " << endl;
    cin >> this->Option;

    switch (this->Option)
    {
    case 1:
      this->InventoryManagementModule();
      break;
    case 2:
      this->PointofSaleModule();
      break;
    case 3:
      this->ReportingModule();
      break;
    case 4:
      cout << "Program exit successfully \n";
      exit(0);

    default:
      cout << "Invalid Option " << endl;
      break;
    }
  }

  void RoleSelector()
  {
    cout << "Select your Role " << endl;
    cout << "Press 1 to continue as Manager " << endl;
    cout << "Press 2 to continue as Employee " << endl;
    cout << "Press 3 to Exit " << endl;
    cin >> this->Role;

    switch (this->Role)
    {
    case 1:
      cout << "Role Selected as Manager \n"
           << endl;
      break;
    case 2:
      cout << "Role Selected as an \nEmployee" << endl;
      break;
    case 3:
      cout << "Program exited successfully";
      exit(0);
    default:
      cout << "Invalid Option" << endl;
      exit(0);
      break;
    }
  }

  void MenuDisplayer()
  {
    cout << "\nWelcome to the CashNCarry Management System " << endl;
    cout << "Lets setup your System" << endl;
    cout << "1.Default Settings(1 Employee , 1 Customer ,1 Product )" << endl;
    cout << "2.Custom Settings" << endl;
    cin >> this->Option;

    switch (this->Option)
    {
    case 1:
      if (this->Option == 1)
      {
        MyData = new Data;
        MyEmployee = new Employee[MyData->NoOfEmp];
        MyInventory = new Inventory(MyData->NoOfProducts);
        this->MyName = "Default System";
        Suppliers = new Supplier[MyData->NoOfProducts];
        MyManager = new Manager;
        MyCustomer = new Customer[MyData->NoOfCustomer];
        MyCustomer->CustomerBasketAllocator(MyData->NoOfProducts);
      }
      break;

    case 2:
      MyData = new Data;
      MyData->Reader();
      MyEmployee = new Employee[MyData->NoOfEmp];
      MyInventory = new Inventory(MyData->NoOfProducts);
      this->MyName = "Custom System";
      Suppliers = new Supplier[MyData->NoOfProducts];
      MyCustomer = new Customer[MyData->NoOfCustomer];
      MyManager = new Manager;
      MyCustomer->CustomerBasketAllocator(MyData->NoOfProducts);
      break;

    default:
      cout << "Invalid Option\n";
      exit(0);
    }
  }
};

int main()
{
  ManagementSystem obj;
  obj.MenuDisplayer();
  obj.RoleSelector();
  while (true)
  {
    obj.ModuleSelector();
    system("pause");
    system("cls");
  }
  return 0;
}
