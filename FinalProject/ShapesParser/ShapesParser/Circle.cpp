#include "Circle.h"

Circle::Circle(float r)
{
	_r = r;
}

float Circle::Area()
{
	float result = PI * _r * _r;
	return result;
}

float Circle::Perimeter()
{
	float result = PI * 2 * _r;
	return result;
}

float Circle::getRadius()
{
	return _r;
}

string Circle::toString()
{
	return string("Circle");
}