#pragma once
#include "ParseTable.h"
#include "ILexer.h"

class CStackParser
{
public:
	CStackParser();
	~CStackParser();

	void Parse(std::string filename);

private:
	CParseTable m_Rules;
};