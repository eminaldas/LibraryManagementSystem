#pragma once
#include "MainMenu.h"
#include "Manager.h"
#include "Member.h"
#include "Book.h"
#include "UserLogin.h"
struct Kitap
{
	string kitapAdi;
	int rafNo;
};
class Display : public book  {
	long long int number;
	string firstName;
	string lastName;
	string username;
	int ID;
public:
	string toLowerCase(const string& str);
	void deger(string isim);
	void displayMember();
	void displayManager();
	void showManagerProfil();
	void showUserprofil();
	void books();
	void askBook();
	void wishBook();
	void returnedbook();
	void loaned();
	void kitapIslem();
};
