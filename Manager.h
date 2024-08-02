#pragma once
#include "UserLogin.h"
#include "book.h"
#include <iostream>
using namespace std;

class Manager:public book {
public:
	string username;
	string firstName;
	string lastName;
	long long int userNumber;
	int password;

public:
	Manager();
	Manager(string firstName, string lastName, string userName, int password, long long int userNumber);
	~Manager();
	void setFirstName(string firstName);
	string getFirstName() const;

	void setLastName(string lastName);
	string getLastName()const;

	void setUsername(string userName);
	string getUsername()const;

	void setUserNumber(long int userNumber);
	long long int getUserNumber() const;


	void setPassword(int password);
	int getPassword()const;
};
