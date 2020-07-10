#include "Function.h"

void main(int argc, char* argv[])
{
	int index;
	bool isAdmin = false, isMng = false, isExec = false;
	User user;
	Reader reader;
	Book book;
	Card card;
	char curUser[50];
	char curPass[50];
	execLib(argv);
	if (login(user, "user.bin", isAdmin, isMng, isExec, curUser, curPass) == 0)
		cout << "Try harder";
	else
	{
		//addReader(reader, "reader.bin");
		listReader(reader, "reader.bin");
		cout << "Nhap vao STT cua doc gia can thay doi thong tin:";
		cin >> index;
		cin.ignore();
		deleteReader(reader, "reader.bin", "temp.bin", index);
		//updateReaderInfo(reader, "reader.bin", index);
		//cout << "Cap nhat thong tin doc gia thanh cong" << endl;
		listReader(reader, "reader.bin");
		//showList(user, "user.bin");
		//cout << "Nhap vao STT cua user can thay doi chuc vu:";
		//cin >> index;
		//typeUser(user, "user.bin", index);
		//cout << "Cap nhat chuc vu nguoi dung thanh cong:" << endl;
		//showList(user, "user.bin");
		////addUser(user, "user.bin");
		//showInfo(user, "user.bin", curUser, curPass);
		//updateInfo(user, "user.bin", curUser, curPass);

	}
}