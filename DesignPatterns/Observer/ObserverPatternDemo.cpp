#include "Subject.h"
#include "BinaryObserver.h"
#include "OctalObserver.h"
#include "HexaObserver.h"
#include <iostream>

int main(int argc, char **argv)
{
	Subject subject;

	BinaryObserver bo(&subject);
	OctalObserver oo(&subject);
	HexaObserver ho(&subject);

	std::cout << "First state change: 15" << std::endl;
	subject.setState(15);
	std::cout << "Second state change: 10" << std::endl;
	subject.setState(10);


	system("pause");

	return 0;
}