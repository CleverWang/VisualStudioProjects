#pragma once

#include "Student.h"
#include "StudentView.h"

class StudentController
{
public:
	StudentController(Student *m, StudentView *v) : model(m), view(v) {}
	~StudentController() = default;

	void setStudentName(const std::string &name);
	std::string getStudentName() const;
	void setStudentRollNo(const std::string &rollNo);
	std::string getStudentRollNo() const;
	void updateView();

private:
	Student * model;
	StudentView * view;
};