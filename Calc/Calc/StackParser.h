#pragma once
#include "Lexer.h"
#include "ParseTable.h"

class CStackParser
{
public:
	CStackParser();
	~CStackParser();

	void Parse(std::string filename);

private:
	CParseTable m_Rules;
};