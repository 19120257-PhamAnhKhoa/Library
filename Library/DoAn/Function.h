#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include<conio.h>
#define BUF_SIZE 1024*10

using namespace std;


// Các struct
struct Date
{
	int year;
	int month;
	int day;
};

struct User
{
	char username[50];
	char password[50];
	char name[50];
	Date birthday;
	char ID[10];
	char address[50];
	char gender[4];
	int status;
	//1 Activated 0 Blocked
	int type;
	//1 Manager 0 Executive
};

struct Reader
{
	char readerID[10];
	char name[50];
	char ID[50];
	Date birthday;
	char gender[7];
	char email[50];
	char address[50];
	Date cardCreate;
	Date cardExpire;
};

struct Book
{
	char ISBN[10];
	char bName[50];
	char author[50];
	char publisher[50];
	Date publishY;
	char genre[10];
	int price;
	int quantity;
};

struct Card
{
	char readerID[10];
	Date borrowTime;
	Date expectReturn;
	Date actualReturn;
	int number;
	bool late;
	bool lost;
};

//Các định nghĩa hàm

bool login(User& user, const char* filename, bool& isAdmin,
	bool& isManager, bool& isExecutive, char curUser[], char curPass[]);

bool execLib(char* argv[]);

bool isLeapY(int n);

void inputDate(Date& date);

void newLogin(User& user);

bool checkAvailability(User user, const char* filename);

void changePassword(User& user, const char* filename);

void updateInfo(User& user, const char* filename, char curUser[], char curPass[]);

void showInfo(User user, const char* filename, char curUser[], char Pass[]);

void generalInfo(User& user);

void addUser(User& user, const char* filename);

void showList(User user, const char* filename);

void typeUser(User& user, const char* filename, int index);

bool checkReader(Reader reader, const char* filename);

void newReader(Reader& reader);

void listReader(Reader& reader, const char* filename);

void readerInfo(Reader& reader);

void CopyFile(const char* filename1, const char* filename2);

void addReader(Reader& reader, const char* filename);

void updateReaderInfo(Reader& reader, const char* filename, int index);

void deleteReader(Reader& reader, const char* filename1, const char* filename2, int index);

void pass(char mk[]);
