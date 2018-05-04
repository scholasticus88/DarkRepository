#pragma once

#include "stdafx.h"
#include "Symbols.h"
#include "LexToken.h"


class CLexer
{
public:
	CLexer();
	void Init(std::string filename);
	LexTokenPtr GetNextToken();

	long GetCurrentLine() const;
	long GetCurrentColumn() const;

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