#include "stdafx.h"
#include "RecursiveParser.h"

CRecursiveParser::CRecursiveParser()
{
}

CRecursiveParser::~CRecursiveParser()
{
}

void CRecursiveParser::Parse(std::string filename)
{

}


IParserPtr PARSER_DLL_EXPORT CreateRecursiveParser()
{
	return std::make_shared<CRecursiveParser>();
}