// struct.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "githubuser.h"
using namespace std;


bool Comparison(gitHubUser p1, gitHubUser p2)
{
	bool same = false;
	if (p1.userName.compare(p2.userName) == 0)
	{
		same = true;
	}
	else
		same = false;
	if (p1.firstName.compare(p2.firstName) == 0)
	{
		same = true;
	}
	else 
		same = false;
	if (p1.password.compare(p2.password) == 0)
	{
		same = true;
	}
	else 
		same = false;
	if (p1.email.compare(p2.email) == 0)
	{
		same = true;
	}
	else
		same = false;

	if(same == true)
	{
		return true;
	}
	else
		return false;

}

bool exists(gitHubUser* arr, int size, string userName)
{
	
	for(int i = size-1; i >= 0;i--)
	{
		if (userName == arr[i].userName )
		{
			
			return true;
		}
	
	}
	return false;
}
void inputFromUser(gitHubUser* user, int size)
{
	bool y;
	for(int i=0; i<4;i++)
	{
		cout<<"Please Enter Your Fisrt name, User"<<"("<<i+1<<"): ";
		cin >> user[i].firstName;
		cout<<endl;
		cout<<"Please Enter User name: ";
		if (i == 0)
		{
			
			cin >> user[i].userName;
		}
		else
		{
			cin>> user[i].userName;
			while(exists(user,i,user[i].userName))
			{
				cout<<"'This UserName already exists, enter another userName'"<<endl;
				cout<<"Enter UserName again: ";

				cin>> user[i].userName;
			}
		}
		cout<<endl;
		cout << "Please Enter Password: ";
		cin >> user[i].password;
		cout << endl;
		cout << "Please Enter Email: ";
		cin >> user[i].email;
		cout<<endl;

	}
}

gitHubUser* searchUser ( gitHubUser* users, int size, string userName) 
{
	for(int i=0; i<4;i++)
	{
		if(userName == users[i].userName)
		{
			return &users[i];
		}
	}
	return nullptr;
}





int main()
{
	int x=4;
	bool compare2accounts = false;  
	string search;
	int n1,n2;
	gitHubUser * p;
	gitHubUser * user;
	user = new gitHubUser[x];
	
	cout<<"Enter the user name you want to search: ";
	cin>> search; 
	
	p = searchUser(user,x,search);
		if(p!=nullptr){
		cout <<"The account is found"<<endl;
		cout<<"Fisrt name: "<<p->firstName<<endl;
		cout<<"User name: "<<p->userName<<endl;
		cout<<"Password: "<<p->password<<endl;
		cout<<"Email: "<<p->email<<endl;
		}
	cout << "Enter which two accounts you want to compare: "<<endl;
	cin >> n1;
	cin >> n2;
	compare2accounts =  Comparison(user[n1], user[n2]);
	cout<<compare2accounts;
	delete [] user;
}