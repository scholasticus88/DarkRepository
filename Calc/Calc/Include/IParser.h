#pragma once

#include "IParser.h"

class PARSER_DLL_EXPORT IParser
{
public:
	virtual void Parse(const std::string& filename) = 0;
};

typedef std::shared_ptr<IParser> IParserPtr;