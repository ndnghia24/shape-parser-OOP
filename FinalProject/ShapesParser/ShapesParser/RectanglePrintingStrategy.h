#pragma once
#include "ShapePrintingStrategy.h"
#include "Rectangle.h"

class RectanglePrintingStrategy : public ShapePrintingStrategy
{
public:
	/// <summary>
	/// In ra thông tin chi tiết của đối tượng Rectangle.
	/// </summary>
	/// <param name="shape">Con trỏ đến đối tượng Rectangle cần in ra.</param>
	void printData(Shape* shape);

	/// <summary>
	/// In ra bảng chứa thông tin của đối tượng Rectangle.
	/// </summary>
	/// <param name="shape">Con trỏ đến đối tượng Rectangle cần in ra.</param>
	void printTable(Shape* shape);

	string toString();
};