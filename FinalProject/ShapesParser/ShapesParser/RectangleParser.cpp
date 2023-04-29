#include "RectangleParser.h"

Shape* RectangleParser::parse(string data)
{
	try
	{
        Shape* result = nullptr;

        stringstream line(data);
        string buffer;

        getline(line, buffer, '=');
        getline(line, buffer, ',');
        float w = stof(buffer);

        if (w <= 0)
        {
            throw exception("");
        }

        getline(line, buffer, '=');
        getline(line, buffer);
        float h = stof(buffer);

        if (h <= 0)
        {
            throw exception("");
        }

        result = new Rectangle(w, h);

        return result;
	}
	catch (const std::exception&)
	{
        return nullptr;
	}
}

string RectangleParser::toString()
{
    return string("RectangleParser");
}
