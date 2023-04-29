#include "pch.h" 
#include "Ellipse.h"

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

EllipseDLL::EllipseDLL(float a, float b)
{
    _a = a;
    _b = b;
}

float EllipseDLL::Area()
{
    return PI * _a * _b;
}

float EllipseDLL::Perimeter()
{
    return 2 * PI * sqrt(((_a * _a) + (_b * _b)) / 2);
}

float EllipseDLL::getA()
{
    return _a;
}

float EllipseDLL::getB()
{
    return _b;
}

std::string EllipseDLL::toString()
{
    return std::string("Ellipse");
}

Shape* EllipseParser::parse(std::string data) noexcept(false)
{
    try {
        Shape* result = nullptr;

        std::stringstream line(data);
        std::string buffer;

        // Lấy giá trị của bán kính trục lớn và trục bé
        getline(line, buffer, '=');
        getline(line, buffer, ',');
        float a = stof(buffer);

        getline(line, buffer, '=');
        getline(line, buffer);
        float b = stof(buffer);

        if (a <= 0 || b <= 0) {
            throw std::exception("");
        }

        result = new EllipseDLL(a, b);

        return result;
    }
    catch (const std::exception&) {
        return nullptr;
    }
}

string EllipseParser::toString()
{
    return string("EllipseParser");
}

void EllipsePrintingStrategy::printData(Shape* shape) {
    EllipseDLL* ellipse = dynamic_cast<EllipseDLL*>(shape);

    wcout << L"Hình elip: Trục lớn=" << ellipse->getA() << L", Trục bé=" << ellipse->getB() << endl;
}

void EllipsePrintingStrategy::printTable(Shape* shape) {
    EllipseDLL* ellipse = dynamic_cast<EllipseDLL*>(shape);

    wcout << L" | " << setw(15) << left << L"Hình elip"
        << L" | " << L"T.lớn=" << left << fixed << setprecision(0) << ellipse->getA() << L", T.bé=" << setw(5) << fixed << setprecision(0) << ellipse->getB()
        << L" | " << L"Chu vi=" << setw(10) << left << fixed << setprecision(1) << ellipse->Perimeter()
        << L" | " << L"Diện tích=" << setw(10) << left << fixed << setprecision(2) << ellipse->Area() << L" |" << endl;
}

string EllipsePrintingStrategy::toString()
{
    return string("EllipsePrintingStrategy");
}

EllipseDLL* getEllipse(float a, float b)
{
    return new EllipseDLL(a, b);
}

EllipseParser* getEllipseParser()
{
    return new EllipseParser;
}

EllipsePrintingStrategy* getEllipsePrintingStrategy()
{
    return new EllipsePrintingStrategy;
}
