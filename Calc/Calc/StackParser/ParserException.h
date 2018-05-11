#pragma once
#include "stdafx.h"
#include "BaseException.h"

class CParserException : public CBaseException
{
public:
	CParserException(const char* msg, long line, long column);
	virtual ~CParserException();

private:


};
