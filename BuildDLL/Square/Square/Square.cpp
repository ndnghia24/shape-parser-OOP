#include "pch.h"
#include "Square.h"

bool Shape::AscendingByArea(std::shared_ptr<Shape> a, std::shared_ptr<Shape> b)
{
	return a->Area() < b->Area();
};

std::string Shape::toString()
{
	return std::string("Shape");
}

std::string ShapeParser::toString()
{
	return std::string("IShapeParser");
}

std::string ShapePrintingStrategy::toString()
{
	return std::string("ShapePrintingStrategy");
}

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

std::string Square::toString()
{
	return std::string("Square");
}

Shape* SquareParser::parse(std::string data)
{
	try
	{
		Shape* result = nullptr;

		std::stringstream line(data);
		std::string buffer;

		getline(line, buffer, '=');
		getline(line, buffer);
		float a = stof(buffer);

		if (a <= 0)
		{
			throw std::exception("");
		}

		result = new Square(a);

		return result;
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
}

std::string SquareParser::toString()
{
	return std::string("SquareParser");
}

void SquarePrintingStrategy::printData(Shape* shape)
{
	Square* square = dynamic_cast<Square*>(shape);

	std::wcout << L"Hình vuông: Cạnh=" << square->getEdge() << std::endl;
}

void SquarePrintingStrategy::printTable(Shape* shape)
{
	Square* square = dynamic_cast<Square*>(shape);

	std::wcout << L" | " << std::setw(15) << std::left << L"Hình vuông"
		<< L" | " << L"Cạnh=" << std::setw(14) << std::left << std::fixed << std::setprecision(0) << square->getEdge()
		<< L" | " << L"Chu vi=" << std::setw(10) << std::left << std::fixed << std::setprecision(1) << square->Perimeter()
		<< L" | " << L"Diện tích=" << std::setw(10) << std::left << std::fixed << std::setprecision(2) << square->Area() << L" |" << std::endl;
}

std::string SquarePrintingStrategy::toString()
{
	return std::string("SquarePrintingStrategy");
}

Square* getSquare(float a)
{
	return new Square(a);
}

SquareParser* getSquareParser()
{
	return new SquareParser;
}

SquarePrintingStrategy* getSquarePrintingStrategy()
{
	return new SquarePrintingStrategy;
}