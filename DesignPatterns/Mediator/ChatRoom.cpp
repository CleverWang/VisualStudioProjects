#include "ChatRoom.h"
#include <ctime>
#include <iostream>

void ChatRoom::showMessage(User * user, const std::string & message)
{
	time_t now = time(NULL);
	char buff[30];
	ctime_s(buff, 30, &now);
	char *returnChar = strchr(buff, '\n');
	*returnChar = '\0';
	std::cout << buff << " [" << user->getName() << "] : " << message << std::endl;
}
