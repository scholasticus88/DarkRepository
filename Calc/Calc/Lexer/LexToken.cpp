#include "stdafx.h"
#include "LexToken.h"

CLexToken::CLexToken(Symbols type, long line, long column):
	m_type(type),
	m_lLine(line),
	m_lColumn(column)
{

}

CLexToken::~CLexToken()
{

}

Symbols CLexToken::GetType() const
{
	return m_type;
}

long CLexToken::GetLine() const
{
	return m_lLine;
}

long CLexToken::GetColumn() const
{
	return m_lColumn;
}