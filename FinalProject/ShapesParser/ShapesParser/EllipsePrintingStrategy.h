#pragma once

#include "ShapePrintingStrategy.h"
#include "Ellipse.h"

class EllipsePrintingStrategy : public ShapePrintingStrategy {
public:
    void printData(Shape* shape);
    void printTable(Shape* shape);

    string toString();
};