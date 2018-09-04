#include "SingleObject.h"

int main(int argc, char **argv)
{
	std::shared_ptr<SingleObject> object = SingleObject::getInstance();
	object->showMessage();

	system("pause");

	return 0;
}