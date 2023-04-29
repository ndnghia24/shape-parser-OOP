#pragma once
#include "framework.h"
#include <sstream>
#include <iomanip>
#include <iostream>

class Circle;

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

	virtual std::string toString();
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

#define PI 3.14

class Circle : public Shape
{
private:
	float _r;
public:
	Circle(float r);

	float Area();
	float Perimeter();
	float getRadius();

	std::string toString();
};

class CircleParser : public ShapeParser
{
public:
	Shape* parse(std::string data);

	std::string toString();
};

class CirclePrintingStrategy : public ShapePrintingStrategy
{
	void printData(Shape* shape);
	void printTable(Shape* shape);

	std::string toString();
};

extern "C" __declspec(dllexport) CirclePrintingStrategy* getCirclePrintingStrategy();
extern "C" __declspec(dllexport) CircleParser* getCircleParser();
extern "C" __declspec(dllexport) Circle* getCircle(float r);