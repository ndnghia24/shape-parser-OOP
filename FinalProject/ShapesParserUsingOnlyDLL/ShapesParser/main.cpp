#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <windows.h>
#include <filesystem>
#include <algorithm>

using namespace std;

namespace fs = std::filesystem;

#include "ultils.h" // Thư viện chứa các hàm tiện ích
#include "ShapeParserFactory.h" // Lớp factory cho việc tạo ra các đối tượng ShapeParser
#include "ShapePrintingContext.h" // Lớp context cho việc in các đối tượng Shape

int main()
{
    try
    {
        //*** Đưa các DLL vào chương trình
        vector<string> DLL; // Danh sách tên file DLL trong thư mục hiện tại
        string filename; // Biến lưu trữ tên file

        // Lặp qua tất cả các file trong thư mục hiện tại và kiểm tra nếu là file DLL thì thêm vào danh sách
        for (const auto& entry : fs::directory_iterator("."))
        {
            if (entry.path().extension() == ".dll")
            {
                filename = entry.path().filename().string();
                DLL.push_back(filename.substr(0, filename.find('.')));
            }
        }

        // Map lưu trữ các file DLL đã load lên và tên tương ứng của chúng
        map<string, HINSTANCE> DLL_Loader;

        // Lặp qua danh sách tên file DLL và load chúng lên
        for (const auto& x : DLL)
        {
            LPCWSTR fileFormat = ConvertStringToLPCWSTR(x + ".dll");
            DLL_Loader.insert({ x, LoadLibrary(fileFormat) });

            if (DLL_Loader[x] != NULL)
            {
                cout << "Doc " << (x + ".dll") << " thanh cong!" << endl;
            }
        }
        cout << endl;

        //*** Đưa các hàm cần thiết từ DLL vào các factory

        // Tạo ra một shared pointer đến lớp factory
        shared_ptr<ShapeParserFactory> factory = ShapeParserFactory::getInstance();

        // Định nghĩa một function pointer để lấy ra đối tượng ShapeParser từ file DLL
        typedef ShapeParser* (*GetShapeParser)();

        // Duyệt tất cả các DLL đã tải và lấy con trỏ hàm GetShapeParser của từng DLL, sau đó đăng ký parser tương ứng với factory
        for (auto it = DLL_Loader.begin(); it != DLL_Loader.end(); ++it)
        {
            if (it->second != NULL)
            {
                GetShapeParser getParser = (GetShapeParser)GetProcAddress(it->second, ("get" + it->first + "Parser").c_str());
                shared_ptr<ShapeParser> pParser = shared_ptr<ShapeParser>(getParser());
                factory->registerWith(it->first, pParser);
            }
        }

        // Tạo ra một đối tượng ShapePrintingContext
        shared_ptr<ShapePrintingContext> printStrategy = ShapePrintingContext::getInstance();

        // Định nghĩa một function pointer để lấy ra đối tượng ShapePrintingStrategy từ file DLL
        typedef ShapePrintingStrategy* (*GetSquarePrintingStrategy)();

        // Duyệt tất cả các DLL đã tải và lấy con trỏ hàm GetSquarePrintingStrategy của từng DLL, sau đó đăng ký strategy tương ứng với printStrategy
        for (auto it = DLL_Loader.begin(); it != DLL_Loader.end(); ++it)
        {
            if (it->second != NULL)
            {
                GetSquarePrintingStrategy getStrategy = (GetSquarePrintingStrategy)GetProcAddress(it->second, ("get" + it->first + "PrintingStrategy").c_str());
                shared_ptr<ShapePrintingStrategy> pStrategy = shared_ptr<ShapePrintingStrategy>(getStrategy());
                printStrategy->registerPrintingStrategy(it->first, pStrategy);
            }
        }

        // Đọc dữ liệu từ tệp văn bản
        _setmode(_fileno(stdout), _O_U16TEXT);

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
                    shared_ptr<Shape> newShape = shared_ptr<Shape>(parser->parse(data));

                    if (newShape == nullptr)
                    {
                        continue;
                    }

                    listOfShapes.push_back(newShape);
                }
            }

            reader.close();     // Nhớ đóng file sau khi mở
        }

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

        // Giải phóng thư viện DLL đã load vào bộ nhớ 
        for (auto it = DLL_Loader.begin(); it != DLL_Loader.end(); ++it)
        {
            FreeLibrary(it->second);
        }
    }
    catch (const std::exception& ex)
    {
        cout << "Error: " << ex.what() << endl;
    }

    system("pause");
    return 0;
}