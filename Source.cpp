#define _CRT_SECURE_NO_WARNINGS
#include "Library.h"

//Utility function

bool login(User user, char* argv[], char* filename,bool& isAdmin)
{
	FILE* f1 = fopen(filename, "rb");
	if (f1 == NULL)
		return false;
	if (strcmp(argv[1], "admin") == 0 && strcmp(argv[2], "admin") == 0)
	{
		isAdmin = true;
		return true;
	}
	fseek(f1, 0, SEEK_END);
	int size = ftell(f1);
	int n = size / sizeof(User);
	// Tim ra so luong nguoi dung can phai doc 
	rewind(f1);
	for (int i = 0; i < n; i++)
	{
		fread(&user, sizeof(User), 1, f1);
		if (strcmp(argv[1], user.username) == 0 && strcmp(argv[2], user.password) == 0)
		{
			fclose(f1);
			return true;
		}
			
	}
	fclose(f1);
	return false;
}

bool isLeapY(int n)
{
	if (n % 4 == 0 && n % 400 == 0)
		return true;
	else if (n % 4 == 0 && n % 100 != 0)
		return true;
	return false;
}

void inputDate(Date date)
{
	int maxday = 0;
	cout << "Nhap vao nam:";
	cin >> date.year;
	cout << "Nhap vao thang:";
	cin >> date.month;
	if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7||
		date.month == 8 || date.month == 10|| date.month == 12)
	{
		maxday = 31;
		do
		{
			cout << "Nhap vao ngay:";
			cin >> date.day;
		} while (date.day > maxday || date.day < 0);

	}
	else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
	{
		maxday = 30;
		do
		{
			cout << "Nhap vao ngay:";
			cin >> date.day;
		} while (date.day > maxday || date.day < 0);
	}
	else if (date.month == 2)
	{
		if (isLeapY(date.year) == true)
		{
			maxday = 29;
			do
			{
				cout << "Nhap vao ngay:";
				cin >> date.day;
			} while (date.day > maxday || date.day < 0);
		}
		else
			maxday = 28;
		do
		{
			cout << "Nhap vao ngay:";
			cin >> date.day;
		} while (date.day > maxday || date.day < 0);
	}			
}

void newLogin(User user)
{
	cout << "Nhap vao username:";
	cin.get(user.username,50);
	cin.ignore();
	cout << "Nhap vao password:";
	cin.get(user.password, 50);
	cin.ignore();
}

bool checkAvailability(User user, char* filename)
{
	User temp;
	FILE* f1 = fopen(filename, "rb");
	if (f1 == NULL)
		return;
	fread(&temp, sizeof(User), 1, f1);
	fseek(f1, 0, SEEK_END);
	int size = ftell(f1);
	rewind(f1);
	for (int i = 0; i < size; i++)
	{
		if (strcmp(temp.username, user.username) == 0)
		{
			fclose(f1);
			return false;
		}
	}
	fclose(f1);	
	return true;
}

//Function 1
void changePassword(User user, char* filename)
{
	int k = 0;
	char curPas[50];
	User temp;
	cout << "Nhap vao mat khau hien tai:";
	cin.get(curPas, 50);
	if (strcmp(curPas, user.password) == 0)
	{
		FILE* f1 = fopen(filename, "wb+");
		fseek(f1, 0, SEEK_END);
		int size = ftell(f1);
		int n = size / sizeof(User);
		rewind(f1);
		for (int i = 0; i < n; i++)
		{
			fread(&temp, sizeof(User), 1, f1);
				if (strcmp(temp.username, user.username) == 0)
				{
					k = ftell(f1);
					break;
				}
		}
		fseek(f1, k - sizeof(User), SEEK_SET);
		strcpy(user.password, temp.password);
		fclose(f1);
	}
	cout << "Nhap sai mat khau cu:";
	return;	
}

void addUser(User user, char* filename)
{

}
	

void main(int argc, char** argv)
{
	bool isAdmin;
	User user;
	Reader reader;
	Book book;
	Card card;

}