#pragma once
#include "Object.h"
#include "Shape.h"
#include <map>
#include "ShapePrintingStrategy.h"

class ShapePrintingContext : public Object
{
private:
    /// <summary>
    /// Một bản đồ lưu trữ các chiến lược in cho các loại hình khác nhau.
    /// </summary>
    map<string, shared_ptr<ShapePrintingStrategy>> _listPrintingStrategy;

    /// <summary>
    /// Chiến lược in hiện tại.
    /// </summary>
    shared_ptr<ShapePrintingStrategy> _printingStrategy;

    /// <summary>
    /// Đối tượng đơn lẻ của lớp ShapePrintingContext.
    /// </summary>
    static shared_ptr<ShapePrintingContext> _instance;

    /// <summary>
    /// Constructor mặc định của lớp ShapePrintingContext.
    /// </summary>
    ShapePrintingContext();

public:
    /// <summary>
    /// Phương thức trả về đối tượng đơn lẻ của lớp ShapePrintingContext.
    /// </summary>
    static shared_ptr<ShapePrintingContext> getInstance();

    /// <summary>
    /// Phương thức đăng ký một chiến lược in cho một loại hình đã cho.
    /// </summary>
    /// <param name="type">Loại hình cần đăng ký chiến lược in.</param>
    /// <param name="strategy">Chiến lược in cho loại hình đã cho.</param>
    void registerPrintingStrategy(string type, shared_ptr<ShapePrintingStrategy> strategy);

    /// <summary>
    /// Phương thức thiết lập chiến lược in cho một loại hình đã cho.
    /// </summary>
    /// <param name="type">Loại hình cần thiết lập chiến lược in.</param>
    void setPrintingStrategy(string type);

    /// <summary>
    /// Phương thức in dữ liệu cho một hình đã cho bằng chiến lược in hiện tại.
    /// </summary>
    /// <param name="_shape">Hình cần in dữ liệu.</param>
    void printData(Shape* _shape);

    /// <summary>
    /// Phương thức in bảng cho một hình đã cho bằng chiến lược in hiện tại.
    /// </summary>
    /// <param name="_shape">Hình cần in bảng.</param>
    void printTable(Shape* _shape);

    /// <summary>
    /// Phương thức trả về một chuỗi biểu diễn lớp ShapePrintingContext.
    /// </summary>
    /// <returns>Chuỗi biểu diễn lớp ShapePrintingContext.</returns>
    string toString();
};