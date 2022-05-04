/*
GROCERY STORE MANAGEMENT SYSTEM -BY SABARI T 
FUNCTIONALITIES AND INPUT
INVENTORY=>ProductId|ProductName|Quantity|Price-Per-Quantity

SALE=>ProductId|Quantity;ProductId|Quantity

== Bill == 
2 
Product ID - Product Name - Quantity Purchased by Customer - Product Price - Offer-Id - Net 
Price 
Product ID - Product Name - Quantity Purchased by Customer - Product Price - Offer-Id - Net 
Price 
== Total == 
Total Amount 

STOCK=>Product ID
======== 

*/
#include <iostream>
#define max 1000
#define customer 100
using namespace std;
class inventory
{
  public:
  string product_id;
  string product_name;
  int quantity;
  //int total=0;
  int price_per_quantity;
  void update_inventory()
  {
    cout<<"product_id|product_name|quantity|price_per_quantity";
    cout<<"\n";
    cin>>product_id>>product_name>>quantity>>price_per_quantity;
    cout<<"Inventory updated";
    cout<<"\n";
  }
  void stock_change(int quantity1)
  {
      quantity=quantity-quantity1;
  }
  int check_inventory(string id)
  {
     if(product_id==id)
        return 1; 
        return 0;
  }
  int bill_of(string product_id,int quantity)
  {
    int eachtotal,total=0;
    eachtotal=quantity*price_per_quantity;
    cout<<  product_id<<" - "<<product_name  <<" - "<<quantity  <<" - "<<price_per_quantity  <<" - "<<"N/A"     <<" - "<<eachtotal;
    cout<<"\n";
    total+= eachtotal;
    return total;
  }
  void print_stock()
  {
    cout<<product_name<< " - "<<quantity;
    cout<<"\n";
  }
};
int main()
{  
    int run=1;
    int iterator=0;
    inventory products[max];
    int customer_counter=0;
    while(run)
    {
     int choice;
     cout<<"1.INVENTORY"<<endl;
     cout<<"2.SALE"<<endl;
     cout<<"3.STOCK"<<endl;
     cin>>choice;
     switch(choice)
     {
        case 1:
           {
                cout<<"INVENTORY"<<endl;
                products[iterator].update_inventory();
                iterator++;
                break;
           }
        case 2:
           {
               cout<<"SALE"<<endl;
               //cout<<"product_id|quantity";
               string product_id;
               int quantity1;
               int total=0;
               int loop=0;
               do
            {  
               cout<<"product_id|quantity";
               cin>>product_id>>quantity1;
               for(int i=0;i<iterator;i++)
               {
                   // total=0;
               if(products[i].check_inventory(product_id))
               {
                  cout<<"====bill==== "<<endl;
                  total+=products[i].bill_of(product_id,quantity1);
                  cout<<"\n";
                  //////////////////////
                 // cout<<"===total is===\n";
                  //cout<<total<<endl;
                  cout<<"\n";
                  products[i].stock_change(quantity1);
               }
               }
               cout<<"press 1 to add more items and 0 to close bill";
               cin>>loop;
             }while(loop);
              cout<<"===total is===\n";
              cout<<total<<endl;
              total=0;
               break;
           }
        case 3:
           {
               string product_id;
               cout<<"STOCK"<<endl;
               cout<<"enter product id";
               cin>>product_id;
               for(int i=0;i<iterator;i++)
               {
               if(products[i].check_inventory(product_id))
                {
                 products[i].print_stock();
                }
               }
               break;
           }
          default:
          {
              run=0;
          }
     }
    }
    return 0;
}

