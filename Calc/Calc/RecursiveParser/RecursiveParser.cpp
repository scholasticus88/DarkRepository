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

	throw CParserException("Unexpected token...", GetLine(), GetColumn());
}

bool CRecursiveParser::Expect(Symbols symbol)
{
	ILexerTokenPtr pToken = Symbol();
	return (*pToken == symbol);
}

ILexerTokenPtr CRecursiveParser::Symbol()
{
	ILexerTokenPtr pToken = m_pLexer->GetCurrentToken();

	if (pToken == nullptr)
		throw CParserException("No token available.", GetLine(), GetColumn());

	return pToken;
}

void CRecursiveParser::Parse_Command()
{
	if (Expect(Symbols::T_VAR))
	{
		Parse_Declaration();
	}
	else if (Expect(Symbols::T_WRITE) || Expect(Symbols::T_WRITELN))
	{
		Parse_Function();
	} 
	else if (Expect(Symbols::T_SEMICOL))
	{
		Parse_EmptyCommand();
	}
	else
	{
		// exc
	}
}

void CRecursiveParser::Parse_Declaration()
{
	Accept(Symbols::T_VAR);
	Accept(Symbols::T_IDENT);

	Parse_Declaration_Rest();

	Accept(Symbols::T_SEMICOL);
}

void CRecursiveParser::Parse_Declaration_Rest()
{
	if (Expect(Symbols::T_ASS))
	{
		Accept(Symbols::T_ASS);

		Parse_Expression();
	}
}

void CRecursiveParser::Parse_Expression()
{
	
}

void CRecursiveParser::Parse_Function()
{
	if (Expect(Symbols::T_WRITE))
	{
		Accept(Symbols::T_WRITE);
	}
	else if (Expect(Symbols::T_WRITELN))
	{
		Accept(Symbols::T_WRITELN);
	}
	else
	{
		throw CParserException("Unexpected function", GetLine(), GetColumn());
	}
}

void CRecursiveParser::Parse_EmptyCommand()
{
	Accept(Symbols::T_SEMICOL);
}

long CRecursiveParser::GetLine() const
{
	return m_pLexer->GetCurrentLine();
}

long CRecursiveParser::GetColumn() const
{
	return m_pLexer->GetCurrentColumn();
}


//////////////////////////////////////////////////////////////////////////
// Factory
//////////////////////////////////////////////////////////////////////////
IParserPtr PARSER_DLL_EXPORT CreateRecursiveParser()
{
	return std::make_shared<CRecursiveParser>();
}