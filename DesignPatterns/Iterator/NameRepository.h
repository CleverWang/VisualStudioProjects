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

	// ͨ�� Container �̳�
	virtual Iterator * getIterator() override;

private:
	// Ƕ���ࣨ�����ڲ��࣬���ǲ��ᴫ��������ָ�룬���߶�����
	class NameIterator;
};

class NameRepository::NameIterator : public Iterator
{
public:
	NameIterator(NameRepository *nr) : index(0), nameRepo(nr) {}
	~NameIterator() = default;

	// ͨ�� Iterator �̳�
	virtual bool hasNext() override;
	virtual void * next() override;

private:
	size_t index;
	NameRepository *nameRepo;
};