#include "Square.h"

Square::Square(float a)
{
	_a = a;
}

float Square::Area()
{
	float result = _a * _a;
	return result;
}

float Square::Perimeter()
{
	float result = _a * 4;
	return result;
}

float Square::getEdge()
{
	return _a;
}

string Square::toString()
{
	return string("Square");
}
