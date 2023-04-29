#include "SquareParser.h"

Shape* SquareParser::parse(string data)
{
	try
	{
		Shape* result = nullptr;

		stringstream line(data);
		string buffer;

		getline(line, buffer, '=');
		getline(line, buffer);
		float a = stof(buffer);

		if (a <= 0)
		{
			throw exception("");
		}

		result = new Square(a);

		return result;
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
}

string SquareParser::toString()
{
	return string("SquareParser");
}
