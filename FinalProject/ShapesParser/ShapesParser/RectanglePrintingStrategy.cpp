#include "RectanglePrintingStrategy.h"

void RectanglePrintingStrategy::printData(Shape* shape)
{
	Rectangle* rectangle = dynamic_cast<Rectangle*>(shape);

	wcout << L"Hình chữ nhật: Rộng=" << rectangle->getWidth() << ", Cao=" << rectangle->getHeight() << endl;
}

void RectanglePrintingStrategy::printTable(Shape* shape)
{
	Rectangle* rectangle = dynamic_cast<Rectangle*>(shape);

	wcout << L" | " << setw(15) << left << L"Hình chữ nhật"
		<< L" | " << L"Rộng=" << left << fixed << setprecision(0) << rectangle->getWidth() << ", Cao=" << setw(7) << fixed << setprecision(0) << rectangle->getHeight()
		<< L" | " << L"Chu vi=" << setw(10) << left << fixed << setprecision(1) << rectangle->Perimeter()
		<< L" | " << L"Diện tích=" << setw(10) << left << fixed << setprecision(2) << rectangle->Area() << L" |" << endl;
}

string RectanglePrintingStrategy::toString()
{
	return string("RectanglePrintingStrategy");
}
