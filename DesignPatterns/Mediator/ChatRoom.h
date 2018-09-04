#pragma once

#include "User.h"
#include <string>

struct ChatRoom
{
	static void showMessage(User *user, const std::string &message);
};