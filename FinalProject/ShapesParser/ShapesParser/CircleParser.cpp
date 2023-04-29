#include "CircleParser.h"

Shape* CircleParser::parse(string data)
{
	try
	{
        Shape* result = nullptr;

        stringstream line(data);
        string buffer;

        getline(line, buffer, '=');
        getline(line, buffer);
        float r = stof(buffer);

        if (r <= 0)
        {
            throw exception("");
        }

        result = new Circle(r);

        return result;
	}
	catch (const std::exception&)
	{
        return nullptr;
	}
}

string CircleParser::toString()
{
    return string("CircleParser");
}
