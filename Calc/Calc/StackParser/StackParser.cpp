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
	stack.push(Symbols::NT_CODE);

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
			int iRule = m_Rules(symbol, token->GetType());

			switch (iRule)
			{
			case 1:
				stack.pop();
				stack.push(Symbols::NT_COMMAND_LIST);
				break;
			case 2:
				stack.pop();
				stack.push(Symbols::NT_COMMAND_LIST);
				stack.push(Symbols::NT_COMMAND);
				break;
			case 3:
				stack.pop();
				break;
			case 4:
				stack.pop();
				stack.push(Symbols::NT_DECLARATION);
				break;
			case 5:
				stack.pop();
				stack.push(Symbols::NT_ASSIGN);
				break;
			case 6:
				stack.pop();
				stack.push(Symbols::NT_FUNCTION);
				break;
			case 7:
				stack.pop();
				stack.push(Symbols::NT_EMPTY);
				break;
			case 8:
				stack.pop();
				stack.push(Symbols::NT_DECLARATION_REST);
				stack.push(Symbols::T_IDENT);
				stack.push(Symbols::T_VAR);
				break;
			case 9:
				stack.pop();
				stack.push(Symbols::T_SEMICOL);
				stack.push(Symbols::NT_EXPR);
				stack.push(Symbols::T_ASS);
				break;
			case 10:
				stack.pop();
				stack.push(Symbols::T_SEMICOL);
				stack.push(Symbols::NT_EXPR);
				stack.push(Symbols::T_ASS);
				stack.push(Symbols::T_IDENT);
				break;
			case 11:
				stack.pop();
				stack.push(Symbols::T_SEMICOL);
				break;
			case 12:
				stack.pop();
				stack.push(Symbols::NT_EXPR_REST);
				stack.push(Symbols::NT_MULTIPL);
				break;
			case 13:
				stack.pop();
				stack.push(Symbols::NT_EXPR_REST);
				stack.push(Symbols::NT_MULTIPL);
				stack.push(Symbols::T_PLUS);
				break;
			case 14:
				stack.pop();
				stack.push(Symbols::NT_EXPR_REST);
				stack.push(Symbols::NT_MULTIPL);
				stack.push(Symbols::T_MINUS);
				break;
			case 15:
				stack.pop();
				break;
			case 16:
				stack.pop();
				stack.push(Symbols::NT_MULTIPLE_REST);
				stack.push(Symbols::NT_MULTIPLICANT);
				break;
			case 17:
				stack.pop();
				stack.push(Symbols::NT_MULTIPLE_REST);
				stack.push(Symbols::NT_MULTIPLICANT);
				stack.push(Symbols::T_MUL);
				break;
			case 18:
				stack.pop();
				stack.push(Symbols::NT_MULTIPLE_REST);
				stack.push(Symbols::NT_MULTIPLICANT);
				stack.push(Symbols::T_DIV);
				break;
			case 19:
				stack.pop();
				break;
			case 20:
				stack.pop();
				stack.push(Symbols::NT_FACTOR);
				stack.push(Symbols::T_RBRACK);
				stack.push(Symbols::NT_EXPR);
				stack.push(Symbols::T_LBRACK);
				break;
			case 21:
				stack.pop();
				stack.push(Symbols::NT_FACTOR);
				stack.push(Symbols::T_IDENT);
				break;
			case 22:
				stack.pop();
				stack.push(Symbols::NT_FACTOR);
				stack.push(Symbols::T_INTEGER);
				break;
			case 23:
				stack.pop();
				stack.push(Symbols::T_DOUBLE);
				break;
			case 24:
				stack.pop();
				stack.push(Symbols::T_FACTOR);
				break;
			case 25:
				stack.pop();
				break;
			case 26:
				stack.pop();
				stack.push(Symbols::T_WRITE);
				break;
			case 27:
				stack.pop();
				stack.push(Symbols::T_WRITELN);
				break;
			default:
				throw new std::exception("Unknown rule");
				break;
			}
		}
	}
}