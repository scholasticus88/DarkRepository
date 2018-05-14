#include "stdafx.h"
#include "LexerException.h"


CLexerException::CLexerException(const char* msg, long line, long column):
	CBaseException(msg, line, column)
{
	
}

CLexerException::~CLexerException()
{
	
}

CBaseException::ExceptionType CLexerException::GetType() const
{
	return ExceptionType::LexerException;
}