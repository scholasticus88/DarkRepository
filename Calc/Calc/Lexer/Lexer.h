#pragma once

#include "stdafx.h"
#include "ILexer.h"
#include "Symbols.h"


class CLexer : public ILexer
{
public:
	CLexer();
	virtual void Init(std::string filename) override;
	virtual ILexerTokenPtr GetNextToken() override;

	virtual long GetCurrentLine() const override;
	virtual long GetCurrentColumn() const override;

private:
	std::ifstream m_ifs;
	std::string m_filename;
	char m_cSymbol;

	long m_lLine;
	long m_lColumn;

	std::map<std::string, Symbols> m_mKeywods;

	void InitKeywords();
	void NextSymbol();
	void SkipWhiteSpaces();
	Symbols TranslateKeyword(std::string strTmp);
};

typedef std::shared_ptr<CLexer> LexerPtr;


ILexerPtr LEXER_DLL_EXPORT CreateLexer()
{
	return std::make_shared<CLexer>();
}