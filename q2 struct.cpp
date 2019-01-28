// q2 struct.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream>
#include "githubuser2.h"
using namespace std;



void readDataFromFile( gitHubUser * users, string filepath) 
{
	ifstream fileread;
	fileread.open("githubuser2.txt");
	int x;
	fileread >> x;
	users = new githubuser2 [x];
	for(int i=0; i< x; i++)
	{
		fileread >> users[i].firstName;
		fileread >> users[i].username;
		
		fileread>>users[i].email;
		fileread>>users[i].foldercount;
	}
}