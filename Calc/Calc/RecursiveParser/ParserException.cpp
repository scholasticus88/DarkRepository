#include "stdafx.h"
#include "ParserException.h"

CParserException::CParserException(const char* msg, long line, long column):
	CBaseException(msg, line, column)
{

}

CParserException::~CParserException()
{

}

CBaseException::ExceptionType CParserException::GetType() const
{
	return ExceptionType::ParserException;
}