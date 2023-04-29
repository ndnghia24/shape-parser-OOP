#include "ShapePrintingContext.h"

ShapePrintingStrategy* _printingStrategy = nullptr;
shared_ptr<ShapePrintingContext> ShapePrintingContext::_instance = nullptr;

ShapePrintingContext::ShapePrintingContext()
{

}

shared_ptr<ShapePrintingContext> ShapePrintingContext::getInstance() {
	if (_instance == nullptr)
	{
		_instance = shared_ptr<ShapePrintingContext>(new ShapePrintingContext);
	}
	return _instance;
}

void ShapePrintingContext::registerPrintingStrategy(string type, shared_ptr<ShapePrintingStrategy> strategy)
{
	_listPrintingStrategy.insert({ type, strategy });
}

void ShapePrintingContext::setPrintingStrategy(string type)
{
	_printingStrategy = _listPrintingStrategy[type];
}

void ShapePrintingContext::printData(Shape* _shape)
{
	_printingStrategy->printData(_shape);
}

void ShapePrintingContext::printTable(Shape* _shape)
{
	_printingStrategy->printTable(_shape);
}

string ShapePrintingContext::toString()
{
	return string("ShapePrintingContext");
}
