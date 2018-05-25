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

const char* CLexToken::GetString() const
{
	return std::to_string(m_type).c_str();
}

bool CLexToken::operator==(Symbols symbol) const
{
	return (m_type == symbol);
}