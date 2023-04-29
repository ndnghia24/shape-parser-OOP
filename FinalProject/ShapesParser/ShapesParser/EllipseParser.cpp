#include "EllipseParser.h"

Shape* EllipseParser::parse(string data) noexcept(false) 
{
    try {
        Shape* result = nullptr;

        stringstream line(data);
        string buffer;

        // Lấy giá trị của bán kính trục lớn và trục bé
        getline(line, buffer, '=');
        getline(line, buffer, ',');
        float a = stof(buffer);

        getline(line, buffer, '=');
        getline(line, buffer);
        float b = stof(buffer);

        if (a <= 0 || b <= 0) {
            throw exception("");
        }

        result = new Ellipse(a, b);

        return result;
    }
    catch (const std::exception&) {
        return nullptr;
    }
}

string EllipseParser::toString()
{
    return string("EllipseParser");
}
