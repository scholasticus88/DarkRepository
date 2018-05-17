#pragma once

#include "stdafx.h"
#include "IParser.h"
#include "ILexer.h"


class CRecursiveParser : public IParser
{
public:
	CRecursiveParser();
	~CRecursiveParser();

	virtual void Parse(const std::string& filename) override;

private:
	ILexerPtr m_pLexer;

	void Accept(Symbols symbol);
};

IParserPtr PARSER_DLL_EXPORT CreateRecursiveParser();