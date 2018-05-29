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
			case Rules::CODE:
				stack.pop();
				stack.push(Symbols::NT_COMMAND_LIST);
				break;
			case Rules::COMMAND_LIST_1:
				stack.pop();
				stack.push(Symbols::NT_COMMAND_LIST);
				stack.push(Symbols::NT_COMMAND);
				break;
			case Rules::COMMAND_LIST_2:
				stack.pop();
				break;
			case Rules::COMMAND_1:
				stack.pop();
				stack.push(Symbols::NT_DECLARATION);
				break;
			case Rules::COMMAND_2:
				stack.pop();
				stack.push(Symbols::NT_ASSIGN);
				break;
			case Rules::COMMAND_3:
				stack.pop();
				stack.push(Symbols::NT_FUNCTION);
				break;
			case Rules::COMMAND_4:
				stack.pop();
				stack.push(Symbols::NT_EMPTY);
				break;
			case Rules::DECLARATION_1:
				stack.pop();
				stack.push(Symbols::NT_DECLARATION_REST);
				stack.push(Symbols::T_IDENT);
				stack.push(Symbols::NT_DATA_TYPE);
				break;
			case Rules::DECLARATION_REST_1:
				stack.pop();
				stack.push(Symbols::T_SEMICOL);
				stack.push(Symbols::NT_RIGHT_SIDE);
				stack.push(Symbols::T_ASS);
				break;
			case Rules::DECLARATION_REST_2:
				stack.pop();
				break;
			case Rules::ASSIGN_1:
				stack.pop();
				stack.push(Symbols::T_SEMICOL);
				stack.push(Symbols::NT_RIGHT_SIDE);
				stack.push(Symbols::T_ASS);
				stack.push(Symbols::T_IDENT);
				break;
			case Rules::EMPTY:
				stack.pop();
				stack.push(Symbols::T_SEMICOL);
				break;
			case Rules::RIGHT_SIDE_1:
				stack.pop();
				stack.push(Symbols::NT_EXPR);
				break;
			case Rules::RIGHT_SIDE_2:
				stack.pop();
				stack.push(Symbols::NT_STRING_EXPR);
				break;
			case Rules::EXPR:
				stack.pop();
				stack.push(Symbols::NT_EXPR_REST);
				stack.push(Symbols::NT_MULTIPL);
				break;
			case Rules::EXPR_REST_1:
				stack.pop();
				stack.push(Symbols::NT_EXPR_REST);
				stack.push(Symbols::NT_MULTIPL);
				stack.push(Symbols::T_PLUS);
				break;
			case Rules::EXPR_REST_2:
				stack.pop();
				stack.push(Symbols::NT_EXPR_REST);
				stack.push(Symbols::NT_MULTIPL);
				stack.push(Symbols::T_MINUS);
				break;
			case Rules::EXPR_REST_3:
				stack.pop();
				break;
			case Rules::MULTIPL:
				stack.pop();
				stack.push(Symbols::NT_MULTIPLE_REST);
				stack.push(Symbols::NT_MULTIPLICANT);
				break;
			case Rules::MULTIPL_REST_1:
				stack.pop();
				stack.push(Symbols::NT_MULTIPLE_REST);
				stack.push(Symbols::NT_MULTIPLICANT);
				stack.push(Symbols::T_MUL);
				break;
			case Rules::MULTIPL_REST_2:
				stack.pop();
				stack.push(Symbols::NT_MULTIPLE_REST);
				stack.push(Symbols::NT_MULTIPLICANT);
				stack.push(Symbols::T_DIV);
				break;
			case Rules::MULTIPL_REST_3:
				stack.pop();
				break;
			case Rules::MULTIPLICANT_1:
				stack.pop();
				stack.push(Symbols::NT_FACTOR);
				stack.push(Symbols::T_RBRACK);
				stack.push(Symbols::NT_EXPR);
				stack.push(Symbols::T_LBRACK);
				break;
			case Rules::MULTIPLICANT_2:
				stack.pop();
				stack.push(Symbols::NT_FACTOR);
				stack.push(Symbols::T_IDENT);
				break;
			case Rules::MULTIPLICANT_3:
				stack.pop();
				stack.push(Symbols::NT_FACTOR);
				stack.push(Symbols::T_INTEGER);
				break;
			case Rules::MULTIPLICANT_4:
				stack.pop();
				stack.push(Symbols::T_DOUBLE);
				break;
			case Rules::FACTOR_1:
				stack.pop();
				stack.push(Symbols::T_FACTOR);
				break;
			case Rules::FACTOR_2:
				stack.pop();
				break;
			case Rules::STRING_1:
				stack.pop();
				stack.push(Symbols::T_STRING);
				break;
			case Rules::FUNCTION_1:
				stack.pop();
				stack.push(Symbols::T_WRITE);
				break;
			case Rules::FUNCTION_2:
				stack.pop();
				stack.push(Symbols::T_WRITELN);
				break;
			case Rules::DATA_TYPE_1:
				stack.pop();
				stack.push(Symbols::T_KW_INT);
				break;
			case Rules::DATA_TYPE_2:
				stack.pop();
				stack.push(Symbols::T_KW_DOUBLE);
				break;
			case Rules::DATA_TYPE_3:
				stack.pop();
				stack.push(Symbols::T_KW_STRING);
				break;
			case Rules::DATA_TYPE_4:
				stack.pop();
				stack.push(Symbols::T_KW_BOOL);
				break;
			case Rules::DATA_TYPE_5:
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