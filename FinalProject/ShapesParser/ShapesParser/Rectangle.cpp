#include "Rectangle.h"

Rectangle::Rectangle(float w, float h)
{
	_w = w;
	_h = h;
}

float Rectangle::Area()
{
	float result = _w * _h;
	return result;
}

float Rectangle::Perimeter()
{
	float result = (_w + _h) * 2;
	return result;
}

float Rectangle::getWidth()
{
	return _w;
}

float Rectangle::getHeight()
{
	return _h;
}

string Rectangle::toString()
{
	return string("Rectangle");
}
