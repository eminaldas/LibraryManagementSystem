#include <iostream>
#include <string>

using namespace std;

#include "Manager.h"
#include "MainMenu.h"

Manager::Manager() {

}
Manager::Manager(string firstName, string lastName, string userName, int password, long long int userNumber) {
	setFirstName(firstName);
	setLastName(lastName);
	setUsername(userName);
	setPassword(password);
	setUserNumber(userNumber);
	
}
Manager::~Manager() {

}
void Manager::setFirstName(string firstName) {
	this->firstName = firstName;
}
string Manager::getFirstName() const {
	return this->firstName;
}

void Manager::setLastName(string lastName) {
	this->lastName = lastName;
}
string Manager::getLastName()const {
	return this->lastName;
}

void Manager::setUsername(string userName) {
	this->username = userName;
}
string Manager::getUsername()const {
	return username;
}

void Manager::setUserNumber(long int userNumber) {
	this->userNumber = userNumber;
}
long long int Manager::getUserNumber() const {
	return userNumber;
}


void Manager::setPassword(int password) {
	this->password = password;
}
int Manager::getPassword()const {
	return password;
}