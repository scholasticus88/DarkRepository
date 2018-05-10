#pragma once

#include "stdafx.h"
#include "ILexerToken.h"

class LEXER_DLL_EXPORT ILexer
{
public:
	virtual void Init(std::string filename) = 0;
	virtual ILexerTokenPtr GetNextToken() = 0;

	virtual long GetCurrentLine() const = 0;
	virtual long GetCurrentColumn() const = 0;

};

typedef std::shared_ptr<ILexer> ILexerPtr;

ILexerPtr LEXER_DLL_EXPORT CreateLexer();