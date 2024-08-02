#pragma once
#include "UserLogin.h"
#include "MainMenu.h"

class Member {
private:
	string username;
	string firstName;
	string lastName;
	long long int userNumber;
	int password;
	int userID;

public:
	Member();
	Member(string firstName, string lastName, string userName, int password, long long int userNumber, int userID);
	~Member();
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

	void setUserID(int _userID);
	int getUserID()const;

};

