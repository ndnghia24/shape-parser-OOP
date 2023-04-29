#include "Ellipse.h"

Ellipse::Ellipse(float a, float b) 
{
    _a = a;
    _b = b;
}

float Ellipse::Area() 
{
    return PI * _a * _b;
}

float Ellipse::Perimeter() 
{
    return 2 * PI * sqrt(((_a * _a) + (_b * _b)) / 2);
}

float Ellipse::getA() 
{
    return _a;
}

float Ellipse::getB() 
{
    return _b;
}

string Ellipse::toString() 
{
    return string("Ellipse");
}