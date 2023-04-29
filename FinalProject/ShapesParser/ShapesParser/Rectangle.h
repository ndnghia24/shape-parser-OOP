/// <summary>
/// File: Rectangle.h
/// </summary>

#pragma once

// Include các thư viện và file header cần thiết
#include "Shape.h"

// Lớp Rectangle kế thừa từ lớp Shape
class Rectangle : public Shape
{
private:
	// Các thuộc tính của hình chữ nhật: chiều rộng và chiều cao
	float _w;
	float _h;

public:
	// Constructor với tham số là chiều rộng và chiều cao của hình chữ nhật
	/// <summary>
	/// Tạo một hình chữ nhật mới với chiều rộng và chiều cao được chỉ định.
	/// </summary>
	/// <param name="w">Chiều rộng của hình chữ nhật.</param>
	/// <param name="h">Chiều cao của hình chữ nhật.</param>
	Rectangle(float w, float h);

	// Phương thức tính diện tích của hình chữ nhật
	/// <summary>
	/// Tính diện tích của hình chữ nhật.
	/// </summary>
	/// <returns>Diện tích của hình chữ nhật.</returns>
	float Area();

	// Phương thức tính chu vi của hình chữ nhật
	/// <summary>
	/// Tính chu vi của hình chữ nhật.
	/// </summary>
	/// <returns>Chu vi của hình chữ nhật.</returns>
	float Perimeter();

	// Getter cho thuộc tính chiều rộng
	/// <summary>
	/// Lấy giá trị chiều rộng của hình chữ nhật.
	/// </summary>
	/// <returns>Chiều rộng của hình chữ nhật.</returns>
	float getWidth();

	// Getter cho thuộc tính chiều cao
	/// <summary>
	/// Lấy giá trị chiều cao của hình chữ nhật.
	/// </summary>
	/// <returns>Chiều cao của hình chữ nhật.</returns>
	float getHeight();

	// Phương thức chuyển đổi thông tin hình chữ nhật thành chuỗi
	/// <summary>
	/// Chuyển đổi thông tin của hình chữ nhật thành chuỗi.
	/// </summary>
	/// <returns>Chuỗi chứa thông tin của hình chữ nhật.</returns>
	string toString();
};