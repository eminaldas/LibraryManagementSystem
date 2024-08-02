#include <iostream>
#include <string>
#include<windows.h>    
#include <conio.h>
#include <cstring>
using namespace std;

#include "UserLogin.h"
#include "Book.h"
#include "MainMenu.h"
#include "Manager.h"
#include "Member.h"
#include "DB.h"
int main() {
	
	
	User user;
	user.veriatama();
	user.loginDisplayPage();
	
	
}