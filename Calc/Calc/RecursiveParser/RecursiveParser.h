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

	bool Expect(const std::vector<Symbols>& vs);
	bool Expect(Symbols symbol);
	void Accept(Symbols symbol);
	ILexerTokenPtr Symbol();

	void Parse_Code();
	void Parse_CommandList();
	void Parse_Command();
	void Parse_Assign();
	void Parse_Declaration();
	void Parse_Declaration_Rest();
	void Parse_Expression();
	void Parse_Multiple();
	void Parse_ExpressionRest();
	void Parse_Multiplicant();
	void Parse_MultipleRest();
	void Parse_Factor();
	void Parse_Function();
	void Parse_EmptyCommand();

	long GetLine() const;
	long GetColumn() const;

};

IParserPtr PARSER_DLL_EXPORT CreateRecursiveParser();