#include "Shape.h"

float Shape::Area()
{
    return 0;
}

float Shape::Perimeter()
{
    return 0;
}

bool Shape::AscendingByArea(shared_ptr<Shape> a, shared_ptr<Shape> b)
{
    return a->Area() < b->Area();
}

string Shape::toString()
{
    return string("Shape");
}
