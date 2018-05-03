#include "stdafx.h"
#include "Lexer.h"

CLexer::CLexer():
	m_lLine(0),
	m_lColumn(0)
{

}

void CLexer::Init(std::string filename)
{
	m_filename = filename;
	m_lLine = 0;
	m_lColumn = 0;

	m_ifs.open(filename, std::ifstream::in);

	if (m_ifs.fail())
	{
		throw new std::exception("Failed to init lexer.");
	}

	NextSymbol();
}

long CLexer::GetCurrentLine() const
{
	return m_lLine;
}

long CLexer::GetCurrentColumn() const
{
	return m_lColumn;
}

LexTokenPtr CLexer::GetNextToken()
{
	SkipWhiteSpaces();

	long lLine = m_lLine;
	long lColumn = m_lColumn;

	if (m_cSymbol == '+')
	{
		NextSymbol();
		return std::make_shared<CLexToken>(Symbols::PLUS, lLine, lColumn);
	}
	else if (m_cSymbol == '-')
	{
		NextSymbol();
		return std::make_shared<CLexToken>(Symbols::MINUS, lLine, lColumn);
	}
	else if (isdigit(m_cSymbol))
	{
		do
		{
			NextSymbol();
		} while (isdigit(m_cSymbol));

		return std::make_shared<CLexToken>(Symbols::INTEGER, lLine, lColumn);
	}
	else if (isalpha(m_cSymbol))
	{
		do
		{
			NextSymbol();
		} while (isalnum(m_cSymbol));

		return std::make_shared<CLexToken>(Symbols::IDENT, lLine, lColumn);
	}
	else if (m_cSymbol == -1)
	{
		return nullptr;
	}

	throw new std::exception("Unknown symbol");
}

void CLexer::NextSymbol()
{
	if (!m_ifs.eof())
	{
		if (m_cSymbol == '\n')
		{
			m_lLine++;
			m_lColumn = 0;
		}
		else
		{
			m_lColumn++;
		}

		m_cSymbol = m_ifs.get();
	}
	else
	{
		m_cSymbol = -1;
	}
}

void CLexer::SkipWhiteSpaces()
{
	while (iswspace(m_cSymbol))
	{
		NextSymbol();
	}
}