#include <iostream>
#include <string>
#include<windows.h>           
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
using namespace std;

#include "UserLogin.h"
#include "MainMenu.h"
#include "Manager.h"
#include "Member.h"
#include "Book.h"
User user;
Manager manager;
Member member;
static string _outputFolder = "D:\\Proje\\kütüphane yönetim sistemi\\ProjectLib\\LibraryManagementSystem1\\LibraryManagementSystem\\UserTxTFolder\\";
void Display::deger(string isim) {
	username = isim;
}
void Display::displayMember() {
	while (true) {
		char choise;
		int syac;
		system("cls");
		cout << "\n\t\t\t\tLIBRARY " << endl;
		cout << "\t\t=======================================" << endl;
		cout << "\t\t [1] - Kitaplar       " << endl;
		cout << "\t\t---------------------------------------" << endl;
		cout << "\t\t [2] - Kitap iste     " << endl;
		cout << "\t\t---------------------------------------" << endl;
		cout << "\t\t [3] - Yeni Eklenenler" << endl;
		cout << "\t\t---------------------------------------" << endl;
		cout << "\t\t [4] - Odunc Kitap Al " << endl;
		cout << "\t\t---------------------------------------" << endl;
		cout << "\t\t [5] - Profil Goster  " << endl;
		cout << "\t\t---------------------------------------" << endl;
		cout << "\t\t [6] - Exit           " << endl;
		cout << "\t\t=======================================" << endl;
	label_choise:
		cout << "\t\ttercihiniz :  ";
		cin >> choise;

		switch (choise)
		{
		case '1':
			books();
			break;
		case '2':
			askBook();
			break;
		case '3':
			syac = sayaca();
			newAdded(syac);
			break;
		case '4':
			//borrowBook();
			kitapAl(username);
			break;
		case '5':
			showUserprofil();
			break;
		case '6':
			break;
		default:
			cout << endl << "\n\t\thatali tuslama yaptiniz !!" << endl;
			Sleep(500);
			goto label_choise;
			break;
		}
		if (choise == '6') {
			cout << "\n\n\t\tExciting";
			for (int i = 0; i <= 4; i++)
			{
				Sleep(500);
				cout << ".";
			}
			break;
		}
	}

}
void Display::displayManager() {
	while (true) {
		char choise;
		system("cls");
		cout << "\n\t\t\t      LIBRARY " << endl;
		cout << "\t\t=======================================" << endl;
		cout << "\t\t               MENU " << endl;
		cout << "\t\t=======================================" << endl;
		cout << "\t\t[1] - Kitap Islemleri    " << endl;
		cout << "\t\t---------------------------------------" << endl;
		cout << "\t\t[2] - Kitaplar           " << endl;
		cout << "\t\t---------------------------------------" << endl;
		cout << "\t\t[3] - Odunc verilenler   " << endl;
		cout << "\t\t---------------------------------------" << endl;
		cout << "\t\t[4] - Iade islemi       " << endl;
		cout << "\t\t---------------------------------------" << endl;
		cout << "\t\t[5] - Profil Goster      " << endl;
		cout << "\t\t---------------------------------------" << endl;
		cout << "\t\t[6] - Istek Listesi      " << endl;
		cout << "\t\t---------------------------------------" << endl;
		cout << "\t\t[7] - Exit               " << endl;
		cout << "\t\t=======================================" << endl;
	label_choise:
		cout << "\t\ttercihiniz :  ";
		cin >> choise;
		switch (choise)
		{
		case '1':
			kitapIslem();
			break;
		case '2':
			books();
			break;
		case '3':
			loaned();		
			break;
		case '4':
			returnedbook();
			
			break;
		case '5':
			showManagerProfil();
			break;
		case '6':
			wishBook();
			break;
		case '7':
			break;
		default:
			cout << endl << "\t\thatali tuslama yaptiniz !!" << endl;
			Sleep(500);
			goto label_choise;
			break;
		}
		if (choise == '7') {
			cout << "\n\n\t\tExciting";
			for (int i = 0; i <= 4; i++)
			{
				Sleep(300);
				cout << ".";
			}
			break;
		}
		
	}
}
void Display::showManagerProfil() {
	system("cls");
	char secim;

	fstream dosyaOku("managerlogin.txt");
	string satir = " ";
	int i = 0, a = 0;
	string arr[50];

	if (dosyaOku.is_open()) {

		while (getline(dosyaOku, satir)) {
			arr[i] = satir;
			if (arr[i] == username) {
				a = i;
			}
			i++;
		}

		dosyaOku.close();
	}

	cout << "\t\t			MANAGER PROFIL				\n" << endl;
	cout << "\t\t=======================================" << endl;
	cout << "\t\tUsername  : " << arr[a - 2] << endl;
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\tName      : " << arr[a] << " " << arr[a - 1] << endl;
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\tNumber ID : " << arr[a + 2] << endl;
	cout << "\t\t=======================================" << endl<<endl;

	cout << "\t\t[1] - Menuye Don   " << endl;
label_secim:
	cout << "\t\tsecim : ";
	cin >> secim;
	switch (secim) {
	case '1':
		break;
	default:
		cout << "\n\t\tHatali secim!..";
		Sleep(500);
		goto label_secim;
		break;
	}


}

void Display::showUserprofil() {
	system("cls");


	string satir = " ";
	int i = 0, a = 0, m = 0, n = 0, ab = 0;
	string arr[100], arr2[10], satir2;
	fstream dosyaOku("userlogin.txt");
	ifstream dosYa(_outputFolder + username + ".txt");

	if (dosYa.is_open()) {
		while (!dosYa.eof()) {
			dosYa >> satir2;
			if (m % 5 == 1) {
				arr2[n] = satir2;
				n++;
			}
			m++;
		}
	}
	dosYa.close();
	if (dosyaOku.is_open()) {

		while (getline(dosyaOku, satir)) {
			arr[i] = satir;
			if (arr[i] == username) {
				a = i;
				ab++;
			}
			i++;
		}
	}
	dosyaOku.close();
	int secim = 0;
	cout << "\t\t			  USER PROFIL				\n" << endl;
	cout << "\t\t=======================================" << endl;
	cout << "\t\tUsername  : " << arr[a] << endl;
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\tName      : " << arr[(a - 2)] << " " << arr[(a - 1)] << endl;
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\tNumber    : " << arr[a + 2] << endl;
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\tUser ID   : " << arr[a + 3] << endl;
	cout << "\t\t---------------------------------------" << endl;
	cout << "\n\n\t\tOdunc Alinan Kitaplar" << endl;
	cout << "\t\t=======================================" << endl;

	for (int k = 0; k <= 10; k++) {
		if (arr2[k] == "") {
			break;
		}
		else if (arr2[k] == "3" || arr2[k] == "2" || arr2[k] == "1" || arr2[k] == "0") {

		}
		else {
			cout << "\t\t" << k + 1 << ". Kitap : " << arr2[k] << endl<<endl;
		}
	}
	cout << "\t\t=======================================" << endl;
	char secenek;
	cout << endl << "\t\tMenuye donmek icin herhangi bir tusa basiniz...." << endl;
	cin >> secenek;

}
void Display::books() {
	char secim;
	system("cls");
	cout << "\t\t*			LIBRARY				*" << endl << endl;
	cout << "\t\t=================================================" << endl;
	cout << "\t\t[1] - Kitap Ara " << " || " << " [2] - Kitap listele" << endl;
	cout << "\t\t-------------------------------------------------" << endl;
	cout << "\t\t[3] - Menu" << endl;
	cout << "\t\t=================================================" << endl;
	cout << "\t\tsecim : ";
	cin >> secim;
	switch (secim)
	{
	case '1':
		kitapAra();
		break;
	case '2':
		kitapYazdir();
		break;
	case '3':
		break;
	default:
		cout << endl << "\t\thatali secim" << endl;
		break;
	}

}


void Display::loaned() {
	system("cls");
	Kitap kitap;
	int i = 0, m = 0, n = 0, k = 0, l = 0;
	int sayac12 = 0;
	string userData[50][3][5];
	string str;
	string** satir = new string * [50];
	for (int ix = 0; ix < 50; ix++) {
		satir[ix] = new string[6];
	}
	//DOSYA ÝSLEMLERÝ
	ifstream dosyaOku("userlogin.txt");
	if (!dosyaOku.is_open()) {
		cout << "dosya acilamadi";
	}
	else {
		while (!dosyaOku.eof()) {
			dosyaOku >> satir[i][m];
			if (m == 2) {
				ifstream dosyaOku2(_outputFolder + satir[i][2] + ".txt");
				if (!dosyaOku2.is_open()) {
					cout << "acik" << endl;
				}
				else {
					while (!dosyaOku2.eof()) {
						dosyaOku2 >> userData[n][k][l];
						l++;
						if (l == 5) {
							l = 0;
							k++;
						}
						if (k == 3) {
							k = 0;
						}
					}
					l = 0;
					k = 0;
					n++;
					dosyaOku2.close();
				}
			}
			m++;
			if (m == 6) {
				m = 0;
				i++;
			}

		}
		dosyaOku.close();
	}
	//yazdýrma islemi
	cout << "\n\t\t\t*      ODUNC VERILENLER      *";

	for (int x = 0; x < 50; x++) {

		if (userData[x][0][2] == "") {

			continue;
		}
		cout << "\n\t\t" << satir[x][2] << endl;
		cout << "\t\t=======================" << endl;
		for (int y = 0; y < 3; y++) {
			if (userData[x][y][1] == "") {
				break;
			}
			int eldekalmasuresi;
			int ilkgun;
			int songun;
			int gunfark;
			int kalangun;
			stringstream zz(userData[x][y][4]);
			zz >> eldekalmasuresi;
			stringstream ss(userData[x][y][3].substr(0, 2));
			ss >> ilkgun;
			stringstream aa(getFormattedDate().substr(0, 2));
			aa >> songun;
			gunfark = songun - ilkgun;
			kalangun = eldekalmasuresi - gunfark;


			cout << "\t\t-------------------------------------------" << endl;
			cout << "\t\tKitap adi : " << userData[x][y][1] << endl;
			cout << "\t\tRaf no    : " << userData[x][y][2] << endl;
			cout << "\t\tAlim Gunu : " << userData[x][y][3] << endl;
			cout << "\t\tElde kalinacak gun : " << userData[x][y][4] << endl;
			cout << "\t\tKalan gun : " << kalangun;
			if (kalangun > 0) {

			}
			else if (kalangun == 0) {
				cout << "\t!!Teslim gunu";
			}
			else if (kalangun < 0 && kalangun >= -2) {
				cout << "\t!!Teslim gunu gecti";
			}
			else {
				cout << "\t!!Kullaniciyi uyar!!";
			}
			cout << endl;

			cout << "\t\t-------------------------------------------" << endl;
		}
		cout << "\t\t=======================" << endl;

	}
	char secenek;
	cout << "\t\tMenuye donmek icin herhangi bir tusa basiniz...." << endl;
	cin >> secenek;
	//
}
void Display::returnedbook() {
	system("cls");
	string kullanici;
	cout << "\t\t\t*       IADE ISLEMLERI       *  ";

	bool islemsonuc = false;
	string userData[4][5];
	int i = 0, k = 0;
	char hangiKitap;
label_choice:
	cout << "\t\t==============================================" << endl;
	cout << "\t\t|| iade Yapacak kisinin kullanici adi :  ";
	cin >> kullanici;
	string kullaniciAdi = toLowerCase(kullanici);

	ifstream inputFile(_outputFolder + kullaniciAdi + ".txt");
	ofstream outputFile(_outputFolder + "temp.txt");

	if (!inputFile.is_open() || !outputFile.is_open()) {
		cout << "Kullanici Bulunamadi!!" << endl;
	}

	while (!inputFile.eof()) {
		inputFile >> userData[k][i];
		i++;
		if (i == 5) {
			i = 0;
			k++;
		}
		if (k == 4) {
			break;
		}
	}
	inputFile.close();


	k = 0;
	for (int n = 0; n < 3; n++) {
		if (userData[n][1] == "") {
			break;
		}
		cout << "\t\t==============================" << endl;
		cout << "\t\t" << n + 1 << ".kitap: " << userData[n][1] << endl;
		cout << "\t\t==============================" << endl << endl;
		k++;
	}
label_kitapsec:
	cout << "\t\tIade edilecek kitap : ";
	cin >> hangiKitap;
	switch (hangiKitap)
	{
	case '1':
		if (k < 1) {
			goto label_kitapsec;
		}
		else {
			for (int a = 0; a < 4; a++) {
				if (a == 0) {
					continue;
				}

				for (int b = 0; b < 5; b++) {
					if (userData[a][b] == "") {
						continue;
					}
					else
					{
						if (b == 0) {
							stringstream ss(userData[a][b]);
							int yenideger;
							ss >> yenideger;
							outputFile << yenideger + 1 << endl;
						}
						else {
							outputFile << userData[a][b] << endl;
						}
					}

				}
			}
		}
		cout << "\t\t Iade tamamlandi!!" << endl;
		outputFile.close();
		islemsonuc = true;
		break;
	case '2':
		if (k < 2) {
			goto label_kitapsec;
		}
		else {
			for (int a = 0; a < 4; a++) {
				if (a == 1) {
					continue;
				}

				for (int b = 0; b < 5; b++) {
					if (userData[a][b] == "") {
						continue;
					}
					else
					{
						if (a != 0 && b == 0) {
							stringstream ss(userData[a][b]);
							int yenideger;
							ss >> yenideger;
							outputFile << yenideger + 1 << endl;
						}
						else {
							outputFile << userData[a][b] << endl;
						}
					}
				}
			}
		}
		cout << "\t\t Iade tamamlandi!!" << endl;
		outputFile.close();
		islemsonuc = true;
		break;
	case '3':
		if (k < 3) {
			goto label_kitapsec;
		}
		else {
			for (int a = 0; a < 4; a++) {
				if (a == 2) {
					continue;
				}

				for (int b = 0; b < 5; b++) {
					if (userData[a][b] == "") {
						continue;
					}
					else
					{
						if (a != 0 && a != 1 && b == 0) {
							stringstream ss(userData[a][b]);
							int yenideger;
							ss >> yenideger;
							outputFile << yenideger + 1 << endl;
						}
						else {
							outputFile << userData[a][b] << endl;
						}
					}
				}
			}
		}
		cout << "\t\tIade tamamlandi!!" << endl;
		outputFile.close();
		islemsonuc = true;
		break;
	default:
		cout << "\t\t hatali secim !!" << endl;
		goto label_kitapsec;
		break;
	}
	string dosyasil = _outputFolder + kullaniciAdi + ".txt";
	string testisim = _outputFolder + "temp.txt";
	if (islemsonuc) {
		remove(dosyasil.c_str());
		bool deger = rename(testisim.c_str(), dosyasil.c_str());
		if (deger) {
			//cout << "basarili";
		}
		else {
			//cout << "basarisiz";

		}
	}
	else {

	}
	char secenek;
	cout << "\t\tMenuye donmek icin herhangi bir tusa basiniz...." << endl;
	cin >> secenek;

}
string Display::toLowerCase(const string& str) {
	string result;
	transform(str.begin(), str.end(), back_inserter(result),
		[](char c) { return tolower(c); });
	return result;
}

void Display::askBook() {
	system("cls");
	string bookName;
	char evethayir;
	fstream file1("istekliste.txt", ios::app);
	if (!file1.is_open()) {
		cout << "Dosya acilamadi... " << endl;
	}


	cout << "\n\n\t                                 ISTEK LISTESÝ                            \n\n";
	cout << endl << "\tEklenilmesini istediginiz kitap adi : ";
	cin.ignore();
	getline(cin, bookName);
lebel_c5:
	cout << "\n\tIstek iletilecek onayliyor musunuz? (1 - Evet) (2 - hayir)";
	cin >> evethayir;
	if (evethayir == '1') {
		file1 << "- " << bookName << " -" << endl;
		cout << "\n\tMenuye donuluyor!.." << endl;
		Sleep(1500);
		file1.close();
	}
	else if (evethayir == '2') {
		file1.close();
		cout << "\n\tMenuye donuluyor!.." << endl;
		Sleep(1500);
	}
	else {
		cout << "\n\thatali tuslama!.." << endl;
		Sleep(500);
		goto lebel_c5;
	}
}

void Display::wishBook() {
	system("cls");
	string satir;
	fstream file1("istekliste.txt");
	if (!file1.is_open()) {
		cout << "Dosya acilamadi... " << endl;
	}
	cout << "\n\n\t                                 ISTEK LISTESÝ                            \n\n";

	while (!file1.eof()) {
		file1 >> satir;
		if (satir == "-") {
			cout << endl << " -------------------------" << endl;
			continue;
		}
		cout << "   " << satir;

	}

	char secenek;
	cout << "Menuye donmek icin herhangi bir tusa basiniz...." << endl;
	cin >> secenek;
}

void Display::kitapIslem() {
	system("cls");
	book kitap;
	fstream file1("book.txt", ios::app);

	if (!file1.is_open()) {
		cout << "Dosya acilamadi... " << endl;
	}

	char secim;
	cout << "\n\t\t\t*       KITAP ISLEMLERI       *"<<endl<<endl;
	cout << "\t\t=======================================" << endl;
	cout << "\t\t[1] - Kitap Ekle         " << endl;
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\t[2] - Kitap Cikar        " << endl;
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\t[3] - kitap Guncelle     " << endl;
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\t[4] - Menu               " << endl;
	cout << "\t\t=======================================" << endl;
	label_secim:
	cout << "\t\tsecim : ";
	cin >> secim;
	switch (secim)
	{
	case '1':
		cin >> kitap;
		file1 << kitap;
		file1.close();
		break;
	case '2':
		kitapCikar();
		break;
	case '3':
		kitapGuncelle();
		break;
	case '4':
		break;
	default:
		cout << "\t\thata islemi..."<<endl;
		goto label_secim;
		break;
	}
	if (!file1.is_open())
	{
		file1.close();
	}
	

}