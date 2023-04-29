/// <summary>
/// File: CircleParser.h
/// </summary>

#pragma once

// Include các thư viện và file header cần thiết
#include "ShapeParser.h"
#include "Circle.h"

// Lớp CircleParser kế thừa từ lớp ShapeParser
class CircleParser : public ShapeParser
{
public:
	/// <summary>
	/// Phương thức parse dữ liệu hình tròn từ chuỗi đầu vào.
	/// </summary>
	/// <param name="data">Chuỗi đầu vào chứa dữ liệu hình tròn cần phân tích.</param>
	/// <returns>Một đối tượng hình tròn với thuộc tính bán kính được trích xuất từ chuỗi đầu vào.</returns>
	/// <exception cref="std::invalid_argument">Nếu chuỗi đầu vào không chứa đầy đủ thông tin cần thiết để tạo ra một hình tròn hợp lệ.</exception>
	Shape* parse(string data) noexcept(false);

	string toString();
};