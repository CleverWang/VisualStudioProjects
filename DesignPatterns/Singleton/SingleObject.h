#pragma once

#include <memory>
#include <mutex>
#include <iostream>

// 饿汉式单例模式（用于线程很多的情况下，以空间换时间）
//class SingleObject
//{
//public:
//	~SingleObject() {}
//	// 阻止单例的拷贝
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

// 懒汉式单例模式（用于线程不多的情况下，延迟对象的创建，以时间换空间）
class SingleObject
{
private:
	SingleObject() {}

	static std::shared_ptr<SingleObject> instance;

public:
	~SingleObject() {}
	// 阻止单例的拷贝
	SingleObject(const SingleObject&) = delete;
	SingleObject &operator=(const SingleObject&) = delete;
	void showMessage();

	static std::mutex mtx;
	static std::shared_ptr<SingleObject> getInstance();
};

std::mutex SingleObject::mtx;
std::shared_ptr<SingleObject> SingleObject::instance = nullptr;

// 双重检查法获取单例
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