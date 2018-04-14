#include "global.h"

void err_msg(initializer_list<string> il)
{
	for (const auto &ele : il)
		cout << ele << " ";
	cout << endl;
}