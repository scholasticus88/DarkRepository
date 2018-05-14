#pragma once
#include "BaseException.h"


class LEXER_DLL_EXPORT CLexerException : public CBaseException
{
public:
	CLexerException(const char* msg, long line, long column);
	virtual ~CLexerException();

	virtual CBaseException::ExceptionType GetType() const override;
};
