/// <summary>
/// File: Ellipse.h
/// </summary>

#pragma once
#define PI 3.14

// Include các thư viện và file header cần thiết
#include "Shape.h"
#include "EllipsePrintingStrategy.h"

// Lớp Ellipse kế thừa từ lớp Shape
class Ellipse : public Shape
{
private:
    /// <summary>
    /// Bán kính trục lớn của hình ellipse.
    /// </summary>
    float _a;

    /// <summary>
    /// Bán kính trục bé của hình ellipse.
    /// </summary>
    float _b;

public:
    /// <summary>
    /// Phương thức khởi tạo Ellipse với tham số là bán kính trục lớn và bán kính trục bé.
    /// </summary>
    /// <param name="a">Bán kính trục lớn của hình ellipse.</param>
    /// <param name="b">Bán kính trục bé của hình ellipse.</param>
    Ellipse(float a, float b);

    /// <summary>
    /// Phương thức tính diện tích của hình ellipse.
    /// </summary>
    /// <returns>Giá trị diện tích của hình ellipse dựa trên công thức S = πab.</returns>
    float Area();

    /// <summary>
    /// Phương thức tính chu vi của hình ellipse.
    /// </summary>
    /// <returns>Giá trị chu vi của hình ellipse dựa trên công thức P = 2πsqrt((a^2+b^2)/2).</returns>
    float Perimeter();

    /// <summary>
    /// Phương thức lấy giá trị bán kính trục lớn của hình ellipse.
    /// </summary>
    /// <returns>Giá trị bán kính trục lớn của hình ellipse.</returns>
    float getA();

    /// <summary>
    /// Phương thức lấy giá trị bán kính trục bé của hình ellipse.
    /// </summary>
    /// <returns>Giá trị bán kính trục bé của hình ellipse.</returns>
    float getB();

    /// <summary>
    /// Phương thức trả về một chuỗi mô tả hình ellipse.
    /// Chuỗi mô tả bao gồm tên và các thuộc tính của hình ellipse.
    /// </summary>
    /// <returns>Chuỗi mô tả hình ellipse.</returns>
    string toString();
};

// Lớp Ellipse sử dụng design pattern Strategy để in hình ellipse.
// Nó sử dụng đối tượng EllipsePrintingStrategy để thực hiện việc in hình ellipse.
// Điều này cho phép lớp Ellipse thay đổi cách thức in hình ellipse mà không cần thay đổi mã nguồn của nó."