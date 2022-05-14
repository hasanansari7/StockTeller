
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;
class customer;
class ADMINISTRATION///done;
{
private:
    char item_name[25];
    char pass[25];
    int item_no;
    double item_price;
    int item_quantity;
    int item_instock;
    //char update[25];
public:
    ADMINISTRATION():pass("ADMIN")
    {

    }
    void menu_for_admin();
    int password(char*);
    void getdata();
    void showdata();
    void write_record();
    void read_record();
    int search_record();
    int menu();
    void update_record();
    void delete_item(char*);
    void exit();

};
int ADMINISTRATION::search_record()///done;
{   int count =0;
    char t[25];
    cin.ignore();
    cout<<"Enetr the name of the item"<<endl;
    gets(t);
    ifstream fin;
    fin.open("stockteller.dat",ios::in|ios::binary);
    if(!fin)
    {
        cout<<"file cannot be opened"<<endl;
    }
    else
    {   cout<<setw(12)<<"ITEM NAME"<<setw(12)<<"ITEM NO"<<setw(12)<<"ITEM PRICE"<<setw(15)<<"ITEM QUANTITY"<<setw(15)<<"ITEM IN STOCK"<<endl;
    cout<<endl;
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(!strcmp(item_name,t))
            {showdata();
            count=1;}
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();

    }
    return count;
}
void ADMINISTRATION:: getdata()///done;
{   char g;
    do{cin.ignore();
    cout<<"Enter the Name of the ITEM"<<endl;
    gets(item_name);
    cout<<"Enter the unique ITEM_NO of "<<item_name<<endl;
    cin>>item_no;
    cout<<"Enter the price of the "<<item_name<<" ITEM"<<endl;
    cin>>item_price;
    cout<<"Enter the Quantity of the "<<item_name<<" ITEM"<<endl;
    cin>>item_quantity;
    cout<<"Enter the current stock of the "<<item_name<<" ITEM"<<endl;
    cin>>item_instock;
    write_record();
    cout<<"Want to add new record????????"<<endl;
    cout<<"Press y or Y for adding and n or N main menu"<<endl;
    cin.ignore();
    cin>>g;}
    while(g=='y'||g=='Y');



}

void ADMINISTRATION::delete_item(char *t)///not done;
{
    ofstream fout;
    ifstream fin;
    fin.open("stockteller.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"File cannot open"<<endl;
    else
    {
    fout.open("tempstockteller.dat",ios::out|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {   if(strcmp(item_name,t))
        {
            fout.write((char*)this,sizeof(*this));
        }
        fin.read((char*)this,sizeof(*this));
    }
        fin.close();
        fout.close();
        remove("stockteller.dat");
        rename("tempstockteller.dat","stockteller.dat");
}}

void ADMINISTRATION:: update_record()///not done;
{
    int count=1;
    char t[20];
    cin.ignore();
    cout<<"Enter the name of the item to be updated"<<endl;
    gets(t);
    ifstream file;
    file.seekg(0);
    file.open("stockteller.dat",ios::in|ios::binary);
    file.read((char*)this,sizeof(*this));

    while(!file.eof())
    {
        if(!(strcmp(item_name,t)))
        {   delete_item(t);
            getdata();
            count=0;
        }
        file.read((char*)this,sizeof(*this));
    }
        if(count==1)
        cout<<"Item Not found"<<endl;
}

void ADMINISTRATION:: write_record()///done;
{
    ofstream fout;
    fout.open("stockteller.dat",ios::app|ios::binary);
    if(!fout)
        cout<<"file cannot be written"<<endl;
    else
    { fout.write((char*)this,sizeof(*this));
        cout<<"Done"<<endl;
        fout.close();
    }
}
void ADMINISTRATION:: read_record()///done;
{
    ifstream fin;
    fin.open("stockteller.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"File cannot be opened"<<endl;
    else
    {   cout<<setw(12)<<"ITEM NAME"<<setw(12)<<"ITEM NO"<<setw(12)<<"ITEM PRICE"<<setw(15)<<"ITEM QUANTITY"<<setw(15)<<"ITEM IN STOCK"<<endl;
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            showdata();
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
}}
void ADMINISTRATION:: showdata()///done;
{
    cout<<setw(10)<<item_name<<setw(10)<<item_no<<setw(10)<<item_price<<setw(15)<<item_quantity<<setw(20)<<item_instock<<endl;
}
int ADMINISTRATION::menu()///done;
{
    int a;
    cout<<"PRESS the Following key for the Respected action:"<<endl;
    cout<<"1:For adding the items"<<endl;
    cout<<"2:for read the items"<<endl;
    cout<<"3:for update the items"<<endl;
    cout<<"4:for search the items"<<endl;
    cout<<"5:Bills of all the customer"<<endl;
    cout<<"6:for exit"<<endl;
    cin>>a;
    return a;
}
void ADMINISTRATION::exit()///done;
{
    cout<<"Thank you have a nice day"<<endl;
}

class customer///done;
{
    int quantity;
    float price;
    int item_no;
    char item_name[25];
    float total;
    char customer_name[25];
    char customer_mobile_no[12];
public:
    void basket();
    void getdata();
    void write_bill();
    void read_bill(int);
    void showdata_bill();
    int delete_items_for_bill(int);
    void print_bill();
    int menu_customer();
    void menu_for_customer();
    void exit();
    int search_items();
    void read_all_customer();
};
void customer::read_all_customer()
{
    ifstream fin;
    fin.open("bill.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"File cannot be opened"<<endl;
    else
    { fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {cout<<"********************************************************************************"<<endl;
        cout<<"customer name :"<<setw(15)<<customer_name<<endl;
        cout<<"customer mobile No: "<<setw(11)<<customer_mobile_no<<endl;///right justify;
        cout<<endl;
        cout<<"********************************************************************************"<<endl;
        cout<<endl;
        cout<<setw(12)<<"item_name"<<setw(12)<<"item_no"<<setw(12)<<"price"<<setw(12)<<"quantity"<<endl;
            showdata_bill();
              cout<<"********************************************************************************"<<endl;
        cout<<"total  "<<total<<endl;

            fin.read((char*)this,sizeof(*this));
        }
        cout<<endl;
        cout<<endl;
        cout<<"*******************************************************************************************"<<endl;
        fin.close();
}}

void customer::read_bill(int c)///done;
{
    ifstream fin;
    fin.open("bill.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"File cannot be opened"<<endl;
    else
    {int m,d,e;
        fin.seekg(0,ios::end);
        d=fin.tellg();
        e=c*(sizeof(customer));
        m=d-e;
        fin.seekg(m,ios::beg);
        fin.read((char*)this,sizeof(*this));
        cout<<endl;
        cout<<"********************************************************************************"<<endl;
        cout<<"customer name :"<<setw(15)<<customer_name<<endl;
        cout<<"customer mobile No: "<<setw(11)<<customer_mobile_no<<endl;///right justify;
        cout<<endl;
        cout<<"********************************************************************************"<<endl;
        cout<<endl;
        cout<<setw(12)<<"item_name"<<setw(12)<<"item_no"<<setw(12)<<"price"<<setw(12)<<"quantity"<<endl;
        while(!fin.eof())
        {
            showdata_bill();
            fin.read((char*)this,sizeof(*this));
        }
        cout<<endl;
        cout<<endl;
        cout<<"********************************************************************************"<<endl;
        cout<<"total  "<<total<<endl;
        cout<<"********************************************************************************"<<endl;
        fin.close();
}}

int customer::delete_items_for_bill(int count)
{
    int a=1;
    char t[25];
    ofstream fout;
    ifstream fin;
    fin.open("bill.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"File cannot open"<<endl;
    else
    {
    fout.open("tempbill.dat",ios::out|ios::binary);
    while(a==1)
        {cout<<"Enter the name of the item to be deleted"<<endl;
               cin.ignore();
               gets(t);
               fin.read((char*)this,sizeof(*this));
               while(!fin.eof())
                {   if(strcmp(item_name,t))
                            fout.write((char*)this,sizeof(*this));
                    fin.read((char*)this,sizeof(*this));
               }
         cout<<"Press 1 to delete more and 0 to exit"<<endl;
         cin>>a;
         count--;
        };
        fin.close();
        fout.close();
        remove("bill.dat");
        rename("tempbill.dat","bill.dat");
        return count;
}}
void customer::showdata_bill()
{
    cout<<setw(10)<<item_name<<setw(12)<<item_no<<setw(10)<<price<<setw(8)<<quantity<<endl;
}


int customer::menu_customer()///done;
{
    int d;
    cout<<"Enter the Respected key for the respected action"<<endl;
    cout<<"1:for searching the items"<<endl;
    cout<<"2: for basket"<<endl;
    cout<<"3: exit"<<endl;
    cin>>d;
    return d;
}
void customer::basket()
{
    cout<<"Enter the following details"<<endl;
    getdata();
}

void customer::getdata()
{   char f;
    int count=0;
    total=0;
    int a,c;
    cin.ignore();
    cout<<"Enter the name of the customer"<<endl;
    gets(customer_name);
    cout<<"Enetr the Mobile no of the customer"<<endl;
    cin>>customer_mobile_no;
do{
    cout<<"Enter the Name of the ITEM"<<endl;
    cin.ignore();
    gets(item_name);
    cout<<"Enter the unique ITEM_NO of "<<item_name<<endl;
    cin>>item_no;
    cout<<"Enter the price of the "<<item_name<<" ITEM"<<endl;
    cin>>price;
    cout<<"Enter the Quantity of the "<<item_name<<" ITEM"<<endl;
    cin>>quantity;
    total=total+(float)(quantity*price);
    write_bill();
    count++;
    cout<<"Press -1 to add more and 0 to exit"<<endl;
    cin>>a;}while(a!=0);
      cout<<"The total amount is "<<total<<" rupees"<<endl;
      cout<<"want to rectify the bill"<<endl;
      cout<<"press y or Y for yes and n and N for no"<<endl;
      cin.ignore();
      cin>>f;
      if(f=='y'||f=='Y')
        { c=delete_items_for_bill(count);
          read_bill(c);
        }
    else
    { read_bill(count);}
}
void customer::print_bill()
{
    showdata_bill();
}
void customer::write_bill()///done;
{
    ofstream fout;
    fout.open("bill.dat",ios::app|ios::binary);
    if(!fout)
        cout<<"file cannot be written"<<endl;
    else
    {
    fout.write((char*)this,sizeof(*this));
    cout<<"Done"<<endl;
    fout.close();
}}
void customer::exit()
{
    cout<<"Thank you!!!!!!! Have a nice day"<<endl;
}
void customer::menu_for_customer()///not done;
{
    int a,d;
    customer c;
    ADMINISTRATION A;
    while(a!=-1)
    {
        switch(c.menu_customer())
        {
        case 1:
            d=(A.search_record());
            if(d==0)
            cout<<"items are out of stocked"<<endl;
            cout<<"Thankyou"<<endl;
            break;
        case 2:
            c.basket();
            cout<<"thankyou"<<endl;
            break;
        case 3:
            exit();
            break;
        default:
            cout<<"invalid selection"<<endl;
            break;
        }
        cout<<"press -1 to try again and -2 for menu"<<endl;
        cin>>a;
    }


}

void ADMINISTRATION::menu_for_admin()///done;

{
    ADMINISTRATION A;
    int c;
    while(c!=-1)
{
        switch(A.menu())
        {
        case 1:
            cout<<"Enter the required details"<<endl;
            A.getdata();
            cout<<"Thank you"<<endl;
            break;
        case 2:
            cout<<"The previous records are"<<endl;
            A.read_record();
            cout<<"Thank you"<<endl;
            break;
            case 3:
            cout<<"Provide the following details for the update-ion for the item"<<endl;
            A.update_record();
            cout<<"Thank you"<<endl;
            break;
        case 4:
            int e;
            e=A.search_record();
            if(e==0)
                cout<<"Items not found"<<endl;
            break;
        case 5:
            customer c;
            c.read_all_customer();
            break;
        case 6:
            exit();
            break;
        default:
            cout<<"invalid selection"<<endl;
            cout<<"TRY AGAIN"<<endl;
        }
        cout<<"want to try again"<<endl;
        cout<<"Press -1 to end the program and -2 for menu"<<endl;
        cin>>c;
}}

int ADMINISTRATION::password(char *t)///done
{
    int d;
    d=strcmp(pass,t);
    return d;
}
void printname()
{
    cout<<"Hello SIR\n";
}
int main()///done;
//for password type ADMIN
{   int s;
int a;
char t[25];
    ADMINISTRATION A;
    printname();
    customer c;
    while(a!=-1)
    {
    cout<<"Enter 1 for ADMIN and 2 for CUSTOMER"<<endl;
    cin>>s;
    if(s==1)
    {
        cout<<"Enter the password for the admin"<<endl;
        cin.ignore();
        gets(t);
        int f;
        f=A.password(t);
        if(!f)
             A.menu_for_admin();
        else
            cout<<"WRong Password"<<endl;
    }
    if(s==2)
    c.menu_for_customer();
    cout<<"Thank you :"<<endl;

    cout<<"Press -1 to shutdown the program and any key for working"<<endl;
    cin>>a;
    }
}
