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

	bool Expect(Symbols symbol);
	void Accept(Symbols symbol);
	ILexerTokenPtr Symbol();

	void Parse_Declaration();
	void Parse_Declaration_Rest();
	void Parse_Expression();
	void Parse_Command();
	void Parse_Function();
	void Parse_EmptyCommand();

	long GetLine() const;
	long GetColumn() const;

};

IParserPtr PARSER_DLL_EXPORT CreateRecursiveParser();