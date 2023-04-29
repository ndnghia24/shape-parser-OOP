#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <windows.h>
#include <algorithm>

using namespace std;

#include "ShapeParserFactory.h"
#include "CircleParser.h"
#include "EllipseParser.h"
#include "SquareParser.h"
#include "RectangleParser.h"
#include "ShapePrintingContext.h"
#include "CirclePrintingStrategy.h"
#include "EllipsePrintingStrategy.h"
#include "SquarePrintingStrategy.h"
#include "RectanglePrintingStrategy.h"

int main()
{
	try
	{
        // Thiết lập chế độ Unicode cho đầu ra console
        _setmode(_fileno(stdout), _O_U16TEXT);

        // Tạo đối tượng ShapeParserFactory, đăng ký các parser cho các kiểu hình
        shared_ptr<ShapeParserFactory> factory = ShapeParserFactory::getInstance();
        factory->registerWith("Circle", shared_ptr<ShapeParser>(new CircleParser()));
        factory->registerWith("Ellipse", shared_ptr<ShapeParser>(new EllipseParser()));
        factory->registerWith("Square", shared_ptr<ShapeParser>(new SquareParser()));
        factory->registerWith("Rectangle", shared_ptr<ShapeParser>(new RectangleParser()));

        // Đọc dữ liệu từ tệp văn bản
        string input = "shapes.txt";
        ifstream reader(input, ios::in);

        // Tạo một vector để lưu trữ các đối tượng hình
        vector<shared_ptr<Shape>> listOfShapes;
        int quantity = 0;

        if (!reader.good())
        {
            wcout << L"Không đọc được tập tin shapes.txt..." << endl;
        }
        else
        {
            string line;

            // Đọc số lượng hình trong tệp       
            reader >> quantity;
            getline(reader, line);

            // Đọc dữ liệu cho từng hình trong tệp
            for (int i = 0; i < quantity; i++) {
                getline(reader, line);
                stringstream buffer(line);
                string type;
                string data;
                getline(buffer, type, ':');
                getline(buffer, data);

                // Sử dụng ShapeParserFactory để lấy parser tương ứng với kiểu hình
                shared_ptr<ShapeParser> parser = factory->mode(type);
                if (parser != nullptr) {
                    // Sử dụng parser để phân tích dữ liệu hình và tạo đối tượng hình tương ứng
                    Shape* newShape = parser->parse(data);

                    if (newShape == nullptr)
                    {
                        continue;
                    }

                    // Tạo một smart pointer để quản lý đối tượng hình
                    shared_ptr<Shape> newSmartPtr(newShape);
                    listOfShapes.push_back(newSmartPtr);
                }
            }

            reader.close();
        }

        // Tạo đối tượng ShapePrintingContext, đăng ký các chiến lược in cho các kiểu hình
        shared_ptr<ShapePrintingContext> printStrategy = ShapePrintingContext::getInstance();
        printStrategy->registerPrintingStrategy("Circle", shared_ptr<ShapePrintingStrategy>(new CirclePrintingStrategy));
        printStrategy->registerPrintingStrategy("Ellipse", shared_ptr<ShapePrintingStrategy>(new EllipsePrintingStrategy));
        printStrategy->registerPrintingStrategy("Square", shared_ptr<ShapePrintingStrategy>(new SquarePrintingStrategy));
        printStrategy->registerPrintingStrategy("Rectangle", shared_ptr<ShapePrintingStrategy>(new RectanglePrintingStrategy));

        // In kết quả phân tích các hình trong tệp
        wcout << L"Tìm thấy " << listOfShapes.size() << L" hình / " << quantity << L" hình" << endl;

        for (int i = 0; i < listOfShapes.size(); i++)
        {
            wcout << i + 1 << ". ";
            // Sử dụng ShapePrintingContext để in đối tượng hình
            printStrategy->setPrintingStrategy(listOfShapes[i]->toString());
            printStrategy->printData(listOfShapes[i].get());
        }

        if (listOfShapes.size() < quantity)
        {
            wcout << L"Không thể đọc được: " << quantity - listOfShapes.size() << L" hình." << endl;
        }

        // Sắp xếp danh sách các hình theo diện tích tăng dần
        sort(listOfShapes.begin(), listOfShapes.end(), Shape::AscendingByArea);

        // In danh sách các hình được sắp xếp theo diện tích tăng dần
        wcout << endl << L"Sắp xếp danh sách hình theo diện tích tăng dần: " << endl;
        for (int i = 0; i < listOfShapes.size(); i++)
        {
            wcout << "| " << i + 1;
            printStrategy->setPrintingStrategy(listOfShapes[i]->toString());
            printStrategy->printTable(listOfShapes[i].get());
        }

        // Giải phóng vùng nhớ các đối tượng hình
        for (int i = 0; i < listOfShapes.size(); i++)
        {
            listOfShapes[i].reset();
        }
	}
	catch (const std::exception& ex)
	{
        cout << "Error: " << ex.what() << endl;
	}

    system("pause");
    return 0;
}