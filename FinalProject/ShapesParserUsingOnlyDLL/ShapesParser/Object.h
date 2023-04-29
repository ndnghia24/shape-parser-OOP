/// <summary>
/// File: Object.h
/// </summary>

#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Object
{
	/// <summary>
	/// Phương thức chuyển đổi đối tượng thành chuỗi.
	/// </summary>
	/// <returns>Chuỗi chứa thông tin về đối tượng.</returns>
	virtual string toString() = 0;
};