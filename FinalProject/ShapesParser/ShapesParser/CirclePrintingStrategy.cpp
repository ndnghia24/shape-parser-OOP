#include "CirclePrintingStrategy.h"

void CirclePrintingStrategy::printData(Shape* shape)
{
	Circle* circle = dynamic_cast<Circle*>(shape);

	wcout << L"Hình tròn: Bán kính=" << circle->getRadius() << endl;
}

void CirclePrintingStrategy::printTable(Shape* shape)
{
	Circle* circle = dynamic_cast<Circle*>(shape);

	wcout << L" | " << setw(15) << left << L"Hình tròn"
		<< L" | " << L"Bán kính=" << setw(10) << left << fixed << setprecision(0) << circle->getRadius()
		<< L" | " << L"Chu vi=" << setw(10) << left << fixed << setprecision(1) << circle->Perimeter()
		<< L" | " << L"Diện tích=" << setw(10) << left << fixed << setprecision(2) << circle->Area() << L" |" << endl;
}

string CirclePrintingStrategy::toString()
{
	return string("CirclePrintingStrategy");
}
