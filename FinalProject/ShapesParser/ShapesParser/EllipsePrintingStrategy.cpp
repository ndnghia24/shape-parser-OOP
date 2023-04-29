#include "EllipsePrintingStrategy.h"

void EllipsePrintingStrategy::printData(Shape* shape) {
    Ellipse* ellipse = dynamic_cast<Ellipse*>(shape);

    wcout << L"Hình Ellipse: Trục lớn=" << ellipse->getA() << L", Trục bé=" << ellipse->getB() << endl;
}

void EllipsePrintingStrategy::printTable(Shape* shape) {
    Ellipse* ellipse = dynamic_cast<Ellipse*>(shape);

    wcout << L" | " << setw(15) << left << L"Hình Elip"
        << L" | " << L"T.lớn=" << left << fixed << setprecision(0) << ellipse->getA() << L", T.bé=" << setw(5) << fixed << setprecision(0) << ellipse->getB()
        << L" | " << L"Chu vi=" << setw(10) << left << fixed << setprecision(1) << ellipse->Perimeter()
        << L" | " << L"Diện tích=" << setw(10) << left << fixed << setprecision(2) << ellipse->Area() << L" |" << endl;
}

string EllipsePrintingStrategy::toString()
{
    return string("EllipsePrintingStrategy");
}
