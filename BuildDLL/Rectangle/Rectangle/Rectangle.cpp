#include "pch.h"
#include "Rectangle.h"

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

RectangleDLL::RectangleDLL(float w, float h)
{
	_w = w;
	_h = h;
}

float RectangleDLL::Area()
{
	float result = _w * _h;
	return result;
}

float RectangleDLL::Perimeter()
{
	float result = (_w + _h) * 2;
	return result;
}

float RectangleDLL::getWidth()
{
	return _w;
}

float RectangleDLL::getHeight()
{
	return _h;
}

std::string RectangleDLL::toString()
{
	return std::string("Rectangle");
}

Shape* RectangleParser::parse(std::string data)
{
	try
	{
		Shape* result = nullptr;

		std::stringstream line(data);
		std::string buffer;

		getline(line, buffer, '=');
		getline(line, buffer, ',');
		float w = stof(buffer);

		if (w <= 0)
		{
			throw std::exception("");
		}

		getline(line, buffer, '=');
		getline(line, buffer);
		float h = stof(buffer);

		if (h <= 0)
		{
			throw std::exception("");
		}

		result = new RectangleDLL(w, h);

		return result;
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
}

std::string RectangleParser::toString()
{
	return std::string("RectangleParser");
}

void RectanglePrintingStrategy::printData(Shape* shape)
{
	RectangleDLL* rectangle = dynamic_cast<RectangleDLL*>(shape);

	std::wcout << L"Hình chữ nhật: Rộng=" << rectangle->getWidth() << ", Cao=" << rectangle->getHeight() << std::endl;
}

void RectanglePrintingStrategy::printTable(Shape* shape)
{
	RectangleDLL* rectangle = dynamic_cast<RectangleDLL*>(shape);

	std::wcout << L" | " << std::setw(15) << std::left << L"Hình chữ nhật"
		<< L" | " << L"Rộng=" << std::left << std::fixed << std::setprecision(0) << rectangle->getWidth() << ", Cao=" << std::setw(7) << std::fixed << std::setprecision(0) << rectangle->getHeight()
		<< L" | " << L"Chu vi=" << std::setw(10) << std::left << std::fixed << std::setprecision(1) << rectangle->Perimeter()
		<< L" | " << L"Diện tích=" << std::setw(10) << std::left << std::fixed << std::setprecision(2) << rectangle->Area() << L" |" << std::endl;
}

std::string RectanglePrintingStrategy::toString()
{
	return std::string("RectanglePrintingStrategy");
}

RectangleDLL* getRectangle(float w, float h)
{
	return new RectangleDLL(w, h);
}

RectangleParser* getRectangleParser()
{
	return new RectangleParser;
}

RectanglePrintingStrategy* getRectanglePrintingStrategy()
{
	return new RectanglePrintingStrategy;
}