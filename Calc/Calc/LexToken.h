#pragma once

#include "stdafx.h"
#include "Symbols.h"

class CLexToken
{
public:
	CLexToken(Symbols type, long line, long column);
	~CLexToken();

	Symbols GetType() const;
	long GetLine() const;
	long GetColumn() const;

private:
	Symbols m_type;
	long m_lLine;
	long m_lColumn;
};

typedef std::shared_ptr<CLexToken> LexTokenPtr;