/// <summary>
/// File: Shape.h
/// </summary>

#pragma once
#include "Object.h"

class Shape : public Object
{
public:
	/// <summary>
	/// Phương thức tính diện tích của hình.
	/// </summary>
	/// <returns>Giá trị diện tích của hình.</returns>
	virtual float Area() = 0;

	/// <summary>
	/// Phương thức tính chu vi của hình.
	/// </summary>
	/// <returns>Giá trị chu vi của hình.</returns>
	virtual float Perimeter() = 0;

	/// <summary>
	/// Phương thức so sánh hai hình theo diện tích tăng dần.
	/// </summary>
	/// <param name="a">Đối tượng hình 1.</param>
	/// <param name="b">Đối tượng hình 2.</param>
	/// <returns>True nếu diện tích của hình a nhỏ hơn diện tích của hình b, ngược lại trả về False.</returns>
	static bool AscendingByArea(shared_ptr<Shape>, shared_ptr<Shape>);

	/// <summary>
	/// Phương thức chuyển đổi đối tượng Shape thành chuỗi.
	/// </summary>
	/// <returns>Chuỗi chứa thông tin về đối tượng Shape.</returns>
	virtual string toString();
};