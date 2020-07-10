﻿#include"Function.h"

//Utility functions for projects and Function 1

bool execLib(char* argv[])
{
	if (_stricmp(argv[1], "open") == 0)
	{
		cout << "-----Phan mem quan ly thu vien-----" << endl;
		return true;
	}
	cout << "Vui long mo lai command prompt va nhap vao 'Open' hoac 'open' de vao app" << endl;
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
	do
	{
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
	} while (date.month > 12 || date.month < 1);
}

void newLogin(User& user)
{
	cout << "Nhap vao username:";
	cin.get(user.username, 50);
	cin.ignore();
	char temp[50];
	do
	{
		cout << "Nhap vao password:";
		pass(user.password);
		cout << "Nhap lai password:";
		pass(temp);
	} while (strcmp(user.password, temp) != 0);
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

void generalInfo(User& user)
{
	cout << "Nhap vao ho va ten:";
	cin.get(user.name, 50);
	cin.ignore();
	cout << "Nhap vao ngay sinh:" << endl;
	inputDate(user.birthday);
	cin.ignore();
	cout << "Nhap vao CMND:";
	cin.get(user.ID, 10);
	cin.ignore();
	cout << "Nhap vao dia chi:";
	cin.get(user.address, 50);
	cin.ignore();
	cout << "Nhap vao gioi tinh (Nam/Nu):";
	cin.get(user.gender, 7);
	cin.ignore();
	do
	{
		cout << "Nhap vao tinh trang (1:Activated,0:Blocked):";
		cin >> user.status;
	} while (user.status != 1 && user.status != 0);
	do
	{
		cout << "Nhap vao chuc vu (1:Manager,0:Executive):";
		cin >> user.type;
	} while (user.type != 1 && user.type != 0);
}

void pass(char mk[])
{
	char x;
	int size = 0;
	x = _getch();
	while (x != 13)
	{
		if (x == 8 && size > 0)
		{
			mk[size] = '\0';
			size--;
			cout << "\b \b";
		}
		else if (x == 8 && size == 0)
		{
			x = _getch();
			continue;
		}
		else
		{
			cout << x;
			cout << "\b \b*";
			mk[size] = x;
			size++;
		}
		x = _getch();

	}
	mk[size] = '\0';
	cout << endl;
}


//Function 1

//Function 1.1 Login
bool login(User& user, const char* filename, bool& isAdmin,
	bool& isManager, bool& isExecutive, char curUser[], char curPass[])
{
	cout << "Username:";
	cin.get(curUser, 50);
	cin.ignore();
	cout << "Password:";
	pass(curPass);
	if (strcmp("admin", curUser) == 0 && strcmp("admin", curPass) == 0)
	{
		isAdmin = true;
		return true;
	}
	FILE* f1 = fopen(filename, "rb");
	if (f1 == NULL)
		return false;
	fseek(f1, 0, SEEK_END);
	int n = ftell(f1) / sizeof(User);
	// Tim ra so luong nguoi dung can phai doc 
	rewind(f1);
	for (int i = 0; i < n; i++)
	{
		fread(&user, sizeof(User), 1, f1);
		if (strcmp(curUser, user.username) == 0 && strcmp(curPass, user.password) == 0)
		{
			if (user.type == 1)
				isManager = true;
			else
				isExecutive = true;
			fclose(f1);
			return true;
		}
	}
	fclose(f1);
	return false;
}

//Function 1.2 Logout không cần hàm vì chỉ cần thoát ra lại màn hình menu chính

//Function 1.3 change password
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
	fclose(f1);
}

//Function 1.4 update info & show info

void updateInfo(User& user, const char* filename, char curUser[], char curPass[])
{
	int k = 0;
	FILE* f1 = fopen(filename, "rb+");
	if (f1 == NULL)
		return;
	fseek(f1, 0, SEEK_END);
	int n = ftell(f1) / sizeof(User);
	rewind(f1);
	for (int i = 0; i < n; i++)
	{
		fread(&user, sizeof(User), 1, f1);
		if (strcmp(user.username, curUser) == 0 && strcmp(user.password, curPass) == 0)
		{
			cout << "Cap nhat lai thong tin cua ban than:" << endl;
			generalInfo(user);
			k = ftell(f1);
			break;
		}
	}
	rewind(f1);
	fseek(f1, k - sizeof(User), SEEK_SET);
	fwrite(&user, sizeof(User), 1, f1);
	fclose(f1);
}

void showInfo(User user, const char* filename, char curUser[], char Pass[])
{
	cout << "Ho va ten:" << user.name << endl;
	cout << "Ngay sinh:" << user.birthday.day << "/" << user.birthday.month
		<< "/" << user.birthday.year << endl;
	cout << "CMND:" << user.ID << endl;
	cout << "Dia chi:" << user.address << endl;
	cout << "Gioi tinh:" << user.gender << endl;
	cout << "Tinh trang:";
	if (user.status == 0)
		cout << "Blocked" << endl;
	else
		cout << "Activated" << endl;
	cout << "Chuc vu:";
	if (user.type == 0)
		cout << "Executive" << endl;
	else
		cout << "Manager" << endl;

}

//Function 1.5 add users

void addUser(User& user, const char* filename)
{
	FILE* f1 = fopen(filename, "rb+");
	if (f1 == NULL)
	{
		FILE* f1 = fopen(filename, "wb");
		fclose(f1);
		addUser(user, filename);
		return;
	}
	//Mở file ở dạng wb để tạo file nếu chưa có thì gọi lại 
	//hàm addUser mở ở dạng rb+ để đọc ghi
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

//Function 1.6 define type of user

void showList(User user, const char* filename)
{
	FILE* f1 = fopen(filename, "rb");
	if (f1 == NULL)
		return;
	fseek(f1, 0, SEEK_END);
	int n = ftell(f1) / sizeof(User);
	rewind(f1);
	for (int i = 0; i < n; i++)
	{
		fread(&user, sizeof(User), 1, f1);
		cout << "User no." << i + 1 << ":" << endl;
		cout << "Username:" << user.username << endl;
		cout << "Chuc vu hien tai cua nguoi dung:";
		if (user.type == 1)
			cout << "Manager" << endl;
		else
			cout << "Executive" << endl;
		cout << "-------------------------------------------" << endl;
	}
	fclose(f1);
}

void typeUser(User& user, const char* filename, int index)
{
	index--;
	FILE* f1 = fopen(filename, "rb+");
	if (f1 == NULL)
		return;
	int k = 0;
	fseek(f1, 0, SEEK_END);
	int n = ftell(f1) / sizeof(User);
	rewind(f1);
	for (int i = 0; i < n; i++)
	{
		fread(&user, sizeof(User), 1, f1);
		if (i == index)
		{
			cout << "Cap nhat chuc nang cua nguoi dung:" << endl;
			cout << "Nhap vao 1:Manager" << endl;
			cout << "Nhap vao 0:Executive" << endl;
			cin >> user.type;
			k = ftell(f1);
			break;
		}
	}
	rewind(f1);
	fseek(f1, k - sizeof(User), SEEK_SET);
	fwrite(&user, sizeof(User), 1, f1);
	fclose(f1);
}

//Utility functions for Function 2

bool checkReader(Reader reader, const char* filename)
{
	Reader temp;
	FILE* f1 = fopen(filename, "rb");
	if (f1 == NULL)
	{
		return 0;
	}
	fseek(f1, 0, SEEK_END);
	int n = ftell(f1) / sizeof(Reader);
	rewind(f1);
	for (int i = 0; i < n; i++)
	{
		fread(&temp, sizeof(Reader), 1, f1);
		if (strcmp(temp.readerID, reader.readerID) == 0)
		{
			fclose(f1);
			return false;
		}
	}
	fclose(f1);
	return true;
}

void newReader(Reader& reader)
{
	cout << "Nhap vao ma doc gia:";
	cin.get(reader.readerID, 10);
	cin.ignore();
}

void readerInfo(Reader& reader)
{
	cout << "Nhap vao ho va ten:";
	cin.get(reader.name, 50);
	cin.ignore();
	cout << "Nhap vao CMND:";
	cin.get(reader.ID, 10);
	cin.ignore();
	cout << "Nhap vao ngay sinh:" << endl;
	inputDate(reader.birthday);
	cout << "Nhap vao gioi tinh:";
	cin.ignore();
	cin.get(reader.gender, 7);
	cin.ignore();
	cout << "Nhap vao email:";
	cin.get(reader.email, 50);
	cin.ignore();
	cout << "Nhap vao dia chi:";
	cin.get(reader.address, 50);
	cin.ignore();
	cout << "Nhap vao ngay lap the" << endl;
	inputDate(reader.cardCreate);
	cin.ignore();
	cout << "Ngay the het han:" << endl;
	reader.cardExpire = reader.cardCreate;
	reader.cardExpire.year = reader.cardCreate.year + 4;
	cout << reader.cardExpire.day << "/" << reader.cardExpire.month
		<< "/" << reader.cardExpire.year << endl;
}

void CopyFile(const char* filename1, const char* filename2)
{
	FILE* f1 = fopen(filename1, "rb");
	if (f1 == NULL)
		return;
	FILE* f2 = fopen(filename2, "wb");
	if (f2 == NULL)
		return;
	char buf[BUF_SIZE];
	int count;
	do
	{
		count = fread(buf, 1, BUF_SIZE, f1);
		fwrite(buf, 1, count, f2);
	} while (count == BUF_SIZE);
}
//Hàm copy file từ file temp.bin sang reader.bin để xóa phần tử cuối

void moveRBottom(Reader& reader, const char* filename, int index)
{
	int k = 0;
	index--;
	Reader temp;
	FILE* f1 = fopen(filename, "rb+");
	if (f1 == NULL)
		return;
	fseek(f1, 0, SEEK_END);
	int n = ftell(f1) / sizeof(Reader);
	rewind(f1);
	for (int i = 0; i < n; i++)
	{
		fread(&reader, sizeof(Reader), 1, f1);
		if (i == index)
		{
			temp = reader;
			cout << temp.name << endl;
			k = ftell(f1);
			for (int j = i; j < n - 1; j++)
			{
				fread(&reader, sizeof(Reader), 1, f1);
				rewind(f1);
				fseek(f1, k - sizeof(Reader), SEEK_SET);
				fwrite(&reader, sizeof(Reader), 1, f1);
				k = ftell(f1) + sizeof(Reader);
				rewind(f1);
				fseek(f1, k, SEEK_SET);
			}
			fseek(f1, k - sizeof(Reader), SEEK_SET);
			fwrite(&temp, sizeof(Reader), 1, f1);
			break;
		}
	}
	fclose(f1);
}
//Hàm chuyển phần tử cần xóa xuống cuối để có thể dễ dàng xóa 


//Function 2

//Function 2.1 list of readers

void listReader(Reader& reader, const char* filename)
{
	FILE* f1 = fopen(filename, "rb");
	if (f1 == NULL)
		return;
	fseek(f1, 0, SEEK_END);
	int n = ftell(f1) / sizeof(Reader);
	rewind(f1);
	for (int i = 0; i < n; i++)
	{
		cout << "Reader no." << i + 1 << endl;
		fread(&reader, sizeof(Reader), 1, f1);
		cout << "Ma doc gia:" << reader.readerID << endl;
		cout << "Ho va ten:" << reader.name << endl;
		cout << "CMND:" << reader.ID << endl;
		cout << "Ngay sinh:" << reader.birthday.day << "/" << reader.birthday.month
			<< "/" << reader.birthday.year << endl;
		cout << "Gioi tinh:" << reader.gender << endl;
		cout << "Email:" << reader.email << endl;
		cout << "Dia chi:" << reader.address << endl;
		cout << "Ngay mo the:" << reader.cardCreate.day << "/" << reader.cardCreate.month
			<< "/" << reader.cardCreate.year << endl;
		cout << "Ngay het han:" << reader.cardExpire.day << "/" << reader.cardExpire.month
			<< "/" << reader.cardExpire.year << endl;
		cout << "-------------------------------------------" << endl;
	}
	fclose(f1);
}

//Function 2.2 add reader

void addReader(Reader& reader, const char* filename)
{
	FILE* f1 = fopen(filename, "rb+");
	if (f1 == NULL)
	{
		FILE* f1 = fopen(filename, "wb");
		fclose(f1);
		addReader(reader, filename);
		return;
	}
	fseek(f1, 0, SEEK_END);
	newReader(reader);
	if (checkReader(reader, filename) == false)
	{
		cout << "Ma so doc gia da bi lay vui long nhap ma so moi" << endl;
		return;
	}
	readerInfo(reader);
	fseek(f1, 0, SEEK_END);
	fwrite(&reader, sizeof(Reader), 1, f1);
	fclose(f1);
}

//Function 2.3 update reader info

void updateReaderInfo(Reader& reader, const char* filename, int index)
{
	int k = 0;
	index--;
	FILE* f1 = fopen(filename, "rb+");
	if (f1 == NULL)
		return;
	fseek(f1, 0, SEEK_END);
	int n = ftell(f1) / sizeof(Reader);
	rewind(f1);
	for (int i = 0; i < n; i++)
	{
		fread(&reader, sizeof(Reader), 1, f1);
		if (i == index)
		{
			cout << "Cap nhat thong tin cua doc gia:" << endl;
			readerInfo(reader);
			k = ftell(f1);
			break;
		}
	}
	rewind(f1);
	fseek(f1, k - sizeof(Reader), SEEK_SET);
	fwrite(&reader, sizeof(Reader), 1, f1);
	fclose(f1);
}

//Function 2.4 delete reader info

void deleteReader(Reader& reader, const char* filename1, const char* filename2, int index)
{
	moveRBottom(reader, filename1, index);
	int k = 0;
	FILE* f1 = fopen(filename1, "rb+");
	if (f1 == NULL)
		return;
	FILE* f2 = fopen(filename2, "wb");
	if (f2 == NULL)
		return;
	fseek(f1, 0, SEEK_END);
	int n = ftell(f1) / sizeof(Reader);
	rewind(f1);
	for (int i = 0; i < n - 1; i++)
	{
		fread(&reader, sizeof(Reader), 1, f1);
		fwrite(&reader, sizeof(Reader), 1, f2);
	}
	fclose(f1);
	fclose(f2);
	CopyFile(filename2, filename1);
	fclose(f1);
	fclose(f2);
}