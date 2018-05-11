#include "stdafx.h"
#include "ParserException.h"

CParserException::CParserException(const char* msg, long line, long column):
	CBaseException(msg, line, column)
{

}

CParserException::~CParserException()
{

}