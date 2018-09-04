#include "NameRepository.h"
#include "Iterator.h"
#include <iostream>

int main(int argc, char **argv)
{
	NameRepository *namesRepository = new NameRepository();
	
	Iterator *iter = nullptr;
	for (iter = namesRepository->getIterator(); iter->hasNext();)
	{
		std::string name(*static_cast<std::string *>(iter->next()));
		std::cout << "Name : " + name << std::endl;
	}

	delete iter;
	delete namesRepository;

	return 0;
}