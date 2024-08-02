#pragma once
#include "Manager.h"
#include "Member.h"
#include <vector>
class User {
public:
	void veriatama();
	void loginDisplayPage();
	bool managerLogin();
	bool userLogin();
	bool userNewAccount();
	bool ManagerNewAccount();
	bool userNewPassword();
	bool numberControl(long int number);
	bool passwordControl(int _password);

};
