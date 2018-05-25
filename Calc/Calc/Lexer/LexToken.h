#pragma once

#include "stdafx.h"
#include "Symbols.h"
#include "ILexerToken.h"

class CLexToken : public ILexerToken
{
public:
	CLexToken(Symbols type, long line, long column);
	~CLexToken();

	bool operator==(Symbols symbol) const;

	virtual Symbols GetType() const override;
	virtual long GetLine() const override;
	virtual long GetColumn() const override;
	virtual const char* GetString() const override;

private:
	Symbols m_type;
	long m_lLine;
	long m_lColumn;
};

typedef std::shared_ptr<CLexToken> LexTokenPtr;