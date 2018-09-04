#pragma once

#include <string>
#include <memory>

class Shape
{
public:
	Shape() = default;
	virtual ~Shape() = default;
	// �������캯��
	//Shape(const Shape &rhs) : type(rhs.type), id(rhs.id) {}

	virtual void draw() {};

	std::string getType() { return type; }

	std::string getId() { return id; }

	void setId(const std::string &id) { this->id = id; }

	// ��¡����
	virtual std::shared_ptr<Shape> clone() { return std::make_shared<Shape>(*this); }

protected:
	std::string type;
private:
	std::string id;
};