#include "SquarePrintingStrategy.h"

void SquarePrintingStrategy::printData(Shape* shape)
{
	Square* square = dynamic_cast<Square*>(shape);

	wcout << L"Hình vuông: Cạnh=" << square->getEdge() << endl;
}

void SquarePrintingStrategy::printTable(Shape* shape)
{
	Square* square = dynamic_cast<Square*>(shape);

	wcout << L" | " << setw(15) << left << L"Hình vuông"
		<< L" | " << L"Cạnh=" << setw(14) << left << fixed << setprecision(0) << square->getEdge()
		<< L" | " << L"Chu vi=" << setw(10) << left << fixed << setprecision(1) << square->Perimeter()
		<< L" | " << L"Diện tích=" << setw(10) << left << fixed << setprecision(2) << square->Area() << L" |" << endl;
}

string SquarePrintingStrategy::toString()
{
	return string("SquarePrintingStrategy");
}
