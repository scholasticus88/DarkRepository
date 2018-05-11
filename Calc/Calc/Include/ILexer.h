#pragma once

#include "stdafx.h"
#include "ILexerToken.h"

class LEXER_DLL_EXPORT ILexer
{
public:
	virtual void Init(std::string filename) = 0;
	virtual ILexerTokenPtr Next() = 0;
	virtual ILexerTokenPtr GetCurrentToken() = 0;

	virtual long GetCurrentLine() const = 0;
	virtual long GetCurrentColumn() const = 0;

	ILexerTokenPtr operator*()
	{
		return GetCurrentToken();
	}
};

typedef std::shared_ptr<ILexer> ILexerPtr;

ILexerPtr LEXER_DLL_EXPORT CreateLexer();