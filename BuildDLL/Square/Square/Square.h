#pragma once
#include "framework.h"
#include <sstream>
#include <iomanip>
#include <iostream>

class Square;

class Object
{
	virtual std::string toString() = 0;
};

class Shape : public Object
{
public:
	virtual float Area() = 0;
	virtual float Perimeter() = 0;

	static bool AscendingByArea(std::shared_ptr<Shape>, std::shared_ptr<Shape>);

	std::string toString();
};

class ShapeParser : public Object
{
public:
	virtual Shape* parse(std::string data) = 0;

	virtual std::string toString();
};

class ShapePrintingStrategy : public Object
{
public:
	virtual void printData(Shape* shape) = 0;
	virtual void printTable(Shape* shape) = 0;

	virtual std::string toString();
};

class Square : public Shape
{
private:
	float _a;
public:
	Square(float a);

	float Area();
	float Perimeter();

	float getEdge();

	std::string toString();
};

class SquareParser : public ShapeParser
{
public:
	Shape* parse(std::string data) noexcept(false);

	std::string toString();
};

class SquarePrintingStrategy : public ShapePrintingStrategy
{
	void printData(Shape* shape);
	void printTable(Shape* shape);

	std::string toString();
};

extern "C" __declspec(dllexport) Square * getSquare(float r);
extern "C" __declspec(dllexport) SquareParser * getSquareParser();
extern "C" __declspec(dllexport) SquarePrintingStrategy * getSquarePrintingStrategy();