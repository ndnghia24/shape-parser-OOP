/// <summary>
/// File: EllipseParser.h
/// </summary>

#pragma once

// Include các thư viện và file header cần thiết
#include "ShapeParser.h"
#include "Ellipse.h"

// Lớp EllipseParser kế thừa từ lớp ShapeParser
class EllipseParser : public ShapeParser
{
public:
    /// <summary>
    /// Phương thức parse dữ liệu hình ellipse từ chuỗi đầu vào.
    /// </summary>
    /// <param name="data">Chuỗi đầu vào chứa dữ liệu hình ellipse cần phân tích.</param>
    /// <returns>Một đối tượng hình ellipse với thuộc tính bán kính trục lớn và trục bé được trích xuất từ chuỗi đầu vào.</returns>
    /// <exception cref="std::invalid_argument">Nếu chuỗi đầu vào không chứa đầy đủ thông tin cần thiết để tạo ra một hình ellipse hợp lệ.</exception>
    Shape* parse(string data) noexcept(false);

    string toString();
};