#pragma once
#include <string>
#include <iostream>
using namespace std;


// User info
struct Date
{
	int year;
	int month;
	int day;
};

struct Address

{
	char number[10];
	char street[20];
	char district[20];
	char city[20];
	char country[20];
};

struct User
{
	char username[50];
	char password[50];
	char name[50];
	Date birthday;
	char ID[10];
	Address curAddress;
	char gender[7];
	int status;
	int type;
	//1 manager //2 executive
};

struct Reader
{
	char readerID[10];
	char name[50];
	char ID[50];
	Date birthday;
	char gender[7];
	char email[50];
	Address curAddress;
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