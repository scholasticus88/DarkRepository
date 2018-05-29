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

	Parse_Code();
}

void CRecursiveParser::Accept(Symbols symbol)
{
	ILexerTokenPtr pToken = m_pLexer->GetCurrentToken();
	if (pToken->GetType() == symbol)
	{
		std::cout << pToken->GetType() << std::endl;
		m_pLexer->Next();
	}
	else
	{
		std::stringstream ss;
		ss << "Unexpected token [" << SymbolAsString() << "]";
		throw CParserException(ss.str().c_str(), GetLine(), GetColumn());
	}	
}

bool CRecursiveParser::Expect(const std::vector<Symbols>& vs)
{
	ILexerTokenPtr pToken = Symbol();

	std::vector<Symbols>::const_iterator it = std::find(vs.begin(), vs.end(), pToken->GetType());

	return (it != std::end(vs));
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

std::string CRecursiveParser::SymbolAsString()
{
	ILexerTokenPtr pToken = m_pLexer->GetCurrentToken();

	if (pToken == nullptr)
		throw CParserException("No token available.", GetLine(), GetColumn());

	return std::string(pToken->GetString());
}

void CRecursiveParser::Parse_Code()
{
	Parse_CommandList();
}

void CRecursiveParser::Parse_CommandList()
{
	while (Expect({Symbols::T_IDENT, Symbols::T_SEMICOL, Symbols::T_WRITE, Symbols::T_WRITELN, Symbols::T_KW_INT, Symbols::T_KW_DOUBLE, Symbols::T_KW_STRING, Symbols::T_KW_AUTO, Symbols::T_KW_BOOL}))
	{
		Parse_Command();
	}

	if (!Expect(Symbols::T_END))
	{
		std::stringstream ss;
		ss << "Unexpected token '" << SymbolAsString() << "' when parsing commandlist.";
		throw CParserException(ss.str().c_str(), GetLine(), GetColumn());
	}
}

void CRecursiveParser::Parse_Command()
{
	if (Expect({Symbols::T_KW_INT, Symbols::T_KW_DOUBLE, Symbols::T_KW_STRING, Symbols::T_KW_AUTO, Symbols::T_KW_BOOL}))
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
	else if (Expect(Symbols::T_IDENT))
	{
		Parse_Assign();
	}
	else
	{
		std::stringstream ss;
		ss << "Unexpected token '" << SymbolAsString() << "' when parsing command.";
		throw CParserException(ss.str().c_str(), GetLine(), GetColumn());
	}
}

void CRecursiveParser::Parse_Declaration()
{
	Parse_DataType();

	Accept(Symbols::T_IDENT);

	Parse_Declaration_Rest();

	Accept(Symbols::T_SEMICOL);
}

void CRecursiveParser::Parse_Assign()
{
	Accept(Symbols::T_IDENT);
	Accept(Symbols::T_ASS);

	Parse_RightSide();

	Accept(Symbols::T_SEMICOL);
}

void CRecursiveParser::Parse_Declaration_Rest()
{
	if (Expect(Symbols::T_ASS))
	{
		Accept(Symbols::T_ASS);

		Parse_RightSide();
	}
	else if (Expect(Symbols::T_SEMICOL))
	{
		// rule 10
	}
}

void CRecursiveParser::Parse_RightSide()
{
	if (Expect({Symbols::T_LBRACK, Symbols::T_IDENT, Symbols::T_INTEGER, Symbols::T_DOUBLE}))
	{
		Parse_Expression();
	}
	else if (Expect(Symbols::T_STRING))
	{
		Parse_StringExpr();
	}
	else
	{
		std::stringstream ss;
		ss << "Unexpected token '" << SymbolAsString() << "' when parsing right side of an assignment.";
		throw CParserException(ss.str().c_str(), GetLine(), GetColumn());
	}
}

void CRecursiveParser::Parse_StringExpr()
{
	Accept(Symbols::T_STRING);
}

void CRecursiveParser::Parse_Expression()
{
	if (Expect({Symbols::T_LBRACK, Symbols::T_IDENT, Symbols::T_INTEGER, Symbols::T_DOUBLE}))
	{
		Parse_Multiple();

		Parse_ExpressionRest();
	}
	else
	{
		std::stringstream ss;
		ss << "Unexpected token '" << SymbolAsString() << "' when parsing expression.";
		throw CParserException(ss.str().c_str(), GetLine(), GetColumn());
	}
}

void CRecursiveParser::Parse_ExpressionRest()
{
	if (Expect(Symbols::T_PLUS))
	{
		Accept(Symbols::T_PLUS);
		Parse_Multiple();
		Parse_ExpressionRest();
	}
	else if (Expect(Symbols::T_MINUS))
	{
		Accept(Symbols::T_MINUS);
		Parse_Multiple();
		Parse_ExpressionRest();
	}
	else if (Expect({Symbols::T_SEMICOL, Symbols::T_RBRACK}))
	{
		// rule #15
	}
	else
	{
		std::stringstream ss;
		ss << "Unexpected token '" << SymbolAsString() << "' when parsing expression_rest.";
		throw CParserException(ss.str().c_str(), GetLine(), GetColumn());
	}
}

void CRecursiveParser::Parse_Multiple()
{
	if (Expect({Symbols::T_LBRACK, Symbols::T_IDENT, Symbols::T_INTEGER, Symbols::T_DOUBLE}))
	{
		Parse_Multiplicant();
		Parse_MultipleRest();
	}
	else
	{
		std::stringstream ss;
		ss << "Unexpected token '" << SymbolAsString() << "' when parsing multiple.";
		throw CParserException(ss.str().c_str(), GetLine(), GetColumn());
	}
}

void CRecursiveParser::Parse_MultipleRest()
{
	if (Expect(Symbols::T_MUL))
	{
		Accept(Symbols::T_MUL);
		Parse_Multiplicant();
		Parse_MultipleRest();
	}
	else if (Expect(Symbols::T_DIV))
	{
		Accept(Symbols::T_DIV);
		Parse_Multiplicant();
		Parse_MultipleRest();
	}
	else if (Expect({Symbols::T_RBRACK, Symbols::T_PLUS, Symbols::T_MINUS, Symbols::T_SEMICOL}))
	{
		// rule #19
	}
	else
	{
		std::stringstream ss;
		ss << "Unexpected token '" << SymbolAsString() << "' when parsing multiple_rest.";
		throw CParserException(ss.str().c_str(), GetLine(), GetColumn());
	}
}

void CRecursiveParser::Parse_Multiplicant()
{
	if (Expect(Symbols::T_LBRACK))
	{
		Accept(Symbols::T_LBRACK);
		Parse_Expression();
		Accept(Symbols::T_RBRACK);
		Parse_Factor();
	}
	else if (Expect(Symbols::T_IDENT))
	{
		Accept(Symbols::T_IDENT);
		Parse_Factor();
	}
	else if (Expect(Symbols::T_INTEGER))
	{
		Accept(Symbols::T_INTEGER);
		Parse_Factor();
	}
	else if (Expect(Symbols::T_DOUBLE))
	{
		Accept(Symbols::T_DOUBLE);
	}
	else
	{
		std::stringstream ss;
		ss << "Unexpected token '" << SymbolAsString() << "' when parsing multiplicant.";
		throw CParserException(ss.str().c_str(), GetLine(), GetColumn());
	}
}

void CRecursiveParser::Parse_Factor()
{
	if (Expect(Symbols::T_FACTOR))
	{
		Accept(Symbols::T_FACTOR);
	}
	else if (Expect({Symbols::T_MUL, Symbols::T_DIV, Symbols::T_PLUS, Symbols::T_MINUS, Symbols::T_SEMICOL, Symbols::T_RBRACK}))
	{
		// rule #25
	}
	else
	{
		std::stringstream ss;
		ss << "Unexpected token '" << SymbolAsString() << "' when parsing factor.";
		throw CParserException(ss.str().c_str(), GetLine(), GetColumn());
	}
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
		std::stringstream ss;
		ss << "Unexpected token '" << SymbolAsString() << "' when parsing function.";
		throw CParserException(ss.str().c_str(), GetLine(), GetColumn());
	}
}

void CRecursiveParser::Parse_DataType()
{
	if (Expect(Symbols::T_KW_INT))
	{
		Accept(Symbols::T_KW_INT);
	}
	else if (Expect(Symbols::T_KW_DOUBLE))
	{
		Accept(Symbols::T_KW_DOUBLE);
	}
	else if (Expect(Symbols::T_KW_STRING))
	{
		Accept(Symbols::T_KW_STRING);
	}
	else if (Expect(Symbols::T_KW_BOOL))
	{
		Accept(Symbols::T_KW_BOOL);
	}
	else if (Expect(Symbols::T_KW_AUTO))
	{
		Accept(Symbols::T_KW_AUTO);
	}
	else
	{
		std::stringstream ss;
		ss << "Unknown data type '" << SymbolAsString() << "' when parsing declaration.";
		throw CParserException(ss.str().c_str(), GetLine(), GetColumn());
	}
}

void CRecursiveParser::Parse_EmptyCommand()
{
	Accept(Symbols::T_SEMICOL);
}


//////////////////////////////////////////////////////////////////////////
// Position
//////////////////////////////////////////////////////////////////////////
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