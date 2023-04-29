#pragma once
#include <map>
#include <memory>
#include "Object.h"
#include "Shape.h"
#include "ShapeParser.h"

class ShapeParserFactory : public Object
{
private:
    /// <summary>
    /// Đối tượng đơn lẻ của lớp ShapeParserFactory.
    /// </summary>
    static shared_ptr<ShapeParserFactory> _instance;

    /// <summary>
    /// Constructor mặc định của lớp ShapeParserFactory.
    /// </summary>
    ShapeParserFactory();

public:
    /// <summary>
    /// Phương thức trả về đối tượng đơn lẻ của lớp ShapeParserFactory.
    /// </summary>
    /// <returns>Đối tượng đơn lẻ của lớp ShapeParserFactory.</returns>
    static shared_ptr<ShapeParserFactory> getInstance();

private:
    /// <summary>
    /// Một bản đồ lưu trữ các bản sao nguyên mẫu của các đối tượng ShapeParser.
    /// </summary>
    map<string, shared_ptr<ShapeParser>> _prototypes;

public:
    /// <summary>
    /// Phương thức đăng ký một đối tượng ShapeParser với một loại hình đã cho.
    /// </summary>
    /// <param name="type">Loại hình cần đăng ký.</param>
    /// <param name="parser">Đối tượng ShapeParser cần đăng ký.</param>
    void registerWith(string type, shared_ptr<ShapeParser> parser);

    /// <summary>
    /// Phương thức thiết lập chế độ cho một loại hình đã cho.
    /// </summary>
    /// <param name="type">Loại hình cần thiết lập chế độ.</param>
    /// <returns>Đối tượng ShapeParser tương ứng với chế độ đã thiết lập.</returns>
    shared_ptr<ShapeParser> mode(string type);

    /// <summary>
    /// Phương thức trả về một chuỗi biểu diễn lớp ShapeParserFactory.
    /// </summary>
    /// <returns>Chuỗi biểu diễn lớp ShapeParserFactory.</returns>
    string toString();
};