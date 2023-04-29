#pragma once
#include "framework.h"
#include <sstream>
#include <iomanip>
#include <iostream>

class Rectangle;

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

class RectangleDLL : public Shape
{
private:
	float _w;
	float _h;
public:
	RectangleDLL(float w, float h);

	float Area();
	float Perimeter();

	float getWidth();
	float getHeight();

	std::string toString();
};

class RectangleParser : public ShapeParser
{
public:
	Shape* parse(std::string data) noexcept(false);

	std::string toString();
};

class RectanglePrintingStrategy : public ShapePrintingStrategy
{
	void printData(Shape* shape);
	void printTable(Shape* shape);

	std::string toString();
};

extern "C" __declspec(dllexport) RectangleDLL * getRectangle(float w, float h);
extern "C" __declspec(dllexport) RectangleParser * getRectangleParser();
extern "C" __declspec(dllexport) RectanglePrintingStrategy * getRectanglePrintingStrategy();