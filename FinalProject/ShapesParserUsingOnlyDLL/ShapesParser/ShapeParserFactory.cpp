#include "ShapeParserFactory.h"

shared_ptr<ShapeParserFactory> ShapeParserFactory::_instance = nullptr;

ShapeParserFactory::ShapeParserFactory()
{
}

shared_ptr<ShapeParserFactory> ShapeParserFactory::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = shared_ptr<ShapeParserFactory>(new ShapeParserFactory);
    }

    return _instance;
}

void ShapeParserFactory::registerWith(string type, shared_ptr<ShapeParser> parser)
{
    _prototypes.insert({ type, parser });
}

shared_ptr<ShapeParser> ShapeParserFactory::mode(string type)
{
    shared_ptr<ShapeParser> parser = nullptr;

    if (_prototypes.contains(type)) {
        parser = _prototypes[type];
    }

    return parser;
}

string ShapeParserFactory::toString()
{
    return string("ParserFactory");
}
