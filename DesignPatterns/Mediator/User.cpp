#include "User.h"

#include "ChatRoom.h"

void User::sendMessage(const std::string & message)
{
	ChatRoom::showMessage(this, message);
}
