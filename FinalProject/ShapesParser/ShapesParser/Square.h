#pragma once
#include "Shape.h"

class Square : public Shape
{
private:
	float _a;

public:
	/// <summary>
	/// Constructor của lớp Square với tham số là cạnh của hình vuông.
	/// </summary>
	/// <param name="a">Cạnh của hình vuông.</param>
	Square(float a);

	/// <summary>
	/// Phương thức tính diện tích của hình vuông.
	/// </summary>
	/// <returns>Diện tích của hình vuông.</returns>
	float Area();

	/// <summary>
	/// Phương thức tính chu vi của hình vuông.
	/// </summary>
	/// <returns>Chu vi của hình vuông.</returns>
	float Perimeter();

	/// <summary>
	/// Getter cho thuộc tính cạnh của hình vuông.
	/// </summary>
	/// <returns>Cạnh của hình vuông.</returns>
	float getEdge();

	/// <summary>
	/// Phương thức chuyển đổi thông tin hình vuông thành chuỗi.
	/// </summary>
	/// <returns>Chuỗi chứa thông tin của hình vuông.</returns>
	string toString();
};