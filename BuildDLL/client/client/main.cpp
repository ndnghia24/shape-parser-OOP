#include <iostream>
#include <Windows.h>
#include <vector>
#include <filesystem>
#include <map>

using namespace std;

namespace fs = std::filesystem;

LPCWSTR ConvertStringToLPCWSTR(const std::string& str)
{
	int num_chars = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
	wchar_t* wide_str = new wchar_t[num_chars];
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wide_str, num_chars);
	return wide_str;
}

class Object
{
	virtual std::string toString() = 0;
};

class Shape : public Object
{
public:
	virtual float Area() = 0;
	virtual float Perimeter() = 0;

	std::string toString()
	{
		return std::string("Shape");
	}
};

class IShapeParser : public Object
{
public:
	virtual Shape* parse(std::string data) = 0;

	std::string toString()
	{
		return std::string("IShapeParser");
	}
};

class ShapePrintingStrategy : public Object
{
public:
	virtual void printData(Shape* shape) = 0;
	virtual void printTable(Shape* shape) = 0;

	std::string toString()
	{
		return std::string("ShapePrintingStrategy");
	}
};

int main()
{
	vector<string> DLL;
	string filename;

	for (const auto& entry : fs::directory_iterator("."))
	{
		if (entry.path().extension() == ".dll")
		{
			filename = entry.path().filename().string();
			DLL.push_back(filename.substr(0, filename.find('.')));
			std::cout << DLL[DLL.size()-1] << std::endl;
		}
	}

	map<string, HINSTANCE> DLL_Loader;

	for (const auto& x : DLL)
	{
		LPCWSTR fileFormat = ConvertStringToLPCWSTR(x + ".dll");
		DLL_Loader.insert({x, LoadLibrary(fileFormat)});

		if (DLL_Loader[x] != NULL)
		{
			cout << "Doc " << (x + ".dll") << " thanh cong!" << endl;
		}
	}

	typedef Shape* (*GetSquareFunc)(float);

	if (DLL_Loader["Square"] != NULL)
	{
		GetSquareFunc getSquare = (GetSquareFunc)GetProcAddress(DLL_Loader["Square"], "getSquare");
		if (getSquare == NULL) {
			// xử lý lỗi khi không tìm thấy hàm trong DLL
		}

		Shape* pSquare = getSquare(2.0f);

		cout << pSquare->toString();

		// sử dụng đối tượng pCircle ở đây

		delete pSquare;
	}

	system("pause");
	return 0;
}