#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class page
{
	public:
		int control_panel();
		int registration();
		int login();
		int forgot_password();
		
};
page::control_panel()
{
	cout<<"\n\n\t\t-:Control Panel:-";
	cout<<"\n1)Registration\n\n";
	cout<<"2)login\n\n";
	cout<<"3)Forgot Password\n\n";
	cout<<"4)Exit\n\n";
	
}
page::registration()
{
	system("cls");
	fstream file;
	string username,password;
	cout<<"\t\t\t-:Registration Portal:-\n";
	cout<<"Enter the username";
	cin>>username;
	cout<<"Enter the password";
	cin>>password;
	file.open("logindata.txt",ios::out|ios::app);
	file<<username<<"\t"<<password<<"\n";
	cout<<"Registerd succesfully";
	file.close();
	
}
page::login()
{
	system("cls");
	int check=0;
	fstream file;
	string username,password,user,pass;
	cout<<"\t\t\t-:Login Portal:-\n";
	cout<<"Username : ";
	cin>>username;
	cout<<"Password : ";
	cin>>password;
	file.open("logindata.txt",ios::in);
	if(!file) cout<<"file openning error! ";
	else
	{
		file>>user>>pass;
		while(!file.eof())
		{
			if(user==username)
			{
				check=1;
				if(pass==password)
				{
					cout<<"logined successfully";
				}
				else
				{
					cout<<"wrong password";
				}
			}
			file>>user>>pass;
			
		}	
		if(check==0)
		{
			cout<<"Invalid username";
		}
		file.close();
	}
}
page::forgot_password()
{
	system("cls");
	fstream file;
	int check2=0;
	string username,password,user;
	cout<<"\n\t\t-:Forgot password Protal:-\n";
	cout<<"Username : ";
	cin>>user;
	file.open("logindata.txt",ios::in);
	if(!file) cout<<"file opennig error";
	else
	{
		file>>username>>password;
		while(!file.eof())
		{
			if(user==username)
			{
				check2=1;
				cout<<"Your password is : "<<password;	
			}	
			file>>username>>password;
		}	
		if(check2==0)
		{
			cout<<"Invalid username";
		}
	}	file.close();
}
int main()
{
	page p;
	int choice;
	m:
	p.control_panel();
	cout<<"\nEnter Your Choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			p.registration();
		break;
		case 2:
			p.login();
		break;
		case 3:
			p.forgot_password();
		break;
		case 4:
			exit(0);
		break;
		default:
			cout<<"\nInvalid choice! ";
	}
	goto m;
}