#include "Student.h"
#include "StudentController.h"
#include "StudentView.h"

Student *retriveStudentFromDatabase() {
	Student *student = new Student();
	student->setName("Robert");
	student->setRollNo("10");
	return student;
}


int main(int argc, char **argv)
{
	//�����ݿ��ȡѧ����¼
	Student *model = retriveStudentFromDatabase();

	//����һ����ͼ����ѧ����ϸ��Ϣ���������̨
	StudentView *view = new StudentView();

	StudentController *controller = new StudentController(model, view);

	controller->updateView();

	//����ģ������
	controller->setStudentName("John");

	controller->updateView();

	return 0;
}