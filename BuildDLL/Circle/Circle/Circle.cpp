#include "pch.h" 
#include "Circle.h"

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
	return std::string("ShapeParser");
}

std::string ShapePrintingStrategy::toString()
{
	return std::string("ShapePrintingStrategy");
}

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

std::string Circle::toString()
{
	return std::string("Circle");
}

Shape* CircleParser::parse(std::string data)
{
	try
	{
		Shape* result = nullptr;

		std::stringstream line(data);
		std::string buffer;

		getline(line, buffer, '=');
		getline(line, buffer);
		float r = stof(buffer);

		if (r <= 0)
		{
			throw std::exception("");
		}

		result = new Circle(r);

		return result;
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
}

std::string CircleParser::toString()
{
	return std::string("CircleParser");
}

void CirclePrintingStrategy::printData(Shape* shape)
{
	Circle* circle = dynamic_cast<Circle*>(shape);

	std::wcout << L"Hình tròn: Bán kính=" << circle->getRadius() << std::endl;
}
void CirclePrintingStrategy::printTable(Shape* shape)
{
	Circle* circle = dynamic_cast<Circle*>(shape);

	std::wcout << L" | " << std::setw(15) << std::left << L"Hình tròn"
		<< L" | " << L"Bán kính=" << std::setw(10) << std::left << std::fixed << std::setprecision(0) << circle->getRadius()
		<< L" | " << L"Chu vi=" << std::setw(10) << std::left << std::fixed << std::setprecision(1) << circle->Perimeter()
		<< L" | " << L"Diện tích=" << std::setw(10) << std::left << std::fixed << std::setprecision(2) << circle->Area() << L" |" << std::endl;
}

std::string CirclePrintingStrategy::toString()
{
	return std::string("CirclePrintingStrategy");
}

CirclePrintingStrategy* getCirclePrintingStrategy()
{
	return new CirclePrintingStrategy;
}

CircleParser* getCircleParser()
{
	return new CircleParser;
}

Circle* getCircle(float r)
{
	return new Circle(r);
}