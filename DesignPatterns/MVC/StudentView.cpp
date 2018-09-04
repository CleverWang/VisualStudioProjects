#include "StudentView.h"
#include <iostream>

void StudentView::printStudentDetails(const std::string & rollNo, const std::string & name) const
{
	std::cout << "Student: \n";
	std::cout << "Roll No: " << rollNo << std::endl;
	std::cout << "Name: " << name << std::endl;
}
