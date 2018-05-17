#include "stdafx.h"
#include "RecursiveParser.h"
#include "ParserException.h"


CRecursiveParser::CRecursiveParser()
{
	m_pLexer = CreateLexer();
}

CRecursiveParser::~CRecursiveParser()
{
}

void CRecursiveParser::Parse(const std::string& filename)
{
	m_pLexer->Init(filename);

}

void CRecursiveParser::Accept(Symbols symbol)
{
	ILexerTokenPtr pToken = m_pLexer->GetCurrentToken();
	if (pToken->GetType() == symbol)
	{
		m_pLexer->Next();
	}

	throw CParserException("Unexpected token...", 0, 0);
}




//////////////////////////////////////////////////////////////////////////
// Factory
//////////////////////////////////////////////////////////////////////////
IParserPtr PARSER_DLL_EXPORT CreateRecursiveParser()
{
	return std::make_shared<CRecursiveParser>();
}