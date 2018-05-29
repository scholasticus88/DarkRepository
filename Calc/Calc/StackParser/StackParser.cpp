#include "stdafx.h"
#include "StackParser.h"
#include "LexerException.h"
#include "ParserException.h"


CStackParser::CStackParser()
{
	
}

CStackParser::~CStackParser()
{

}

void CStackParser::Parse(const std::string& filename)
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
			try
			{
				stack.pop();
				pLexer->Next();
			}
			catch (CBaseException& e)
			{
				CParserException e2(e.GetMessage(), e.GetLine(), e.GetColumn());
				throw e2;
			}
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
				stack.push(Symbols::NT_DATA_TYPE);
				break;
			case 9:
				stack.pop();
				stack.push(Symbols::T_SEMICOL);
				stack.push(Symbols::NT_RIGHT_SIDE);
				stack.push(Symbols::T_ASS);
				break;
			case 10:
				stack.pop();
				stack.push(Symbols::T_SEMICOL);
				stack.push(Symbols::NT_RIGHT_SIDE);
				stack.push(Symbols::T_ASS);
				stack.push(Symbols::T_IDENT);
				break;
			case 12:
				stack.pop();
				stack.push(Symbols::T_SEMICOL);
				break;
			case 13:
				stack.pop();
				stack.push(Symbols::NT_EXPR);
				break;
			case 14:
				stack.pop();
				stack.push(Symbols::NT_STRING_EXPR);
				break;
			case 22:
				stack.pop();
				stack.push(Symbols::NT_EXPR_REST);
				stack.push(Symbols::NT_MULTIPL);
				break;
			case 23:
				stack.pop();
				stack.push(Symbols::NT_EXPR_REST);
				stack.push(Symbols::NT_MULTIPL);
				stack.push(Symbols::T_PLUS);
				break;
			case 24:
				stack.pop();
				stack.push(Symbols::NT_EXPR_REST);
				stack.push(Symbols::NT_MULTIPL);
				stack.push(Symbols::T_MINUS);
				break;
			case 25:
				stack.pop();
				break;
			case 26:
				stack.pop();
				stack.push(Symbols::NT_MULTIPLE_REST);
				stack.push(Symbols::NT_MULTIPLICANT);
				break;
			case 27:
				stack.pop();
				stack.push(Symbols::NT_MULTIPLE_REST);
				stack.push(Symbols::NT_MULTIPLICANT);
				stack.push(Symbols::T_MUL);
				break;
			case 28:
				stack.pop();
				stack.push(Symbols::NT_MULTIPLE_REST);
				stack.push(Symbols::NT_MULTIPLICANT);
				stack.push(Symbols::T_DIV);
				break;
			case 29:
				stack.pop();
				break;
			case 30:
				stack.pop();
				stack.push(Symbols::NT_FACTOR);
				stack.push(Symbols::T_RBRACK);
				stack.push(Symbols::NT_EXPR);
				stack.push(Symbols::T_LBRACK);
				break;
			case 31:
				stack.pop();
				stack.push(Symbols::NT_FACTOR);
				stack.push(Symbols::T_IDENT);
				break;
			case 32:
				stack.pop();
				stack.push(Symbols::NT_FACTOR);
				stack.push(Symbols::T_INTEGER);
				break;
			case 33:
				stack.pop();
				stack.push(Symbols::T_DOUBLE);
				break;
			case 34:
				stack.pop();
				stack.push(Symbols::T_FACTOR);
				break;
			case 35:
				stack.pop();
				break;
			case 36:
				stack.pop();
				stack.push(Symbols::T_STRING);
				break;
			case 75:
				stack.pop();
				stack.push(Symbols::T_WRITE);
				break;
			case 76:
				stack.pop();
				stack.push(Symbols::T_WRITELN);
				break;
			case 100:
				stack.pop();
				stack.push(Symbols::T_KW_INT);
				break;
			case 101:
				stack.pop();
				stack.push(Symbols::T_KW_DOUBLE);
				break;
			case 102:
				stack.pop();
				stack.push(Symbols::T_KW_STRING);
				break;
			case 103:
				stack.pop();
				stack.push(Symbols::T_KW_BOOL);
				break;
			case 104:
				stack.pop();
				stack.push(Symbols::T_KW_AUTO);
				break;
			default:
				std::stringstream ss;
				ss << "Unexpected symbol '" << symbol << "' on position " << token->GetLine() << ":" << token->GetColumn();
				throw CParserException(ss.str().c_str(), token->GetLine(), token->GetColumn());
				break;
			}
		}
	}
}


//////////////////////////////////////////////////////////////////////////
// Factory
//////////////////////////////////////////////////////////////////////////
IParserPtr PARSER_DLL_EXPORT CreateStackParser()
{
	return std::make_shared<CStackParser>();
}