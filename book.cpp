#include "book.h"
#include "Dfa.h"
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int degere = 0;
static string _outputFolder = "D:\\Proje\\kütüphane yönetim sistemi\\ProjectLib\\LibraryManagementSystem1\\LibraryManagementSystem\\UserTxTFolder\\";

book::book() {

}
book::book(string _bookName) {
	bookName = bookName;
}

book::book(string _bookName, string _author, string _publisher, string _kind, string _language, int _year, int _bookStock, int _pageNumber, long  int _ID, int _shelfNo) {
	setBookName(_bookName);
	setAuthor(_author);
	setPublisher(_publisher);
	setKind(_kind);
	language = _language;
	year = _year;
	bookStock = _bookStock;
	setPageNumber(_pageNumber);
	ID = _ID;
	shelfNo = _shelfNo;
}

book::~book() {

}

void book::setBookName(string _bookName) {
	bookName = _bookName;
}
string book::getBookName() {
	return bookName;
}

void book::setAuthor(string _author) {
	author = _author;
}
string book::getAuthor() {
	return author;
}

void book::setPublisher(string _publisher) {
	publisher = _publisher;
}
string book::getPublisher() {
	return publisher;
}

void book::setKind(string _kind) {
	kind = _kind;
}
string book::getKind() {
	return kind;
}

void book::setPageNumber(int _pageNumber) {
	pageNumber = _pageNumber;
}
int book::getPageNumber() {
	return pageNumber;
}

void book::setID(long int _ID) {
	ID = _ID;
}
long int book::getID() {
	return ID;
}


//KÝTAP YAZDIRMA**********************************************
void book::kitapYazdir() {
	system("cls");
	fstream dosyaOku("book.txt");
	string** satir = new string * [100];
	for (int ix = 0; ix < 100; ix++) {
		satir[ix] = new string[10];
	}

	int n = 0, m = 0;

	if (dosyaOku.is_open()) {
		while (!dosyaOku.eof()) {
			dosyaOku >> satir[n][m];
			m++;
			if (m == 10) {
				m = 0;
				n++;
			}
		}
		dosyaOku.close();
	}

	for (int a = 0; a < 10; a++) {
		int anum = (a + 1) * 5;
		for (int x = anum - 5; x < anum; x++) {
			if (satir[x][1] == "") {
				a = 55;
				break;
			}
			if (x % 5 == 0) {
				cout << "\t";
			}
			cout << "\t[" << x + 1 << "] - Kitap\t";
		}
		cout << endl;
		for (int xa = anum - 5; xa < anum; xa++) {
			if (xa % 5 == 0) {
				cout << "\t   =";
			}
			cout << "==========================";
		}
		cout << endl;
		for (int xb = anum - 5; xb < anum; xb++) {
			if (satir[xb][1] == "") { break; }
			if (xb % 5 == 0) {
				cout << "Kitap adi  : ";
			}
			cout << satir[xb][0];
			for (int xba = 0; xba < 25 - satir[xb][0].size(); xba++) {
				cout << " ";
			}

		}
		cout << endl;
		for (int xc = anum - 5; xc < anum; xc++) {
			if (satir[xc][1] == "") { break; }
			if (xc % 5 == 0) {
				cout << "Yazar      : ";
			}
			cout << satir[xc][1];
			for (int xca = 0; xca < 25 - satir[xc][1].size(); xca++) {
				cout << " ";
			}
		}
		cout << endl;
		for (int xd = anum - 5; xd < anum; xd++) {
			if (satir[xd][2] == "") { break; }
			if (xd % 5 == 0) {
				cout << "Yayin evi  : ";
			}
			cout << satir[xd][2];
			for (int xda = 0; xda < 25 - satir[xd][2].size(); xda++) {
				cout << " ";
			}
		}
		cout << endl;
		for (int xe = anum - 5; xe < anum; xe++) {
			if (satir[xe][3] == "") { break; }
			if (xe % 5 == 0) {
				cout << "Tur        : ";
			}
			cout << satir[xe][3];
			for (int xea = 0; xea < 25 - satir[xe][3].size(); xea++) {
				cout << " ";
			}
		}
		cout << endl;
		for (int xf = anum - 5; xf < anum; xf++) {
			if (satir[xf][4] == "") { break; }
			if (xf % 5 == 0) {
				cout << "Dil        : ";
			}
			cout << satir[xf][4];
			for (int xfa = 0; xfa < 25 - satir[xf][4].size(); xfa++) {
				cout << " ";
			}
		}
		cout << endl;
		for (int xg = anum - 5; xg < anum; xg++) {
			if (satir[xg][5] == "") { break; }
			if (xg % 5 == 0) {
				cout << "Yayim Yili : ";
			}
			cout << satir[xg][5];
			for (int xga = 0; xga < 25 - satir[xg][5].size(); xga++) {
				cout << " ";
			}
		}
		cout << endl;
		for (int xh = anum - 5; xh < anum; xh++) {
			if (satir[xh][6] == "") { break; }
			if (xh % 5 == 0) {
				cout << "Sayfa Sayi : ";
			}
			cout << satir[xh][6];
			for (int xha = 0; xha < 25 - satir[xh][6].size(); xha++) {
				cout << " ";
			}
		}
		cout << endl;
		for (int xi = anum - 5; xi < anum; xi++) {
			if (satir[xi][7] == "") { break; }
			if (xi % 5 == 0) {
				cout << "Kitap ID   : ";
			}
			cout << satir[xi][7];
			for (int xia = 0; xia < 25 - satir[xi][7].size(); xia++) {
				cout << " ";
			}
		}
		cout << endl;
		for (int xj = anum - 5; xj < anum; xj++) {
			if (satir[xj][8] == "") { break; }
			if (xj % 5 == 0) {
				cout << "Raf no     : ";
			}
			cout << satir[xj][8];
			for (int xja = 0; xja < 25 - satir[xj][8].size(); xja++) {
				cout << " ";
			}
		}
		cout << endl;
		for (int xk = anum - 5; xk < anum; xk++) {
			if (satir[xk][9] == "") { break; }
			if (xk % 5 == 0) {
				cout << "Stok no    : ";
			}
			cout << satir[xk][9];
			for (int xka = 0; xka < 25 - satir[xk][9].size(); xka++) {
				cout << " ";
			}
		}
		cout << endl;
	}
	cin >> m;
}
//KÝTAP CIKARMA
void book::kitapCikar() {

	string name;
	char sec, seci;
	system("cls");
	cout << "\t\t*			LIBRARY				*" << endl << endl;
	cout << "\t\t=================================================" << endl;
	cout << "\t\t[1] - Kitap adi gir " << " || " << " [2] - Menu" << endl;
	cout << "\t\t=================================================" << endl;
label_sec:
	cout << "\t\tsecim : ";
	cin >> sec;
	if (sec == '1')
	{
		cout << "\t\tSilinecek Kitap Adini Giriniz: " << endl;
		cin >> name;

		ifstream inputFile("book.txt");
		ofstream outputFile("temp.txt");

		if (!inputFile.is_open() || !outputFile.is_open()) {
			cerr << "Dosya açýlamadý!" << endl;
			return;
		}
		string line;
		bool bookFound = false;
		int lineNo = 1;
		int lineCntrl = 1;
		bool taskDone = false;
		while (getline(inputFile, line)) {
			if (bookFound == false) {
				if (lineNo % 10 == 1) {

					if (line.find(name) != string::npos) {

						bookFound = true;
					}
					else {

						outputFile << line << endl;
					}
				}
				else {

					outputFile << line << endl;
				}
			}
			else if (bookFound == true) {

				if (lineCntrl == 9) {
					lineCntrl = 0;
					bookFound = false;
					taskDone = true;
				}
				lineCntrl++;
			}
			lineNo++;
		}


		inputFile.close();
		outputFile.close();

		if (!taskDone) {
			cout << "\t\tKitap bulunamadi." << endl;
			remove("temp.txt");
			for (int i = 0; i <= 4; i++)
			{
				Sleep(500);
				cout << ".";
			}
		}
		else {
			cout << "\t\tKitap Silindi!..." << endl;
			remove("book.txt");
			int renameResult = rename("temp.txt", "book.txt");

			if (renameResult != 0) {
				cout << "\t\tislem basarisiz" << endl;
			}

			for (int i = 0; i <= 4; i++)
			{
				Sleep(500);
				cout << ".";
			}

		}
		cout << "\n\t\tmenuye donmek icin bir tusa basiniz..." << endl;
		cin >> seci;
	}
	else if (sec == '2')
	{
		cout << "\t\tMenuye donuluyor..." << endl;
		Sleep(1000);
	}
	else 
	{
		goto label_sec;
	}
	
}
///////////////////////////////////////////
void book::kitapGuncelle() {
	system("cls");
	cout << "\n\t\t\t*       KITAP GUNCELLE       *" << endl << endl;
	cout << "\n\t\tKitap ID'sini giriniz: ";
	long int kitapID;
	cin >> kitapID;

	vector<string> books = readBooks();
	bool kitapVar = false;
	size_t kitapIndex;

	// Kitap ID'sini ara
	for (size_t i = 7; i < books.size(); i += 10) {
		if (stoi(books[i]) == kitapID) {
			kitapVar = true;
			kitapIndex = i;
			break;
		}
	}

	if (!kitapVar) {
		cout << "\nKitap bulunamadi." << endl;
		return;
	}

	// Kitabýn mevcut bilgilerini göster
	cout << "\n\t\tMevcut Kitap Bilgileri\n";
	cout << "\t\t===================================" << endl << endl;
	cout << "\t\tKitap Adi    : " << books[kitapIndex - 7] << endl;
	cout << "\t\tYazar        : " << books[kitapIndex - 6] << endl;
	cout << "\t\tYayin Evi    : " << books[kitapIndex - 5] << endl;
	cout << "\t\tTur          : " << books[kitapIndex - 4] << endl;
	cout << "\t\tDil          : " << books[kitapIndex - 3] << endl;
	cout << "\t\tYayin Tarihi : " << books[kitapIndex - 2] << endl;
	cout << "\t\tSayfa Sayisi : " << books[kitapIndex - 1] << endl;
	cout << "\t\t===================================" << endl << endl;
	// Kullanýcýdan onay al
	cout << "\n\t\tKitap bilgilerini guncellemek istiyor musunuz? (1 - Evet, 2 - Hayir): ";
	int onay;
	cin >> onay;

	if (onay != 1) {
		cout << "\n\t\tKitap bilgileri guncellenmedi." << endl;
		return;
	}

	// Yeni bilgileri al
	cout << "\n\t\tKitap Adi    : ";
	cin >> bookName;

	cout << "\t\tYazar        : ";
	cin >> author;

	cout << "\t\tYayin Evi    : ";
	cin >> publisher;

	cout << "\t\tTur          : ";
	cin >> kind;

	cout << "\t\tDil          : ";
	cin >> language;

	cout << "\t\tYayin Tarihi : ";
	cin >> year;

	cout << "\t\tSayfa Sayisi : ";
	cin >> pageNumber;

	// Yeni bilgileri vector'a ekle
	books[kitapIndex - 7] = bookName;
	books[kitapIndex - 6] = author;
	books[kitapIndex - 5] = publisher;
	books[kitapIndex - 4] = kind;
	books[kitapIndex - 3] = language;
	books[kitapIndex - 2] = to_string(year);
	books[kitapIndex - 1] = to_string(pageNumber);

	// Dosyayý güncelle
	ofstream dosyaYaz("book.txt");
	if (dosyaYaz.is_open()) {
		for (size_t i = 0; i < books.size(); ++i) {
			dosyaYaz << books[i] << endl;
		}
		cout << "\n\t\tKitap bilgileri basariyla guncellendi." << endl;

		// Güncellenmiþ kitap bilgilerini göster
		cout << "\n\t\tGuncellenmis Kitap Bilgileri:\n";
		cout << "\t\t===================================" << endl << endl;
		cout << "\t\tKitap Adi    : " << bookName << endl;
		cout << "\t\tYazar        : " << author << endl;
		cout << "\t\tYayin Evi    : " << publisher << endl;
		cout << "\t\tTur          : " << kind << endl;
		cout << "\t\tDil          : " << language << endl;
		cout << "\t\tYayin Tarihi : " << year << endl;
		cout << "\t\tSayfa Sayisi : " << pageNumber << endl;
		cout << "\t\t===================================" << endl << endl;
	}
	else {
		cout << "\nDosya acilamadi." << endl;
	}

	char seccenek;
	cout << "\t\tMenuye donmek icin bir tusa basiniz";
	cin >> seccenek;
}


void book::kitapAl(string _username) {
	system("cls");
	string kitapID, satir1;
	bool hakvaryok = false, kitapKontrol = false;
	bool islemtamam = false;
	int n = 0, m = 0, mi = 0;
	char  secim;
	string fileuser[20], yenideger;
	string formattedDate = getFormattedDate();
	string** satir = new string * [100];
	for (int ix = 0; ix < 100; ix++) {
		satir[ix] = new string[10];
	}

	//DOSYAÝSLEM===================================================================================
	ifstream dosyaOku("book.txt");
	ofstream dosyaOku2("temp.txt");
	ofstream bookwrituser(_outputFolder + _username + ".txt", ios::app);
	ifstream bookreaduser(_outputFolder + _username + ".txt");
	if (!dosyaOku.is_open()) {
		cout << "Kitap dosyasi acilamadi!" << endl;
		return;
	}
	if (!dosyaOku2.is_open()) {
		cout << "dosya acilamadi!" << endl;
		return;
	}
	if (!bookreaduser.is_open()) {
		cout << "Kullanici dosyasi acilamadi!" << endl;
		return;
	}
	if (dosyaOku.is_open()) {
		while (!dosyaOku.eof()) {
			dosyaOku >> satir[n][m];
			m++;
			if (m == 10) {
				m = 0;
				n++;
			}
		}
		dosyaOku.close();
	}
	if (bookreaduser.is_open()) {
		while (!bookreaduser.eof()) {
			bookreaduser >> fileuser[mi];
			mi++;
		}
		bookreaduser.close();
	}
	for (int kj = 0; kj < mi; kj++) {
		if (fileuser[kj] == "3") {
			yenideger = "2";
		}
		else if (fileuser[kj] == "2") {
			yenideger = "1";
		}
		else if (fileuser[kj] == "1") {
			yenideger = "0";
		}
		else if (fileuser[kj] == "0") {
			cout << "Uzgunum kitap hakkiniz dolmustur!..." << endl;
			hakvaryok = true;

		}
	}

	cout << "\n\t\t\t*       KITAP ODUNC AL       *";
	if (!hakvaryok) {
		//MAÝN ÝSLEMLERÝ===================================================================================
	label_main_secim:
		cout << endl << endl;
		cout << "\t\t========================================================" << endl;
		cout << "\t\t[1] - Kitap ID giriniz " << endl;
		cout << "\t\t--------------------------------------------------------" << endl;
		cout << "\t\t[2] - Kitap ara        " << endl;
		cout << "\t\t--------------------------------------------------------" << endl;
		cout << "\t\t[3] - Cikis            " << endl;
		cout << "\t\t========================================================" << endl;
		cout << "\t\tSeciminiz: ";
		cin >> secim;
		switch (secim) {
		case '1'://ID secimi =========================================
			cout << "\t\t========================================================" << endl;
			cout << endl << "\tID : ";
			cin >> kitapID;

			for (int xy = 0; xy < 100; xy++) {

				int index = satir[xy][7].find(kitapID);
				if (satir[xy][7] == "") {
					bookwrituser.close();
					Sleep(500);
					break;
				}
				else if (index == -1) {
					if (xy == 99) {
						cout << "\t\tkitap Bulunamadi" << endl;
						bookwrituser.close();
					}
				}
				else {
					for (int xc = 0; xc < mi; xc++) {
						if (satir[xy][0] == fileuser[xc]) {
							cout << endl << "\t\tBu kitap zaten alinmistir!.." << endl;
							kitapKontrol = true;
							Sleep(1000);
							break;
						}
						else if (satir[xy][9] == "0") {
							cout << "\t\tKitap stokta kalmamistir !.." << endl;
							Sleep(1500);
							xy = 101;
							kitapKontrol = true;
							break;

						}

					}

					if (!kitapKontrol) {
						{
						label_evethayir:
							cout << endl << "\t\tKitabiniz '" << satir[xy][0] << "' ";
							cout << "\t\tevet[1] Hayir[2]" << endl;
							char evetHayir;
							cin >> evetHayir;
							if (evetHayir == '1') {
							label_donus:
								cout << endl << "\t\tDonus zamani [6 - 9  - 12]   " << endl;
								int donus;
								cin >> donus;
								switch (donus)
								{
								case 6:
									bookwrituser << satir[xy][0] << endl << satir[xy][8] << endl << formattedDate << endl << donus << endl << yenideger << endl;
									bookwrituser.close();
									//stok azalt

									for (int xx = 0; xx < 100; xx++) {
										for (int yy = 0; yy < 10; yy++) {
											if (satir[xx][yy] == "") {
												xx = 101;
												break;
											}
											if (xx == xy && yy == 9) {

												stringstream ss(satir[xx][yy]);
												int degerazalt;
												ss >> degerazalt;

												degerazalt = degerazalt - 1;

												dosyaOku2 << degerazalt << endl;

											}
											else
											{
												dosyaOku2 << satir[xx][yy] << endl;
											}
										}
									}
									islemtamam = true;
									dosyaOku2.close();
									//stok azalt
									cout << "========================================================" << endl;
									cout << "\tKitap alimi basarili ";
									Sleep(1500);
									break;
								case 9:
									bookwrituser << satir[xy][0] << endl << satir[xy][8] << endl << formattedDate << endl << donus << endl << yenideger << endl;
									bookwrituser.close();
									//stok azalt

									for (int xx = 0; xx < 100; xx++) {
										for (int yy = 0; yy < 10; yy++) {
											if (xx == xy && yy == 9) {
												stringstream ss(satir[xx][yy]);
												int degerazalt;
												ss >> degerazalt;

												degerazalt = degerazalt - 1;

												dosyaOku2 << degerazalt << endl;
											}
											else
											{
												dosyaOku2 << satir[xx][yy] << endl;
											}
										}
									}
									islemtamam = true;
									dosyaOku2.close();
									//stok azalt
									cout << "========================================================" << endl;
									cout << "\tKitap alimi basarili ";
									Sleep(1500);
									break;
								case 12:
									bookwrituser << satir[xy][0] << endl << satir[xy][8] << endl << formattedDate << endl << donus << endl << yenideger << endl;
									bookwrituser.close();
									//stok azalt

									for (int xx = 0; xx < 100; xx++) {
										for (int yy = 0; yy < 10; yy++) {
											if (xx == xy && yy == 9) {
												stringstream ss(satir[xx][yy]);
												int degerazalt;
												ss >> degerazalt;

												degerazalt = degerazalt - 1;

												dosyaOku2 << degerazalt << endl;

											}
											else
											{
												dosyaOku2 << satir[xx][yy] << endl;
											}
										}
									}
									islemtamam = true;
									dosyaOku2.close();
									//stok azalt
									cout << "========================================================" << endl;
									cout << "\tKitap alimi basarili ";
									Sleep(1500);
									break;
								default:
									cout << "hatali secim";
									goto label_donus;
									break;
								}
								break;
							}
							else if (evetHayir == '2') {
								continue;
							}
							else {
								cout << endl << "hatali secim";
								goto label_evethayir;
							}

						}
					}
					else {

						goto label_main_secim;

					}
				}
			}
			break;
		case '2'://=========================================
			kitapAra();
			goto label_main_secim;
			break;
		case '3'://=========================================
			bookwrituser.close();
			dosyaOku2.close();
			break;
		default:
			cout << endl << "Hatali secim!" << endl;
			Sleep(500);
			goto label_main_secim;
			break;
		}
		//Ýslem bitti =========================================

		for (int ix = 0; ix < 100; ix++) {
			delete[] satir[ix];
		}
		delete[] satir;
	}
	else {
		Sleep(1500);
		bookwrituser.close();
	}
	if (islemtamam) {
		remove("book.txt");
		rename("temp.txt", "book.txt");
	}
	else {
		bookwrituser.close();
		dosyaOku2.close();
	}


}

string book::getFormattedDate() {
	time_t now;
	time(&now);

	tm ltm;
	localtime_s(&ltm, &now);

	int day = ltm.tm_mday;
	int month = 1 + ltm.tm_mon;
	int year = 1900 + ltm.tm_year;

	std::ostringstream formattedDate;
	formattedDate << day << "." << month << "." << (year % 100);

	return formattedDate.str();
}



void book::newAdded(int degere) {
	system("cls");

	fstream dosyaOku("book.txt");
	string** satir = new string * [100];
	for (int ix = 0; ix < 100; ix++) {
		satir[ix] = new string[10];
	}

	int n = 0, m = 0;

	if (dosyaOku.is_open()) {
		while (!dosyaOku.eof()) {
			dosyaOku >> satir[n][m];
			m++;
			if (m == 10) {
				m = 0;
				n++;
			}
		}
		dosyaOku.close();
	}

	cout << "\n\n\n\t	       *                    YENI EKLENENLER						*	\n\n\n" << endl;


	int anum = (degere);
	for (int x = anum - 5; x < anum; x++) {
		if (satir[x][1] == "") {

			break;
		}
		if (x % anum - 5 == 0) {
			cout << "\t";
		}
		cout << "\t[" << x + 1 << "] - Kitap\t";
	}
	cout << endl;
	for (int xa = anum - 5; xa < anum; xa++) {
		if (xa % anum - 5 == 0) {
			cout << "\t   =";
		}
		cout << "==========================";
	}
	cout << endl;
	for (int xb = anum - 5; xb < anum; xb++) {
		if (satir[xb][1] == "") { break; }
		if (xb % anum - 5 == 0) {
			cout << "Kitap adi  : ";
		}
		cout << satir[xb][0];
		for (int xba = 0; xba < 25 - satir[xb][0].size(); xba++) {
			cout << " ";
		}

	}
	cout << endl;
	for (int xc = anum - 5; xc < anum; xc++) {
		if (satir[xc][1] == "") { break; }
		if (xc % anum - 5 == 0) {
			cout << "Yazar      : ";
		}
		cout << satir[xc][1];
		for (int xca = 0; xca < 25 - satir[xc][1].size(); xca++) {
			cout << " ";
		}
	}
	cout << endl;
	for (int xd = anum - 5; xd < anum; xd++) {
		if (satir[xd][2] == "") { break; }
		if (xd % anum - 5 == 0) {
			cout << "Yayin evi  : ";
		}
		cout << satir[xd][2];
		for (int xda = 0; xda < 25 - satir[xd][2].size(); xda++) {
			cout << " ";
		}
	}
	cout << endl;
	for (int xe = anum - 5; xe < anum; xe++) {
		if (satir[xe][3] == "") { break; }
		if (xe % anum - 5 == 0) {
			cout << "Tur        : ";
		}
		cout << satir[xe][3];
		for (int xea = 0; xea < 25 - satir[xe][3].size(); xea++) {
			cout << " ";
		}
	}
	cout << endl;
	for (int xf = anum - 5; xf < anum; xf++) {
		if (satir[xf][4] == "") { break; }
		if (xf % anum - 5 == 0) {
			cout << "Dil        : ";
		}
		cout << satir[xf][4];
		for (int xfa = 0; xfa < 25 - satir[xf][4].size(); xfa++) {
			cout << " ";
		}
	}
	cout << endl;
	for (int xg = anum - 5; xg < anum; xg++) {
		if (satir[xg][5] == "") { break; }
		if (xg % anum - 5 == 0) {
			cout << "Yayim Yili : ";
		}
		cout << satir[xg][5];
		for (int xga = 0; xga < 25 - satir[xg][5].size(); xga++) {
			cout << " ";
		}
	}
	cout << endl;
	for (int xh = anum - 5; xh < anum; xh++) {
		if (satir[xh][6] == "") { break; }
		if (xh % anum - 5 == 0) {
			cout << "Sayfa Sayi : ";
		}
		cout << satir[xh][6];
		for (int xha = 0; xha < 25 - satir[xh][6].size(); xha++) {
			cout << " ";
		}
	}
	cout << endl;
	for (int xi = anum - 5; xi < anum; xi++) {
		if (satir[xi][7] == "") { break; }
		if (xi % anum - 5 == 0) {
			cout << "Kitap ID   : ";
		}
		cout << satir[xi][7];
		for (int xia = 0; xia < 25 - satir[xi][7].size(); xia++) {
			cout << " ";
		}
	}
	cout << endl;
	for (int xj = anum - 5; xj < anum; xj++) {
		if (satir[xj][8] == "") { break; }
		if (xj % anum - 5 == 0) {
			cout << "Raf no     : ";
		}
		cout << satir[xj][8];
		for (int xja = 0; xja < 25 - satir[xj][8].size(); xja++) {
			cout << " ";
		}
	}
	cout << endl;
	for (int xk = anum - 5; xk < anum; xk++) {
		if (satir[xk][9] == "") { break; }
		if (xk % anum - 5 == 0) {
			cout << "Stok no    : ";
		}
		cout << satir[xk][9];
		for (int xka = 0; xka < 25 - satir[xk][9].size(); xka++) {
			cout << " ";
		}
	}
	cout << endl;

	char secenek;
	cout << endl << "Menuye donmek icin herhangi bir tusa basiniz...." << endl;
	cin >> secenek;
	//
}


istream& operator>>(std::istream& input, book& kitap) {
	system("cls");
	int deger = 0;
	string bos;
	int i = 0;
	ifstream dosya("book.txt");
	if (dosya.is_open()) {
		while (!dosya.eof()) {
			dosya >> bos;
			if (i % 10 == 0) {
				deger++;

			}
			i++;

		}
		dosya.close();
	}
	cout << "\n\t\t\t*       KITAP EKLE       *";
	cout << "\t\tKitap adini giriniz: " << endl;
	input.ignore();
	input >> kitap.bookName;

	cout << "\t\tYazari giriniz: " << endl;
	input >> kitap.author;

	cout << "\t\tYayimevini giriniz: " << endl;
	input >> kitap.publisher;

	cout << "\t\tKitap turunu giriniz: " << endl;
	input >> kitap.kind;

	cout << "\t\tKitap dilini giriniz: " << endl;
	input >> kitap.language;

	cout << "\t\tBasim yilini  giriniz: " << endl;
	input >> kitap.year;

	cout << "\t\tKitabin sayfa sayisi: " << endl;
	input >> kitap.pageNumber;

	cout << "\t\tKitabin bulundugu raf numarasini giriniz: " << endl;
	input >> kitap.shelfNo;
	cout << "\t\tkitap Adedi : ";
	input >> kitap.bookStock;
	kitap.ID = 230001 + deger;


	return input;
}

ostream& operator<<(std::ostream& output, const book& kitap) {


	fstream file1("book.txt", ios::app);

	if (!file1.is_open()) {
		cout << "Dosya acilamadi... " << endl;
	}
	else {
		output << endl << kitap.bookName << endl << kitap.author << endl << kitap.publisher << endl << kitap.kind << endl << kitap.language << endl << kitap.year << endl << kitap.pageNumber << endl << kitap.ID << endl << kitap.shelfNo << endl << kitap.bookStock;
	}
	file1.close();
	return output;
}
int book::sayaca() {
	int degere = 0;
	string bos;
	int sayaca = 0;
	ifstream dosya("book.txt");
	if (dosya.is_open()) {
		while (!dosya.eof()) {
			dosya >> bos;
			if (sayaca % 10 == 0) {
				degere++;

			}
			sayaca++;

		}
		dosya.close();
	}
	return degere;
}



//kitaparrrrrrrrrrrrrrrraaaaaaaaaaaaaaaaaa
void book::kitapAra() {
	system("cls");
	string userInput;
	cout << "\n\t\t\t*             KITAP ARAMA             *" << endl;
	char secim;
	cout << "\t\t=============================================" << endl;
	cout << "\t\t [1] -  Kitap adini gir     " << endl;
	cout << "\t\t---------------------------------------------" << endl;
	cout << "\t\t [2] -  Menu                " << endl;
	cout << "\t\t=============================================" << endl;
label_secim:
	cout << "\t\tsecim : ";
	cin >> secim;
	switch (secim)
	{
	case '1':
		cout << "\t\tAramak istediginiz kitap : ";

		cin >> userInput;

		searchBook(userInput);
		break;
	case '2':
		cout << "\t\tmenuye donluluyor...";
		Sleep(500);
		break;
	default:
		cout << "\t\thatali tuslama" << endl;
		goto label_secim;
		Sleep(500);
		break;
	}

	char secenek;
	cout << "\n\t\tMenuye donmek icin herhangi bir tusa basiniz...." << endl;
	cin >> secenek;
}
//algoritmh
void book::searchBook(const string& userInput) {
	vector<string> books = readBooks();
	DFA dfa(userInput);

	//devam edilecek

	bool found = false;

	for (size_t i = 0; i < books.size(); i += 10) {
		string bookName = books[i];
		string bookNameLowerCase = bookName;
		transform(bookNameLowerCase.begin(), bookNameLowerCase.end(), bookNameLowerCase.begin(), ::tolower);

		if (bookNameLowerCase.find(userInput) != string::npos) {
			cout << "\n\n\t\t * " << bookName << " * " << endl;
			cout << "\t\t=============================================" << endl;

			// Eþleþen kitap adýnýn bulunduðu ilk 10 satýrý yazdýr
			for (size_t j = i; j < i + 10; ++j) {
				cout << "\t\t - " << books[j] << endl;
			}
			cout << "\t\t=============================================" << endl;

			cout << endl;
			found = true;
		}
	}

	if (!found) {
		cout << "Kitap Bulunamadi." << endl;
	}
}

vector<string> book::readBooks() {
	vector<string> books;
	ifstream file("book.txt");

	if (!file.is_open()) {
		cerr << "Dosya acilamadi." << std::endl;
		return books;
	}

	string line;
	while (getline(file, line)) {
		books.push_back(line);
	}

	file.close();
	return books;
}
//***********************
