/// <summary>
/// File: CirclePrintingStrategy.h
/// </summary>

#pragma once

// Include các thư viện và file header cần thiết
#include "ShapePrintingStrategy.h"
#include "Circle.h"

// Lớp CirclePrintingStrategy kế thừa từ lớp ShapePrintingStrategy
class CirclePrintingStrategy : public ShapePrintingStrategy
{
public:
	/// <summary>
	/// Phương thức in dữ liệu hình tròn dưới dạng danh sách.
	/// </summary>
	/// <param name="shape">Đối tượng hình tròn cần in.</param>
	void printData(Shape* shape);

	/// <summary>
	/// Phương thức in dữ liệu hình tròn dưới dạng bảng.
	/// </summary>
	/// <param name="shape">Đối tượng hình tròn cần in.</param>
	void printTable(Shape* shape);

	string toString();
};