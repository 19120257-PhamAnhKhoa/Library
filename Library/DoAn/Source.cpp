﻿#include "Function.h"

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
	char curID[10];
	char curName[50];
	//execLib(argv);
	if (login(user, "user.bin", isAdmin, isMng, isExec, curUser, curPass) == 0)
		cout << "Try harder";
	else
	{
		/*showInfo(user, "user.bin", curUser, curPass);*/
		//changePassword(user, "user.bin");
		/*updateInfo(user, "user.bin", curUser, curPass);*/
		//addReader(reader, "reader.bin")ấ;
		//listReader(reader, "reader.bin");
		//cout << "Nhap vao CMND can tim :";
		//cin.get(curID, 10);
		//cin.ignore();
		//findReaderID(reader, "reader.bin", curID);
		//cout << "Nhap vao ten can tim :";
		//cin.get(curName, 50);
		//cin.ignore();
		//findReaderName(reader, "reader.bin", curName);
		//cout << "Nhap vao STT cua doc gia can thay doi thong tin:";
		//cin >> index;
		//cin.ignore();
		//deleteReader(reader, "reader.bin", "temp.bin", index);
		//updateReaderInfo(reader, "reader.bin", index);
		//cout << "Cap nhat thong tin doc gia thanh cong" << endl;
		//listReader(reader, "reader.bin");
		//showList(user, "user.bin");
		//cout << "Nhap vao STT cua user can thay doi chuc vu:";
		//cin >> index;
		//typeUser(user, "user.bin", index);
		//cout << "Cap nhat chuc vu nguoi dung thanh cong:" << endl;
		//showList(user, "user.bin");
		////addUser(user, "user.bin");
		//showInfo(user, "user.bin", curUser, curPass);
		//updateInfo(user, "user.bin", curUser, curPass);
		//showBookList("book.bin");
		//index = 3;
		//strcpy(book.bName, "CNTT");
		//strcpy(book.ISBN, "123");
		//findAndShowBookInfo("book.bin", book.ISBN, book.bName, index);
		//addBook(book, "book.bin");
		//listReader(reader, "reader.bin");
		//showBookList("book.bin");
		//showCardList(card, "card.bin");
		//createBorrowCard(card, "reader.bin", "book.bin", "card.bin");
		//showBookList("book.bin");
		//showCardList(card, "card.bin");
		//createReturnCard(card, "reader.bin", "book.bin", "card.bin");
		//showBookList("book.bin");
		showBookList("book.bin");
		statisticOfBook("book.bin");
		statisticOfGenre("book.bin");
		statisticOfReader("reader.bin");
		statisticOfReaderGender("reader.bin");
		statisticOfBorrowedBook("book.bin");
	}
}