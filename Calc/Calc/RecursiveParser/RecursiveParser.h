#pragma once

#include "stdafx.h"
#include "IParser.h"


class CRecursiveParser : public IParser
{
public:
	CRecursiveParser();
	~CRecursiveParser();

	virtual void Parse(std::string filename) override;

private:
	
};

IParserPtr PARSER_DLL_EXPORT CreateRecursiveParser();