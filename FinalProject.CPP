#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
int x;
class dish
{
  char name[25];
  char cuisine[15];
  public:
  int qty;
  int code;
  float price;
  void enter()
{
  cout<<"enter the code for dish"<<"\n";
  cin>>code;
  cout<<"enter the name of dish"<<"\n";
  gets(name);
  cout<<"enter the cuisine of dish"<<"\n";
  gets(cuisine);
  cout<<"enter the price of dish"<<"\n";
  cin>>price;
  }

void display()
{

  cout<<"\n"<<" The code for dish"<<"is "<<code;
  cout<<"\n"<<" The name of dish"<<"is ";
  puts(name);
  cout<<"\n"<<" The cuisine of dish"<<"is ";
  puts(cuisine);
  cout<<"\n"<<" The price for dish"<<"is "<<price;
  }
  void modify()
  {
  cout<<"enter code:"<<code<<endl;
  cout<<"name:"<<name<<"\n";
  cout<<"cuisine:"<<cuisine<<"\n";
  cout<<"quantity:"<<qty<<"\n";
  cout<<"price:"<<price<<"\n";
  cout<<"ENTER NEW DETAILS->"<<endl;
  char nm[50],cu[50];
  float pri;
  int co,qn;
	    cout<<"new name :(enter '.'to retain old name)";
	    gets(nm);
	    cout<<"new cuisine :(enter '.'to retain old one)";
	    gets(cu);
	    cout<<"enter new price";
	    cin>>pri;
	    cout<<"new code :(enter '.'to retain old code)";
	    cin>>co;

  if(strcmp(nm,".")!=0)
     strcpy(name,nm);
  if(strcmp(cu,".")!=0)
  strcpy(cuisine,cu);
  if(co!=-1)
  {code=co;}

  }



void bill()
{ int n;
  char date[15],memono[15],gstinno[20];
  cout<<"enter date"<<"\t";
  cin>>date;
  cout<<"\n"<<"enter meno/bill no."<<"\t";
  cin>>memono;
  cout<<"\n"<<"enter GSTIN no."<<"\t";
  cin>>gstinno;
  cout<<"enter dish code you want to purchase.\n\n";
cin>>n;
  cout<<"quantity";
  cin>>qty;
}



void exiit()
{
 exit(0);
}
};
void bill(dish a[])
{
char date[15],memono[15],gstinno[20];
long w=0,v;
cout<<"\n\t\t\t\t"<<"BILL\n";
cout<<"\n\t\t\t\t"<<"MKD Plaza\n\n";
cout<<"Date:"<<date<<"\n";
cout<<"Bill no:"<<memono<<"\n";
cout<<"GST no:"<<gstinno<<"\n";
for(int i=0;i<x;i++)
{ a[i].display();
cout<<a[i].qty;
v=a[i].price*a[i].qty;
w+=v;
}
float  m=w+(w/10);
cout<<"GST: 10%\n";
cout<<"NET AMOUNT: Rs."<<m<<"\n\n";
cout<<"\n\t\t\t\t"<<"!!THANK YOU!!";
}
/*
struct add
{
 int hno;
 char col[30];
 char state[10];
};
struct customerinfo
{
 char name[30];
 char cno[10];
 add a;
};*/

dish d,d1,k[50],de;
void deleete()
  {
ifstream fd;
ofstream ft;
fd.open("plaza.mkd");
ft.open("temp.mkd");
int flag=0;
char con='y';
cout<<"enter code of the the dish to be deleted";
int dcodel;
cin>>dcodel;
while(!fd.eof())
{
fd.read((char*)&de,sizeof(de));
}
if(de.code==dcodel)
{
flag=1;
cout<<"record preparing for delete";
de.display();
cout<<"do you want to delete this code(y/n)";
cin>>con;
if(con=='n')
ft.write((char*)&de,sizeof(de));
}
ft.write((char*)&de,sizeof(de));

if(flag==0)
cout<<"specified code not found";
remove("plaza.mkd");
rename("temp.mkd","plaza.mkd");
cout<<"process complete";
fd.close();
ft.close();
}
void main()
{
 clrscr();
 int ch;
 x=0;int cod,t;
 long pos;char found='f';
 char w;
 do
  {
    cout<<"\n\t\t\t\t"<<"MKD Plaza";
    cout<<"\n\n\t\t\t\t"<<"1. Add dish";
    cout<<"\n\t\t\t\t"<<"2. Display dish";
    cout<<"\n\t\t\t\t"<<"3. Modify dish";
    cout<<"\n\t\t\t\t"<<"4. Delete dish";
    cout<<"\n\t\t\t\t"<<"5. Bill generation";
    cout<<"\n\t\t\t\t"<<"6. Exit";
    cout<<"\n\n"<<"enter your choice";
    cin>>ch;
    switch (ch)
    {
     case 1: d.enter();
		ofstream f;
	     f.open("plaza.mkd",ios::binary|ios::app);
	     f.write((char*)&d,sizeof(d));
	     f.close();
	     break;
     case 2: ifstream f1;
	     f1.open("plaza.mkd",ios::binary);
	     for(int g=0;g<50;g++)
	    {f1.read((char*)&k[g],sizeof(d));
	    if(k[g].code!=0)
	     {k[g].display();}}
	     f1.close();
	     break;

     case 3:	fstream f5;
	     f5.open("plaza.mkd",ios::in||ios::binary);
	     while(!f5.eof())
	     {
	     pos=f5.tellg();
	     f5.read((char*)&d,sizeof(d));
	     if(d.code==cod)
	     {
	     d.modify();
	     f5.seekg(pos) ;
	     f5.write((char*)&d,sizeof(d));
	     found=t;
	     break;
	     }
	     }
	     if(found=='f')
	     cout<<"record not found";
	     break;
     case 4: deleete();
	      break;
     case 5:ifstream f2;
	     f2.open("plaza.mkd",ios::binary);
	     ofstream f3;
	     f3.open("order.mkd",ios::binary);
	     d.bill();
	     while(w=='y'||w=='Y')
	     {

	     while(!f2.eof())
	     {
	      f2.read((char*)&d1,sizeof(d1));

	      if(d.code==d1.code){
	      f3.write((char*)&d1,sizeof(d1));
	      x++;}
	      else {cout<<"Enter valid code";endl;
	      }
	      }cout<<"Wish to enter more?";endl;
	      cin>>w;
	     }
	      f2.close();
	      f3.close();
	      ifstream f4;
	      f4.open("order.mkd",ios::binary);
	      f4.read((char*)&k,sizeof(d));
	      bill(k);


	      break;
     case 6:d.exiit();break;
     default : cout<<"enter a valid choice";
    }
  }while(ch<=4);
  getch();
 }



