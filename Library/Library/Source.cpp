#include "Library.h"



void main(int argc, char* argv[])
{
	bool isAdmin = false;
	User user;
	Reader reader;
	Book book;
	Card card;
	//if (login(user, argv, "user.bin", isAdmin) == true)
	//{
	//	cout << "Ok";
	//	cout << isAdmin;
	//}
	//else cout << "Fuck this shit I'm out";
	addUser(user, "user.bin");
}