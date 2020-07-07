#include"Library.h"

bool login(User& user, char* argv[], const char* filename, bool& isAdmin)
{

	FILE* f1 = fopen(filename, "rb");
	if (f1 == NULL)
		return 0;
	if (strcmp(argv[1], "admin") == 0 && strcmp(argv[2], "admin") == 0)
	{
		isAdmin = true;
		return true;
	}
	fseek(f1, 0, SEEK_END);
	int n = ftell(f1) / sizeof(User);
	// Tim ra so luong nguoi dung can phai doc 
	rewind(f1);
	for (int i = 0; i < n; i++)
	{
		fread(&user, sizeof(User), 1, f1);
		if (strcmp(argv[1], user.username) == 0 && strcmp(argv[2], user.password) == 0)
		{
			return true;
		}

	}
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

void inputDate(Date& date)
{
	int maxday = 0;
	cout << "Nhap vao nam:";
	cin >> date.year;
	cout << "Nhap vao thang:";
	cin >> date.month;
	if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 ||
		date.month == 8 || date.month == 10 || date.month == 12)
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
		{
			maxday = 28;
			do
			{
				cout << "Nhap vao ngay:";
				cin >> date.day;
			} while (date.day > maxday || date.day < 0);
		}
	}
}

void newLogin(User& user)
{
	cout << "Nhap vao username:";
	cin.get(user.username, 50);
	cin.ignore();
	char pass[50];
	do
	{
		cout << "Nhap vao password:";
		cin.get(user.password, 50);
		cin.ignore();
		cout << "Nhap lai password:";
		cin.get(pass, 50);
		cin.ignore();
	}
	while (strcmp(user.password, pass) != 0);
}

bool checkAvailability(User user, const char* filename)
{
	User temp;
	FILE* f1 = fopen(filename, "rb");
	if (f1 == NULL)
	{
		cout << 1;
		return 0;
	}

	fseek(f1, 0, SEEK_END);
	int n = ftell(f1) / sizeof(User);
	rewind(f1);
	for (int i = 0; i < n; i++)
	{
		fread(&temp, sizeof(User), 1, f1);
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
void changePassword(User& user, const char* filename)
{
	User temp;
	FILE* f1 = fopen(filename, "rb+");
	if (f1 == NULL)
		return;
	int k = 0;
	char curPas[50];
	char newPas[50];
	bool correct = false;
	do
	{
		cout << "Nhap vao mat khau hien tai:";
		cin.get(curPas, 50);
		cin.ignore();
		fseek(f1, 0, SEEK_END);
		int n = ftell(f1) / sizeof(User);
		rewind(f1);
		for (int i = 0; i < n; i++)
		{
			fread(&user, sizeof(User), 1, f1);
			if (strcmp(curPas, user.password) == 0)
			{
				k = ftell(f1);
				temp = user;
				correct = true;
				break;
			}
		}
	} while (correct == false);
	cout << "Nhap mat khau moi:";
	cin.get(newPas, 50);
	strcpy(temp.password, newPas);
	fseek(f1, k - sizeof(User), SEEK_SET);
	fwrite(&temp, sizeof(User), 1, f1);
}

void generalInfo(User& user)
{
	cout << "Nhap vao ho va ten:";
	cin.get(user.name, 50);
	cin.ignore();
	cout << "Nhap vao ngay sinh:" << endl;
	inputDate(user.birthday);
	cin.ignore();
	cout << "Nhap vao ID:";
	cin.get(user.ID, 10);
	cin.ignore();
	cout << "Nhap vao dia chi:";
	cin.get(user.address, 50);
	cin.ignore();
	cout << "Nhap vao gioi tinh:";
	cin.get(user.gender, 7);
	cin.ignore();
	do
	{
		cout << "Nhap vao tinh trang (1:Activated;0:Blocked):";
		cin >> user.status;
	} while (user.status != 1 && user.status != 0);
	do
	{
		cout << "Nhap vao chuc vu (1:Manager;2:Executive):";
		cin >> user.type;
	} while (user.type != 1 && user.type != 2);
}

void addUser(User& user, const char* filename)
{
	FILE* f1 = fopen(filename, "rb+");
	if (f1 == NULL)
		return;
	fseek(f1, 0, SEEK_END);
	newLogin(user);
	if (checkAvailability(user, filename) == false)
	{
		cout << "Tai khoan da ton tai";
		return;
	}
	generalInfo(user);
	fseek(f1, 0, SEEK_END);
	fwrite(&user, sizeof(User), 1, f1);
	fclose(f1);
}

void updateInfo(User& user, const char* filename)
{
	return;
}