#include "stdafx.h"
#include "StackParser.h"


CStackParser::CStackParser()
{
	
}

CStackParser::~CStackParser()
{

}

void CStackParser::Parse(std::string filename)
{
	ILexerPtr pLexer = CreateLexer();
	pLexer->Init(filename);

	std::stack<Symbols> stack;
	stack.push(Symbols::T_END);
	stack.push(Symbols::NT_EXPR);

	while (stack.size() > 0)
	{
		Symbols symbol = stack.top();
		ILexerTokenPtr token = pLexer->GetCurrentToken();

		if (symbol == token->GetType())
		{
			stack.pop();
			pLexer->GetNextToken();
		}
		else
		{
			int rule = m_Rules(symbol, token->GetType());
		}
	}



	/*
	ILexerTokenPtr token = pLexer->GetNextToken();
	while (token != nullptr)
	{
		std::cout << "[" << token->GetLine() << ", " << token->GetColumn() << "]: " << token->GetType() << std::endl;

		if (token->GetType() == Symbols::T_END)
			break;

		token = pLexer->GetNextToken();
	}
	*/
}