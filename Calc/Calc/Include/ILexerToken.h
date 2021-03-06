#pragma once

#include "stdafx.h"
#include "Symbols.h"

class LEXER_DLL_EXPORT ILexerToken
{
public:
	virtual Symbols GetType() const = 0;
	virtual long GetLine() const = 0;
	virtual long GetColumn() const = 0;
	virtual const char* GetString() const = 0;

	bool operator==(Symbols s)
	{
		return (GetType() == s);
	}

	operator const char*()
	{
		return GetString();
	}

};

typedef std::shared_ptr<ILexerToken> ILexerTokenPtr;