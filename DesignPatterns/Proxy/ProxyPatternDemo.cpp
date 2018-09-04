#include "ProxyImage.h"
#include "Image.h"
#include <iostream>

int main(int argc, char **argv)
{
	std::shared_ptr<Image> image = std::make_shared<ProxyImage>("test_10mb.jpg");

	//ͼ�񽫴Ӵ��̼���
	image->display();
	std::cout << std::endl;
	//ͼ���޷��Ӵ��̼��أ��Ӵ�����ֱ�ӻ��
	image->display();

	system("pause");

	return 0;
}