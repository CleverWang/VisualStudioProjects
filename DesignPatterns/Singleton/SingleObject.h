#pragma once

#include <memory>
#include <mutex>
#include <iostream>

// ����ʽ����ģʽ�������̺߳ܶ������£��Կռ任ʱ�䣩
//class SingleObject
//{
//public:
//	~SingleObject() {}
//	// ��ֹ�����Ŀ���
//	SingleObject(const SingleObject&) = delete;
//	SingleObject &operator=(const SingleObject&) = delete;
//	void showMessage();
//
//	static std::shared_ptr<SingleObject> getInstance();
//
//private:
//	SingleObject() {}
//
//	static std::shared_ptr<SingleObject> instance;
//};
//
//std::shared_ptr<SingleObject> SingleObject::instance = std::shared_ptr<SingleObject>(new SingleObject);
//
//inline std::shared_ptr<SingleObject> SingleObject::getInstance()
//{
//	return instance;
//}
//
//inline void SingleObject::showMessage()
//{
//	std::cout << "Hello world!\n";
//}

// ����ʽ����ģʽ�������̲߳��������£��ӳٶ���Ĵ�������ʱ�任�ռ䣩
class SingleObject
{
private:
	SingleObject() {}

	static std::shared_ptr<SingleObject> instance;

public:
	~SingleObject() {}
	// ��ֹ�����Ŀ���
	SingleObject(const SingleObject&) = delete;
	SingleObject &operator=(const SingleObject&) = delete;
	void showMessage();

	static std::mutex mtx;
	static std::shared_ptr<SingleObject> getInstance();
};

std::mutex SingleObject::mtx;
std::shared_ptr<SingleObject> SingleObject::instance = nullptr;

// ˫�ؼ�鷨��ȡ����
inline std::shared_ptr<SingleObject> SingleObject::getInstance()
{
	if (instance == nullptr)
	{
		mtx.lock();
		if (instance == nullptr)
		{
			instance = std::shared_ptr<SingleObject>(new SingleObject);
		}
		mtx.unlock();
	}
	return instance;
}

inline void SingleObject::showMessage()
{
	std::cout << "Hello world!\n";
}