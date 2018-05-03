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
	LexerPtr pLexer = std::make_shared<CLexer>();
	pLexer->Init(filename);

	std::stack<Symbols> stack;
	stack.push(Symbols::END);
	stack.push(Symbols::NT_EXPR);

	


	LexTokenPtr token = pLexer->GetNextToken();
	while (token != nullptr)
	{
		std::cout << "[" << token->GetLine() << ", " << token->GetColumn() << "]: " << token->GetType() << std::endl;

		token = pLexer->GetNextToken();
	}
}