#pragma once

#include "Container.h"
#include "Iterator.h"
#include <string>
#include <vector>

class NameRepository : public Container
{
public:
	NameRepository() = default;
	~NameRepository() = default;

	std::vector<std::string> names{ "Robert" , "John" ,"Julie" , "Lora" };

	// 通过 Container 继承
	virtual Iterator * getIterator() override;

private:
	// 嵌套类（类似内部类，但是不会传入外层类的指针，两者独立）
	class NameIterator;
};

class NameRepository::NameIterator : public Iterator
{
public:
	NameIterator(NameRepository *nr) : index(0), nameRepo(nr) {}
	~NameIterator() = default;

	// 通过 Iterator 继承
	virtual bool hasNext() override;
	virtual void * next() override;

private:
	size_t index;
	NameRepository *nameRepo;
};