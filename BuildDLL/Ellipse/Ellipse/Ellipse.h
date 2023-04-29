#pragma once
#include "framework.h"
#include <sstream>
#include <iomanip>
#include <iostream>

using std::wcout, std::setw, std::left,
    std::fixed, std::setprecision, std::endl, std::string,
    std::shared_ptr;

class Ellipse;

class Object
{
	virtual string toString() = 0;
};

class Shape : public Object
{
public:
	virtual float Area() = 0;
	virtual float Perimeter() = 0;

	static bool AscendingByArea(shared_ptr<Shape>, shared_ptr<Shape>);

	virtual string toString();
};

class ShapeParser : public Object
{
public:
	virtual Shape* parse(string data) = 0;

	virtual string toString();
};

class ShapePrintingStrategy : public Object
{
public:
	virtual void printData(Shape* shape) = 0;
	virtual void printTable(Shape* shape) = 0;

	virtual string toString();
};

#define PI 3.14

class EllipseDLL : public Shape
{
private:
    /// <summary>
    /// Bán kính trục lớn của hình ellipse.
    /// </summary>
    float _a;

    /// <summary>
    /// Bán kính trục bé của hình ellipse.
    /// </summary>
    float _b;

public:
    /// <summary>
    /// Phương thức khởi tạo Ellipse với tham số là bán kính trục lớn và bán kính trục bé.
    /// </summary>
    /// <param name="a">Bán kính trục lớn của hình ellipse.</param>
    /// <param name="b">Bán kính trục bé của hình ellipse.</param>
    EllipseDLL(float a, float b);

    /// <summary>
    /// Phương thức tính diện tích của hình ellipse.
    /// </summary>
    /// <returns>Giá trị diện tích của hình ellipse dựa trên công thức S = πab.</returns>
    float Area();

    /// <summary>
    /// Phương thức tính chu vi của hình ellipse.
    /// </summary>
    /// <returns>Giá trị chu vi của hình ellipse dựa trên công thức P = 2πsqrt((a^2+b^2)/2).</returns>
    float Perimeter();

    /// <summary>
    /// Phương thức lấy giá trị bán kính trục lớn của hình ellipse.
    /// </summary>
    /// <returns>Giá trị bán kính trục lớn của hình ellipse.</returns>
    float getA();

    /// <summary>
    /// Phương thức lấy giá trị bán kính trục bé của hình ellipse.
    /// </summary>
    /// <returns>Giá trị bán kính trục bé của hình ellipse.</returns>
    float getB();

    /// <summary>
    /// Phương thức trả về một chuỗi mô tả hình ellipse.
    /// Chuỗi mô tả bao gồm tên và các thuộc tính của hình ellipse.
    /// </summary>
    /// <returns>Chuỗi mô tả hình ellipse.</returns>
    string toString();
};

class EllipseParser : public ShapeParser
{
public:
    /// <summary>
    /// Phương thức parse dữ liệu hình ellipse từ chuỗi đầu vào.
    /// </summary>
    /// <param name="data">Chuỗi đầu vào chứa dữ liệu hình ellipse cần phân tích.</param>
    /// <returns>Một đối tượng hình ellipse với thuộc tính bán kính trục lớn và trục bé được trích xuất từ chuỗi đầu vào.</returns>
    /// <exception cref="invalid_argument">Nếu chuỗi đầu vào không chứa đầy đủ thông tin cần thiết để tạo ra một hình ellipse hợp lệ.</exception>
    Shape* parse(string data) noexcept(false);

    string toString();
};

class EllipsePrintingStrategy : public ShapePrintingStrategy {
public:
    void printData(Shape* shape);
    void printTable(Shape* shape);

    string toString();
};

extern "C" __declspec(dllexport) EllipseDLL * getEllipse(float, float);
extern "C" __declspec(dllexport) EllipseParser * getEllipseParser();
extern "C" __declspec(dllexport) EllipsePrintingStrategy * getEllipsePrintingStrategy();