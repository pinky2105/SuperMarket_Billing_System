#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		
		public:
			void menu();
			void administrator();
			void buyer();
			void add();
			void edit();
			void rem();
			void list();
			void receipt();
			
};

void shopping :: menu()
{
	m:
	int choice;
	string email;
	string password;
	
	cout<<"\n\n\n___________________________________________________\n";
	cout<<"                                                   \n";
	cout<<"              Supermarket Main Menu                \n";
	cout<<"                                                   \n";
	cout<<"___________________________________________________\n";
	cout<<"                                                   \n";
	cout<<"\t\t|  1) Administrator   |  \n";
	cout<<"\t\t|                     |  \n";
	cout<<"\t\t|  2) Buyer           |  \n";
	cout<<"\t\t|                     |  \n";
	cout<<"\t\t|  3) Exit            |  \n";
	cout<<"\t\t|                     |  \n"; 
	cout<<"\n Please select! : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\n\n ___________________________________________________\n";
			cout<<"|                                                   |\n";
			cout<<"|               Please Login                        |\n";
			cout<<"|___________________________________________________|\n";
			cout<<"\n\n\t      Enter Email : ";
			cin>>email;
			cout<<"\n\n\t      Password : ";
			cin>>password;
			
			if(email=="123"&&password=="123")
			{
				administrator();
			}
			else
			{
				cout<<"Invalid email/password \n";
			}
			break;

	
		case 2:
			{
				buyer();
				
			}
			
		case 3:
			{
				exit(0);
			}
			
			default:
				{
					cout<<"Please select form the given option";
				}
		
	
	
}
goto m;
}

void shopping:: administrator()
{
	m:
		int choice;	
		cout<<"\n\n\t\t\t   Administrator Menu ";
		cout<<"\n\n\t\t|__________1) Add The Product_________|";
		cout<<"\n\n\t\t|_____________________________________|";
		cout<<"\n\n\t\t|__________2) Modify The Product______|";
		cout<<"\n\n\t\t|_____________________________________|";
		cout<<"\n\n\t\t|__________3) Delete The Product______|";
		cout<<"\n\n\t\t|_____________________________________|";
		cout<<"\n\n\t\t|__________4) Back to main Menu_______|";
		
		cout<<"\n\n\t Please Enter Your Choice :  ";
		cin>>choice;
		
		
		switch(choice)
		{
			case 1:
				add();
				break;
				
			case 2:
				edit();
				break;
			
			case 3:
				rem();
				break;
				
			case 4:
				menu();
				break;
				
			default :
				cout<<"Invalid choice!";
		}
		goto m;
		
}

void shopping:: buyer()
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t\t Buyer";
	cout<<"\n\n\t\t|__________1) Buy Product_____________|";
	cout<<"\n\n\t\t|                                     |";
	cout<<"\n\n\t\t|_____________________________________|";
	cout<<"\n\n\t\t|                                     |";
	cout<<"\n\n\t\t|__________2) Go Back_________________|";
	cout<<"\n\n\t\t|                                     |";
	cout<<"\n\n\t\t|_____________________________________|";
	
	cout<<"\n\n\t\t\t Enter Your Choice : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
			
		case 2:
			menu();
			break;
			
		default :
			cout<<"Invalid choice";
	}
	goto m;
}

void shopping::add()
{
	m:
	fstream data;
	int c;
	int token = 0;
	float p;
	float d;
	string n;
	cout<<"\n\n\t\t_____________________________________";
	cout<<"\n\n\n\t\t\t Add new Product";
	cout<<"\n\n\t\t_____________________________________";
	cout<<"\n\n\t Product code of the Product : ";
	cin>>pcode;
	cout<<"\n\n\t Name Of Product : ";
	cin>>pname;
	cout<<"\n\n\t Price Of Product : ";
	cin>>price;
	cout<<"\n\n\t Distcount on Product : ";
	cin>>dis;
	
	data.open("database.txt,ios::in");
	
	if(data)
	{
		data.open("database.txt",ios::app|ios::out);
		data<<"		"<<pcode<<"		"<<pname<<"		"<<price<<"		"<<dis<<"\n";
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;
		
		while(!data.eof())
		{
			if(c == pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	}
		if(token == 1)
		goto m;
		else 
		{
			data.open("database.txt",ios::app|ios::out);
			data<<"		"<<pcode<<"		"<<pname<<"		"<<price<<"		"<<dis<<"\n";
			data.close();
		}
			cout<<"\n\n\t\t Record Inserted ! ";
}

void shopping :: edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t\t Modifiy The Record ";
	cout<<"\n\n\t\t\t Product Code ";
	cin>>pkey;
	
	data.open("database,txt",ios::in);
	if(!data)
	{
		cout<<"\n\n File Doesn't exist ! ";
	}
	else
	{
		data.open("database.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t Product New Code : ";
				cin>>c;
				cout<<"\n\t\t Name of the Product : ";
				cin>>n;
				cout<<"\n\t\t Price : ";
				cin>>p;
				cout<<"\n\t\t Discount : ";
				cin>>d;
				
				data<<"		"<<c<<"		"<<n<<"		"<<p<<"		"<<"\n";
				cout<<"\n\n\t\t Record Edited";
				token++;
			}
			else
			{
				data1<<"		"<<pcode<<"		"<<pname<<"		"<<price<<"		"<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found Sorry!";
		}
	}
}

void shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token = 0;
	cout<<"\n\n\t Delete Product";
	cout<<"\n\n\t Product code : ";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"File does't exist";
	}
	else
	{
		data1.open("database.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t Product deleted succesfully";
				token++;
			}
			else
			{
				data<<"		"<<pcode<<"		"<<pname<<"		"<<price<<"		"<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found Sorry!";
		}
	}
	
}

void shopping:: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n\t\t_____________________________________";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n\t\t_____________________________________";
	data>>pcode>>pname>>price>>dis;
	
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}

void shopping:: receipt()
{
	
	fstream data;
	char choice;
	int arrc[100];
	int arrq[100];
	int c=0;
	float amount =0 ;
	float dis =0;
	float total=0;
	
	cout<<"\n\n\t\t\t\t RECEIPT ";
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n Empty database";
	}
	else
	{
		data.close();
		list();
		cout<<"\n\n\t\t_____________________________________";
		cout<<"\n\n\t\t|                                     |";
		cout<<"\n\n\t\t|       Please Place the Order        |";
		cout<<"\n\n\t\t|                                     |";
		cout<<"\n\n\t\t|_____________________________________|";
		do
		{
			m:
			cout<<"\n\nEnter Product code : ";
			cin>>arrc[c];
			cout<<"\n\nEnter the Product quantity : ";
			cin>>arrq[c];
			
			for(int i =0;i<c;i++)
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"\n\n Duplicate Product Code. Please try again ";
					goto m;
				}
			}
			c++;
			cout<<"\n\n Do you want to buy another product? if yes then press y else no then press n";
			cin>>choice;
		}
		while(choice == 'y');
		
		cout<<"\n\n\t\t|________________RECIPTE__________________|";
		cout<<"\nProduct No\t Product Name\t Product Quantity\t Price\t Amount\t Amount with Discount\n";
		
		for(int i=0;i<c;i++)
		{
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>dis;
			while(!data.eof())
			{
				if(pcode==arrc[i])
				{
					amount==price*arrq[i];
					dis=amount-(amount*dis/100);
					total=total+dis;
					cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
				}
				data>>pcode>>pname>>price>>dis;
			}
		}
		data.close();
	}
	cout<<"\n\n\t\t_____________________________________";
	cout<<"\n Total Amount : "<<total;
	
}

int main()
{
	shopping s;
	s.menu();
}



