#pragma once
#include "ShapeParser.h"
#include "Square.h"

class SquareParser : public ShapeParser
{
public:
	/// <summary>
	/// Phân tích dữ liệu chuỗi để tạo ra một đối tượng Square mới.
	/// </summary>
	/// <param name="data">Dữ liệu chuỗi cần phân tích.</param>
	/// <returns>Con trỏ đến đối tượng Shape mới được tạo ra.</returns>
	/// <exception cref="invalid_argument">Ném ra ngoại lệ nếu dữ liệu chuỗi không hợp lệ.</exception>
	Shape* parse(string data) noexcept(false);

	string toString();
};