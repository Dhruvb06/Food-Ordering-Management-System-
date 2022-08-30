#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<cstdio>
#include<stdlib.h>


using namespace std;
struct r{
    char food[50];
    int key;
    float price;
}r;
class FoodOrder
{
public:
    void create();
    void query();
    void display();
    void update();
    void delet();
    void admin();
};
void FoodOrder::create()
{
    char a;
    int k;
    fstream obj;
    display();
    top:
    do {
        obj.open("customer.txt",ios::in|ios::binary);
        cout<<"\n\n\tADD ITEMS TO THE LIST...";
        cout<<"\n\t===========================";
        cout<<"\n\n\n\tEnter The Serial No. Key:";
        cin>>k;
         while(obj.read((char*)&r,sizeof(r)))
            {
                if(r.key==k)
                {
                    cout<<"\n\tSerial No. Key Is Already Exist"<<endl;
                    obj.close();
                goto top;
                }
            }
        obj.close();
        obj.open("customer.txt",ios::app|ios::binary);
        r.key=k;
        cin.ignore();
        cout<<"\n\tENTER THE FOOD ITEM NAME:";
        gets(r.food);
        cout<<"\n\tENTER THE FOOD ITEM PRICE:";
        cin>>r.price;
        obj.write((char*)&r,sizeof(r));
        cout<<"\n\tDo You Want To Add Another Item [y/n] :";
        cin>>a;
        obj.close();
    }
    while(a!='n');
    system("PAUSE");
    system("CLS");
}
void FoodOrder::display()
{
      int c=0;
     fstream obj;
     obj.open("customer.txt",ios::in|ios::binary);
     cout<<"\n\t=====================FOOD MENU==========================";
    cout<<"\n\n\tSERIAL NO. KEY\t\tFOOD NAME\t\t\tPRICE"<<endl;
    while(obj.read((char*)&r,sizeof(r)))
    {
            cout<<"\n\t"<<r.key<<"\t\t\t"<<r.food<<"\t\t\t\t"<<r.price<<endl;
            c++;
    }
    if(c==0)
    {
        cout<<"\n\tList Is Empty"<<endl;
    }
    obj.close();
    
}
void FoodOrder::query()
{
     int a,c=0;
     fstream obj;
     obj.open("customer.txt",ios::in);
     cout<<"\n\n\tQUERY ABOUT THE FOOD ITEMS...";
     cout<<"\n\t===================================";
    cout<<"\n\n\n\tEnter The Serial No. Key :";
    cin>>a;
    while(obj.read((char*)&r,sizeof(r)))
    {
           if(r.key==a)
           {
            cout<<"\n\n\t"<<r.key<<"\t\t"<<r.food<<"\t\t\t"<<r.price<<endl;
            c++;
           }
    }
    if(c==0)
    {
        cout<<"\n\tNot Found"<<endl;
    }
    obj.close();
    system("PAUSE");
    system("CLS");
}
void FoodOrder::update()
{
     int a,p,c=0;
     fstream obj;
     display();
     obj.open("customer.txt",ios::in|ios::out|ios::binary);
     cout<<"\n\n\tUPDATE THE FOOD ITEMS LIST...";
     cout<<"\n\t=================================";
    cout<<"\n\n\n\tEnter The Serial No. Key:";
    cin>>a;
    obj.seekg(0);
    while(obj.read((char*)&r,sizeof(r)))
    {
        if(r.key==a)
        {
            cout<<"\n\tDestination Record :"<<endl;
            cout<<"\n\t"<<r.key<<"\t\t"<<r.food<<"\t\t\t"<<r.price<<endl;
            p=obj.tellg()-(sizeof(r));
            obj.seekp(p);
            cout<<"\n\tEnter The Serial No. Key :";
            cin>>r.key;
            cin.ignore();
            cout<<"\n\tENTER THE FOOD ITEM NAME :";
             gets(r.food);
            cout<<"\n\tENTER THE FOOD ITEM PRICE :";
            cin>>r.price;
            obj.write((char*)&r,sizeof(r));
            c++;
           }

        }
        if(c==0)
        {
            cout<<"\n\tNot Found"<<endl;
        }

    obj.close();
    system("PAUSE");
    system("CLS");
}
void FoodOrder::delet()
{
     int a,c;
     fstream obj,obj1;
     display();
     obj.open("customer.txt",ios::in|ios::binary);
     obj1.open("temp.txt",ios::app|ios::binary);
     cout<<"\n\n\tDELETE THE FOOD ITEM IN THE LIST...";
     cout<<"\n\t======================================";
    cout<<"\n\n\n\tEnter The Serial No. Key :";
    cin>>a;
    while(obj.read((char*)&r,sizeof(r)))
    {
        if(r.key==a)
        {
            c++;
            cout<<"\n\t"<<r.key<<"\t\t"<<r.food<<"\t\t\t"<<r.price<<endl;
            cout<<"\n\tDestination Record Is Deleted"<<endl;
        }
        if(r.key!=a)
        {
            obj1.write((char*)&r,sizeof(r));
           }
    }
    obj.close();
    obj1.close();
    if(c==0)
       {
         cout<<"\n\tNot Found"<<endl;
       }
    remove("customer.txt");
    rename("temp.txt","customer.txt");
    system("PAUSE");
    system("CLS");
}
 void FoodOrder::admin()
{
char a;
    do{

            cout<<"\n\n\n\t\t\t\t\t\t=========================================================================="<<endl;
             cout<<"\n\t\t\t\t\t\t  =========== WELCOME TO FOOD ORDERING MANAGEMENT SYSTEM =========="<< endl;
            cout<<"\t\t\t\t\t\t|                                                                          |"<<endl;
            cout<<"\t\t\t\t\t\t|    1) ADD FOOD ITEM                                                      |"<<endl;
            cout<<"\t\t\t\t\t\t|    2) DISPLAY FOOD ITEMS                                                 |"<<endl;
            cout<<"\t\t\t\t\t\t|    3) QUERY ABOUT FOOD ITEMS                                             |"<<endl;
            cout<<"\t\t\t\t\t\t|    4) UPDATE FOOD ITEMS                                                  |"<<endl;
            cout<<"\t\t\t\t\t\t|    5) DELETE FOOD ITEMS                                                  |"<<endl;
            cout<<"\t\t\t\t\t\t|    0) EXIT TO MAIN MENU                                                  |"<<endl;
            cout<<"\t\t\t\t\t\t|                                                                          |"<<endl;
            cout<<"\t\t\t\t\t\t============================================================================"<<endl;
            cout<<"\n\n\t\t\t\t\t\tSELECT THE CHOICES(0-5) GIVEN ABOVE :";
            cin>>a;
            switch(a)
            {
            case '0':
            	system("CLS");
                break;
            case '1':
                system("CLS");
               create();
                break;
            case '2':
                system("CLS");
               display();
                break;
            case '3':
                system("CLS");
               query();
                break;
            case '4':
                system("CLS");
               update();
                break;
            case '5':
                system("CLS");
             delet();
                break;
            }
    }
    while(a!='0');
}

struct {
char d[50];
float p,amount;
int qty;
char name[50];
}rd;
class customer:public FoodOrder
{
public:
    void bill();
    void showbill();
    void food_menu();
};
void customer::bill()
{
	 int max=99,max1=9999;
     int a,c=0;	
     char ch;
     char b[50];
     float total=0;
    fstream obj,obj1;
    food_menu();
     obj.open("customer.txt",ios::in|ios::binary);
    rd.name;
    cout<<"\n\tEnter Customer Name : ";
    cin>>rd.name;
      obj.write((char*)&r,sizeof(r));
	  obj.close();	 
    obj1.open("bill.txt",ios::out|ios::binary);
     do{
    obj.open("customer.txt",ios::in|ios::binary);
    cout<<"\n\tEnter The Item Number You Want to Order : ";
    cin>>a;

    while(obj.read((char*)&r,sizeof(r)))
    {
           if(r.key==a)
           {
            c++;
            cout<<"\n\tEnter The Quantity : ";
            cin>>rd.qty;
            rd.amount=rd.qty*r.price;
            cout<<"\n\t"<<r.food<<"\t\t"<<r.price<<"*"<<rd.qty<<"\t\t"<<rd.amount<<endl;
            strcpy(rd.d,r.food);
            rd.p=r.price;
            obj1.write((char*)&rd,sizeof(rd));
            total=total+rd.amount;
           }
        }
        if(c==0)
     {
        cout<<"\n\tNot Found"<<endl;
     }

    cout<<"\n\tDo You Want To Order More [y/n] : ";
    cin>>ch;
    
    obj.close();
     }
     while(ch!='n');
     cout<<"\n\t\t\t\tTHANK YOU FOR YOUR ORDER :) GENERATING BILL......... ";
   	              
                  	cout<<"\n\n\t\t\t\t\t";
                 	system("PAUSE");
    obj1.close();
    system("CLS");
    
                                    cout<< "\n\t\t\t\t\t\t =============================================================="<<endl;
			   	                    cout<< "\t\t\t\t\t\t |                 FOOD ORDERING MANAGEMENT SYSTEM           |"<<endl;
			   	                    cout<< "\t\t\t\t\t\t ============================================================="<<endl;
			   	                    cout<< endl;
			   	                    cout<< endl;
			   	                    
			   	                    cout<< "\t\t\t\t\t\t   BILL No. : "<<rand()%max;              cout<<"\t\t\tORDER No. : "<<rand()%max<<endl;
			   	                    cout<< endl;
			   	                    cout<< endl;
			   	                    cout<< "\t\t\t\t\t\t   Cashier  : Dhruv Bansal"<<endl;
			   	                    cout<< "\t\t\t\t\t\t   Customer : "<<rd.name<<endl;
			   	                    cout<< endl;
			   	                    cout<<"\t\t\t\t\t\t";                                    showbill();
			   	                    cout<< "\n\t\t\t\t\t\t     YOUR TOTAL BILL IS Rs."<<total<<endl;
			   	                    cout<< "\t\t\t\t\t\t ================================================================"<<endl;
	 cout<<"\n\n\n\t\t\t\t\t\tTHANK YOU FOR VISITING US :) HAVE A NICE DAY......... ";		   	                    
	cout<<"\n\n\t\t\t\t\t\t";		   	                    
    system("PAUSE");
    system("CLS");
}
 void customer::showbill(){
    fstream obj;
    obj.open("bill.txt",ios::in|ios::binary);
    cout<<"FOOD ITEM NAME\t\tPRICE\t\tQTY\t\tAMOUNT"<<endl;
    while(obj.read((char*)&rd,sizeof(rd)))
    {

            cout<<"\t\t\t\t\t\t"<<rd.d<<"\t\t\t"<<rd.p<<"\t\t"<<rd.qty<<"\t\t"<<rd.amount<<endl;


    }
    obj.close();
 }
 void customer::food_menu()
 {
      fstream obj;
     obj.open("customer.txt",ios::in|ios::binary);
     cout<<"\n\n\n\t\t\t\t\t\t\t============ START YOUR ORDER ============="<<endl;
    while(obj.read((char*)&r,sizeof(r)))
    {
            
            cout<<"\n\t\t\t\t\t\t\t"<<r.key<<") "<<r.food<<"\t-------RS  "<<r.price<<endl;
    }
    obj.close();
 }
 
 class login
 {
 	public:
 		void security()
 		{
		 
           string userName;
           string userPassword;
           int loginAttempt = 0;

    while (loginAttempt < 5)
    {
    	cout<<"\n\n\n\n\t\t\t\t\tWelcome To Food Ordering Management System!!";
    	cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t---------------------------";
        cout << "\n\t\t\t\t\t\tPlease enter your user name: ";
        cin >> userName;
        cout<<"\t\t\t\t\t\t---------------------------";
        cout<<"\n\n\t\t\t\t\t\t---------------------------";
        cout << "\n\t\t\t\t\t\tPlease enter your password: ";
        cin >> userPassword;
        cout<<"\t\t\t\t\t\t---------------------------";

        if (userName == "dhruv" && userPassword == "bansal")
        {
            cout <<"\n\n\t\t\t\t\t\tWelcome Dhruv Bansal!.\n\n\n";
            cout<<"\n\n\t\t\t\t\t\t";
            system("PAUSE");
            system("CLS");
            break;
        }
        else
        {
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
            cout << "Too many login attempts! The program will now terminate.";
            return;
    }	
    
 }
};

int main()
{
	login ob;
	ob.security();
    char a;
    customer obj;
    do
    {
        cout<<"\n\n\n\n\t\t\t\t\t\t\t===================================================================="<<endl;
         cout<<"\t\t\t\t\t\t\t  =========== WELCOME TO FOOD ORDERING MANAGEMENT SYSTEM ========="<< endl;
        cout<<"\t\t\t\t\t\t\t|                                                                  |"<<endl;
        cout<<"\t\t\t\t\t\t\t|                   1) ADMIN                                       |"<<endl;
        cout<<"\t\t\t\t\t\t\t|                   2) CUSTOMER                                    |"<<endl;
        cout<<"\t\t\t\t\t\t\t|                   0) EXIT                                        |"<<endl;
        cout<<"\t\t\t\t\t\t\t|                                                                  |"<<endl; 
        cout<<"\t\t\t\t\t\t\t===================================================================="<<endl;
        cout<<"\n\n\t\t\t\t\t\t\tSELECT FROM THE CHOICES(0-2) GIVEN ABOVE :";
        cin>>a;
        switch(a)
        {
        case '0':
            break;
        case '1':
             system("CLS");
            obj.admin();
            break;
        case '2':
             system("CLS");
            obj.bill();
            break;
        }
    }
    while(a!='0');

}

