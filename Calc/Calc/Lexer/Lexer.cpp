#include "stdafx.h"
#include "Lexer.h"
#include "LexToken.h"

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

	InitKeywords();

	NextSymbol();
	GetNextToken();
}

void CLexer::InitKeywords()
{
	m_mKeywods["var"] = Symbols::T_VAR;
	m_mKeywods["write"] = Symbols::T_WRITE;
	m_mKeywods["writeln"] = Symbols::T_WRITELN;
}

long CLexer::GetCurrentLine() const
{
	return m_lLine;
}

long CLexer::GetCurrentColumn() const
{
	return m_lColumn;
}

ILexerTokenPtr CLexer::GetNextToken()
{
	SkipWhiteSpaces();

	long lLine = m_lLine;
	long lColumn = m_lColumn;

	if (m_cSymbol == '+')
	{
		NextSymbol();
		return (m_pCurrentToken = std::make_shared<CLexToken>(Symbols::T_PLUS, lLine, lColumn));
	}
	else if (m_cSymbol == '-')
	{
		NextSymbol();
		return (m_pCurrentToken = std::make_shared<CLexToken>(Symbols::T_MINUS, lLine, lColumn));
	}
	else if (m_cSymbol == '*')
	{
		NextSymbol();
		return (m_pCurrentToken = std::make_shared<CLexToken>(Symbols::T_MUL, lLine, lColumn));
	}
	else if (m_cSymbol == '/')
	{
		NextSymbol();
		return (m_pCurrentToken = std::make_shared<CLexToken>(Symbols::T_DIV, lLine, lColumn));
	}
	else if (m_cSymbol == '=')
	{
		NextSymbol();
		return (m_pCurrentToken = std::make_shared<CLexToken>(Symbols::T_ASS, lLine, lColumn));
	}
	else if (m_cSymbol == '(')
	{
		NextSymbol();
		return (m_pCurrentToken = std::make_shared<CLexToken>(Symbols::T_LBRACK, lLine, lColumn));
	}
	else if (m_cSymbol == ')')
	{
		NextSymbol();
		return (m_pCurrentToken = std::make_shared<CLexToken>(Symbols::T_RBRACK, lLine, lColumn));
	}
	else if (m_cSymbol == '!')
	{
		NextSymbol();
		return (m_pCurrentToken = std::make_shared<CLexToken>(Symbols::T_FACTOR, lLine, lColumn));
	}
	else if (m_cSymbol == ';')
	{
		NextSymbol();
		return (m_pCurrentToken = std::make_shared<CLexToken>(Symbols::T_SEMICOL, lLine, lColumn));
	}
	else if (isdigit(m_cSymbol))
	{
		do
		{
			NextSymbol();
		} while (isdigit(m_cSymbol));

		return (m_pCurrentToken = std::make_shared<CLexToken>(Symbols::T_INTEGER, lLine, lColumn));
	}
	else if (isalpha(m_cSymbol))
	{
		std::string strTmp;

		do
		{
			strTmp += m_cSymbol;
			NextSymbol();
		} while (isalnum(m_cSymbol));

		Symbols symbol = TranslateKeyword(strTmp);

		return (m_pCurrentToken = std::make_shared<CLexToken>(symbol, lLine, lColumn));
	}
	else if (m_cSymbol == -1)
	{
		return (m_pCurrentToken = std::make_shared<CLexToken>(Symbols::T_END, lLine, lColumn));
	}

	throw new std::exception("Unknown symbol");
}

ILexerTokenPtr CLexer::GetCurrentToken()
{
	return m_pCurrentToken;
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

Symbols CLexer::TranslateKeyword(std::string strTmp)
{
	std::transform(strTmp.begin(), strTmp.end(), strTmp.begin(), ::tolower);

	std::map<std::string, Symbols>::iterator it = m_mKeywods.find(strTmp);
	if (it != m_mKeywods.end())
	{
		return it->second;
	}

	return Symbols::T_IDENT;
}