#pragma once
#include "ParseTable.h"
#include "Export.h"
#include "ILexer.h"
#include "IParser.h"


class CStackParser : public IParser
{
public:
	CStackParser();
	~CStackParser();

	virtual void Parse(const std::string& filename) override;

private:
	CParseTable m_Rules;
};

IParserPtr PARSER_DLL_EXPORT CreateStackParser();