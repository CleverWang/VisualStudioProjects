#include "ProxyImage.h"
#include "Image.h"
#include <iostream>

int main(int argc, char **argv)
{
	std::shared_ptr<Image> image = std::make_shared<ProxyImage>("test_10mb.jpg");

	//图像将从磁盘加载
	image->display();
	std::cout << std::endl;
	//图像将无法从磁盘加载，从代理中直接获得
	image->display();

	system("pause");

	return 0;
}