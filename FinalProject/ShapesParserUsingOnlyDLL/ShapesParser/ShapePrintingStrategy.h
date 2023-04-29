/// <summary>
/// File: ShapePrintingStrategy.h
/// </summary>

#pragma once
#include "Object.h"

class Shape;

class ShapePrintingStrategy : public Object
{
public:
	/// <summary>
	/// Phương thức in dữ liệu của hình theo dạng danh sách.
	/// </summary>
	/// <param name="shape">Đối tượng hình cần in.</param>
	virtual void printData(Shape* shape) = 0;

	/// <summary>
	/// Phương thức in dữ liệu của hình theo dạng bảng.
	/// </summary>
	/// <param name="shape">Đối tượng hình cần in.</param>
	virtual void printTable(Shape* shape) = 0;

	/// <summary>
	/// Phương thức chuyển đổi đối tượng ShapePrintingStrategy thành chuỗi.
	/// </summary>
	/// <returns>Chuỗi chứa thông tin về đối tượng ShapePrintingStrategy.</returns>
	string toString();
};