#include <iostream>
#include <string>
#include<windows.h>           
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

#include "UserLogin.h"
#include "MainMenu.h"
#include "Member.h"
vector<Member> vmember;
vector<Manager> vmanager;
Display display;
Manager* manage;
Member* member;
void User::veriatama() {
	ifstream dosyaOku("userlogin.txt");
	string satir;
	int i = 0, a = 0, y = 0;
	string depo[60];
	long long int userNumber;
	int password;
	int userID;


	if (dosyaOku.is_open()) {
		while (!dosyaOku.eof()) {
			dosyaOku >> depo[i];
			i++;
		}
	}
	while (a < 30) {
		stringstream ss(depo[a + 3]);
		ss >> password;
		stringstream aa(depo[a + 4]);
		aa >> userNumber;
		stringstream xx(depo[a + 5]);
		xx >> userID;
		vmember.push_back(Member(depo[a], depo[a + 1], depo[a + 2], password, userNumber, userID));
		a = a + 6;
		y++;
	}
	dosyaOku.close();


	ifstream dosya("managerlogin.txt");
	int m = 0, n = 0, z = 0;
	string mdepo[60];
	long long int muserNumber;
	int mpassword;


	if (dosya.is_open()) {
		while (!dosya.eof()) {
			dosya >> mdepo[m];
			m++;
		}
	}
	while (n < 30) {
		stringstream mm(mdepo[n + 3]);
		mm >> mpassword;
		stringstream nn(mdepo[n + 4]);
		nn >> muserNumber;

		vmanager.push_back(Manager(mdepo[n], mdepo[n + 1], mdepo[n + 2], mpassword, muserNumber));
		n = n + 5;
		z++;
	}
	dosya.close();
}


void  User::loginDisplayPage() {
	while (true) {

		char tercih;
		bool result = false;
		system("cls");
		cout << "\n\t\t*                     KUTUPHANE GIRIS EKRANI                   *" << endl;
		cout << "\t\t==================================================================" << endl;
		cout << "\t\t[1] - Yonetici Giris      ||   [2] - uye Giris"<<endl;
		cout << "\t\t------------------------------------------------------------------" << endl;
		cout << "\t\t[3] - Uye yeni hesap kur  ||   [4] - Yonetici yeni hesap kur"<<endl;
		cout << "\t\t------------------------------------------------------------------" << endl;
		cout << "\t\t[5] - Exit " << endl;
		cout << "\t\t==================================================================" << endl;
		cout << "\t\ttercih : ";
		cin >> tercih;
		switch (tercih) {
		case '1':
			result = false;
			result = managerLogin();
			if (result) {
				display.displayManager();
			}
			break;
		case '2':
			result = false;
			result = userLogin();
			if (result) {
				display.displayMember();
			}
			break;
		case '3':
			result = false;
			result = userNewAccount();

			if (result) {
				display.displayMember();
			}
			break;
		case '4':
			result = false;
			result = ManagerNewAccount();

			if (result) {
				display.displayManager();
			}
			break;
		case '5':
			cout << "\t\tExciting";
			for (int i = 0; i <= 4; i++)
			{
				Sleep(500);
				cout << ".";
			}
			exit(0);
			break;
		default:
			cout << "\n\n\t\thatali secim";
			Sleep(500);
			break;
		}
	}
}




bool User::managerLogin() {

	system("cls");
	int pass = 0, hak = 5, sifredegis = 0, password = 0;
	string userName;

	cout << "\n\t\t*               MANAGER LOG-IN              *" << endl<<endl;
label_login:
	cout << "\t\t===================================================" << endl;
	cout << "\t\tUsername : ";
	cin >> userName;
	cout << "\t\t---------------------------------------------------" << endl;
label_password:
	cout << "\t\tPassword : ";
	cin >> password;
	cout << "\t\t===================================================" << endl;
	hak--;
	for (int i = 0; i < vmanager.size(); i++) {
		if (userName == vmanager[i].getUsername()) {
			if (password == vmanager[i].getPassword()) {
				cout << endl << "\t\tbasarili giris " << endl;
				Sleep(500);
				cout << endl << "\n\t\tlogining ";
				for (int i = 0; i <= 4; i++)
				{
					Sleep(500);
					cout << ".";
				}
				display.deger(userName);
				return true;
			}
			else {
				cout << "\t\tparola yanlis tekrar deneyiniz!.." << endl;
				Sleep(500);
				if (hak == 0) {
					cout << "\t\tcok fazla giris yapildi ana menuye yonlendiriliyorsunuz" << endl;
					for (int i = 0; i <= 4; i++)
					{
						Sleep(500);
						cout << ".";
					}
					return false;
				}
				Sleep(500);
				goto label_password;
			}
		}
	}
	cout << "\t\tkullanici bulunamadi " << endl;
	Sleep(500);
	goto label_login;

	return false;
}



bool User::userLogin() {

	system("cls");
	int pass = 0, hak = 5, sifredegis = 0, password = 0;
	string userName;


	cout << "\n\t\t*                MEMBER LOG-IN              *" << endl;
label_login:
	cout << "\t\t===================================================" << endl;
	cout << "\t\tUsername : ";
	cin >> userName;
	cout << "\t\t---------------------------------------------------" << endl;
label_password:
	cout << "\t\tPassword : ";
	cin >> password;
	cout << "\t\t===================================================" << endl;
	hak--;
	for (int i = 0; i < vmember.size(); i++) {

		if (userName == vmember[i].getUsername()) {
			if (password == vmember[i].getPassword()) {
				cout << endl << "\t\tbasarili giris " << endl;
				Sleep(500);
				cout << endl << "\t\tlogining ";
				for (int i = 0; i <= 4; i++)
				{
					Sleep(500);
					cout << ".";
				}
				display.deger(userName);
				return true;
			}
			else {
				cout << "\t\tparola yanlis tekrar deneyiniz!.." << endl;
				Sleep(500);
				if (hak == 0) {
					cout << "\t\tcok fazla giris yapildi ana menuye yonlendiriliyorsunuz" << endl;
					for (int i = 0; i <= 4; i++)
					{
						Sleep(500);
						cout << ".";
					}
					return false;
				}
				Sleep(500);
				goto label_password;

			}
		}
	}
	cout << "\t\tkullanici bulunamadi " << endl;
	Sleep(500);
	goto label_login;

	return false;
}



bool User::userNewAccount() {
	system("cls");

	string _username, _firstname, _lastname;
	int _password;
	long long int _number;
	const int userBookAdd = 3;
	const string _outputFolder = "D:\\Proje\\kütüphane yönetim sistemi\\ProjectLib\\LibraryManagementSystem1\\LibraryManagementSystem\\UserTxTFolder\\";
	cout << "\n\t\tFirst Name : ";
	cin.ignore();
	getline(cin, _firstname);
	cout << "\t\tLast Name  : ";
	cin >> _lastname;

lvbel_c5:
	cout << "\t\tUsername   : ";
	cin >> _username;
	if (_username == _firstname) {
		cout << "\n\t\tAd kullanici adi ile ayni olamaz!!" << endl;
		Sleep(500);
		goto lvbel_c5;
	}
	else if (_username == _lastname)
	{
		cout << "\n\t\tsoyad kullanici adi ile ayni olamaz!!" << endl;
		Sleep(500);
		goto lvbel_c5;
	}

	while (true)
	{
		cout << "\t\t(6 haneli olacak sekilde)" << endl;
		cout << "\t\tpassword   : ";
		cin >> _password;
		bool sonuc2 = passwordControl(_password);
		if (sonuc2) {

			break;
		}
	}
	while (true)
	{
		cout << "\t\tnumber +90 -  ";
		cin >> _number;
		bool sonuc = numberControl(_number);
		if (sonuc) {

			break;
		}
	}
	int kullaniciNo = 2023001 + vmember.size();
	vmember.push_back(Member(_firstname, _lastname, _username, _password, _number, kullaniciNo));
	cout << "\t\tName     : " << _firstname << " " << _lastname << endl;
	cout << "\t\tUsername : " << _username << " " << endl;
	cout << "\t\tNumber   : " << _number << endl;
	cout << "\t\tID       : " << kullaniciNo << endl;
	cout << "\n\t\thesap kurulumu basarili  " << endl;


	ofstream file1("userlogin.txt", ios::app);

	if (!file1.is_open()) {
		cout << "Dosya acilamadi... " << endl;
	}
	else {
		file1 << _firstname << endl << _lastname << endl << _username << endl << _password << endl << _number << endl << kullaniciNo << endl;

		file1.close();
	}
	//kullanýcýya özel giriþ
	fstream userfile(_outputFolder + _username + ".txt", ios::app);
	if (!userfile.is_open()) {
		cout << "Dosya acilamadi... " << endl;
	}
	else {
		userfile << userBookAdd << endl;

		userfile.close();
	}
	for (int i = 0; i <= 4; i++)
	{
		Sleep(500);
		cout << ".";
	}

	userLogin();
	return true;
}




bool User::ManagerNewAccount() {
	system("cls");

	string _username, _firstname, _lastname;
	int _password;
	long long int _number;
	cout << "\n\t\tFirst Name : ";
	cin.ignore();
	getline(cin, _firstname);

	cout << "\t\tLast Name  : ";
	cin >> _lastname;

	cout << "\t\tUsername   : ";
	cin >> _username;


	while (true)
	{
		cout << "\t\t(6 haneli olacak sekilde)" << endl;
		cout << "\t\tpassword   : ";
		cin >> _password;
		bool sonuc2 = passwordControl(_password);
		if (sonuc2) {

			break;
		}
	}
	while (true)
	{
		cout << "\t\tnumber +90 -  ";
		cin >> _number;
		bool sonuc = numberControl(_number);
		if (sonuc) {

			break;
		}
	}
	vmanager.push_back(Manager(_firstname, _lastname, _username, _password, _number));
	cout << "\t\tName     : " << _firstname << " " << _lastname << endl;
	cout << "\t\tUsername : " << _username << " " << endl;
	cout << "\t\tNumber   : " << _number << endl;
	cout << "\n\t\thesap kurulumu basarili  " << endl;


	ofstream file1("managerlogin.txt", ios::app);

	if (!file1.is_open()) {
		cout << "Dosya acilamadi... " << endl;
	}
	else {
		file1 << _firstname << endl << _lastname << endl << _username << endl << _password << endl << _number << endl;

	}
	file1.close();
	for (int i = 0; i <= 4; i++)
	{
		Sleep(500);
		cout << ".";
	}

	managerLogin();
	return true;
}



bool User::userNewPassword() {
	system("cls");
	string name;
	int newpassword, newpassword2;
	cout << "\n\t\t                   USER NEW PASSWORD                  " << endl;
	cout << "Yeni sifre : ";
label_main:
	cin >> newpassword;
	if (newpassword >= 100000 && newpassword < 1000000) {

	}
	else {
		cout << "\n\t\t6 haneli sayi giriniz" << endl;
		goto label_main;
	}
label_password_2:
	cout << "\n\t\tYeni sifre tekrar : ";
	cin >> newpassword2;
	if (newpassword2 != newpassword) {
		cout << "\t\tyanlis girdiniz " << endl;
		goto label_password_2;
	}
	vmember[0].setPassword(newpassword);
	cout << "\n\t\tSifreniz degistirilmistir" << endl;

	return true;
}

bool User::passwordControl(int _password) {

	int  _sizeOfPassword = 0;
	while (true) {
		int _degree1 = 0;
		_sizeOfPassword = 0;
		_sizeOfPassword = _password;
		while (_sizeOfPassword > 0) {
			_sizeOfPassword = _sizeOfPassword / 10;
			_degree1++;
		}
		if (_degree1 == 6) {
			return true;
		}
		else {
			cout << "\n\thatali giris !.." << endl;
			return false;
		}
	}
	return false;
}

bool User::numberControl(long int number) {
	long int _sizeofnumber = 0;

	while (true) {
		int degree = 0;
		_sizeofnumber = number;
		while (_sizeofnumber > 0) {
			_sizeofnumber = _sizeofnumber / 10;
			degree++;
		}

		if (degree == 10) {
			return true;
		}
		else {
			cout << "\n\thatali giris !.." << endl;
			return false;
		}
	}
	return false;
}