/// <summary>
/// File: ShapeParser.h
/// </summary>

#pragma once
#include "Object.h"
#include "Shape.h"
#include <sstream>

class ShapeParser : public Object
{
public:
	/// <summary>
	/// Phương thức phân tích dữ liệu hình học từ chuỗi đầu vào.
	/// </summary>
	/// <param name="data">Chuỗi đầu vào chứa dữ liệu hình học cần phân tích.</param>
	/// <returns>Một đối tượng hình học được trích xuất từ chuỗi đầu vào.</returns>
	virtual Shape* parse(string data) = 0;

	/// <summary>
	/// Phương thức chuyển đổi đối tượng ShapeParser thành chuỗi.
	/// </summary>
	/// <returns>Chuỗi chứa thông tin về đối tượng ShapeParser.</returns>
	string toString();
};