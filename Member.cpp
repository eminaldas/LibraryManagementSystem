#include <iostream>
#include <string>

using namespace std;

#include "Member.h"
#include "MainMenu.h"

Member::Member() {
		
}
Member::Member(string firstName, string lastName, string userName, int password, long long int userNumber, int userID) {
	setFirstName(firstName);
	setLastName(lastName);
	setUsername(userName);
	setPassword(password);
	setUserNumber(userNumber);
	setUserID(userID);
}
Member::~Member() {

}
void Member::setFirstName(string firstName) {
	this->firstName = firstName;
}
string Member::getFirstName() const {
	return this->firstName;
}

void Member::setLastName(string lastName) {
	this->lastName = lastName;
}
string Member::getLastName()const {
	return this->lastName;
}

void Member::setUsername(string userName) {
	this->username = userName;
}
string Member::getUsername()const {
	return username;
}

void Member::setUserNumber(long int userNumber) {
	this->userNumber = userNumber;
}
long long int Member::getUserNumber() const {
	return userNumber;
}


void Member::setPassword(int password) {
	this->password = password;
}
int Member::getPassword()const {
	return password;
}

void Member::setUserID(int _userID) {
	this->userID = _userID;
}
int Member::getUserID()const {
	return userID;
}