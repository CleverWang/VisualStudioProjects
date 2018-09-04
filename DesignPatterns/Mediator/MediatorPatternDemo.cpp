#include "User.h"

int main(int argc, char **argv)
{
	User *robert = new User("Robert");
	User *john = new User("John");

	robert->sendMessage("Hi! John!");
	john->sendMessage("Hello! Robert!");

	delete robert;
	delete john;

	return 0;
}