/// <summary>
/// File: Circle.h
/// </summary>

#pragma once

// Include các thư viện và file header cần thiết
#include "Shape.h"
#include "CirclePrintingStrategy.h"

// Định nghĩa hằng số PI
#define PI 3.14

// Lớp Circle kế thừa từ lớp Shape
class Circle : public Shape
{
private:
	/// <summary>
	/// Bán kính của hình tròn.
	/// </summary>
	float _r;

public:
	/// <summary>
	/// Phương thức khởi tạo Circle với tham số là bán kính.
	/// </summary>
	/// <param name="r">Bán kính của hình tròn.</param>
	Circle(float r);

	/// <summary>
	/// Phương thức tính diện tích của hình tròn.
	/// </summary>
	/// <returns>Giá trị diện tích của hình tròn dựa trên công thức S = πr^2.</returns>
	float Area();

	/// <summary>
	/// Phương thức tính chu vi của hình tròn.
	/// </summary>
	/// <returns>Giá trị chu vi của hình tròn dựa trên công thức P = 2πr.</returns>
	float Perimeter();

	/// <summary>
	/// Phương thức lấy giá trị bán kính của hình tròn.
	/// </summary>
	/// <returns>Giá trị bán kính của hình tròn.</returns>
	float getRadius();

	/// <summary>
	/// Phương thức trả về một chuỗi mô tả hình tròn.
	/// Chuỗi mô tả bao gồm tên và các thuộc tính của hình tròn.
	/// </summary>
	/// <returns>Chuỗi mô tả hình tròn.</returns>
	string toString();
};

// Lớp Circle sử dụng design pattern Strategy để in hình tròn.
// Nó sử dụng đối tượng CirclePrintingStrategy để thực hiện việc in hình tròn.
// Điều này cho phép lớp Circle thay đổi cách thức in hình tròn mà không cần thay đổi mã nguồn của nó.