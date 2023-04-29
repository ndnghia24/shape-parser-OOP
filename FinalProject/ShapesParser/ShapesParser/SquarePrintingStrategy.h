#pragma once
#include "ShapePrintingStrategy.h"
#include "Square.h"

class SquarePrintingStrategy : public ShapePrintingStrategy
{
public:
	/// <summary>
	/// In ra thông tin chi tiết của đối tượng Square.
	/// </summary>
	/// <param name="shape">Con trỏ đến đối tượng Square cần in ra.</param>
	void printData(Shape* shape);

	/// <summary>
	/// In ra bảng chứa thông tin của đối tượng Square.
	/// </summary>
	/// <param name="shape">Con trỏ đến đối tượng Square cần in ra.</param>
	void printTable(Shape* shape);

	string toString();
};