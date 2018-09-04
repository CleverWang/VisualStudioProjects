#include "StudentController.h"

void StudentController::setStudentName(const std::string & name)
{
	model->setName(name);
}

std::string StudentController::getStudentName() const
{
	return model->getName();
}

void StudentController::setStudentRollNo(const std::string & rollNo)
{
	model->setRollNo(rollNo);
}

std::string StudentController::getStudentRollNo() const
{
	return model->getRollNo();
}

void StudentController::updateView()
{
	view->printStudentDetails(model->getRollNo(), model->getName());
}
