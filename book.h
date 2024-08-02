#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

class book
{
private:
	
	
	string bookName;
	string author;
	string publisher;
	string kind;
	string language;
	int year;
	int bookStock;
	int pageNumber;
	long int ID;
	int shelfNo;
public:
	book();
	book(string _bookName);
	book(string _bookName, string _author, string _publisher, string _kind, string _language, int _year, int _bookStock, int _pageNumber, long int _ID, int _shelfNo);
	~book();
	vector<string> readBooks();
	void searchBook(const string& userInput);
	string getFormattedDate();
	void kitapCikar();
	void kitapYazdir();
	void kitapAra();
	void kitapGuncelle();
	void newAdded(int degere);
	void kitapAl(string _username);
	
	int sayaca();
	void setBookName(string _bookName);
	string getBookName();

	void setAuthor(string _author);
	string getAuthor();

	void setPublisher(string _publisher);
	string getPublisher();

	void setKind(string _kind);
	string getKind();

	void setPageNumber(int _pageNumber);
	int getPageNumber();

	void setID(int long _ID);
	long int getID();
	friend istream& operator>>(std::istream& input, book& kitap);
	friend ostream& operator<<(std::ostream& output, const book& kitap);

	
};