#include "stdafx.h"
#include "ParseTable.h"

CParseTable::CParseTable()
{
	Init();
}

CParseTable::~CParseTable()
{

}

void CParseTable::Init()
{
	m_mTable[Symbols::NT_CODE][Symbols::T_SEMICOL] = Rules::CODE;
	m_mTable[Symbols::NT_CODE][Symbols::T_WRITE] = Rules::CODE;
	m_mTable[Symbols::NT_CODE][Symbols::T_WRITELN] = Rules::CODE;
	m_mTable[Symbols::NT_CODE][Symbols::T_IDENT] = Rules::CODE;
	m_mTable[Symbols::NT_CODE][Symbols::T_END] = Rules::CODE;
	m_mTable[Symbols::NT_CODE][Symbols::T_KW_INT] = Rules::CODE;
	m_mTable[Symbols::NT_CODE][Symbols::T_KW_DOUBLE] = Rules::CODE;
	m_mTable[Symbols::NT_CODE][Symbols::T_KW_BOOL] = Rules::CODE;
	m_mTable[Symbols::NT_CODE][Symbols::T_KW_STRING] = Rules::CODE;
	m_mTable[Symbols::NT_CODE][Symbols::T_KW_AUTO] = Rules::CODE;

	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_SEMICOL] = Rules::COMMAND_LIST_1;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_WRITE] = Rules::COMMAND_LIST_1;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_WRITELN] = Rules::COMMAND_LIST_1;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_IDENT] = Rules::COMMAND_LIST_1;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_KW_INT] = Rules::COMMAND_LIST_1;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_KW_DOUBLE] = Rules::COMMAND_LIST_1;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_KW_BOOL] = Rules::COMMAND_LIST_1;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_KW_STRING] = Rules::COMMAND_LIST_1;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_KW_AUTO] = Rules::COMMAND_LIST_1;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_END] = Rules::COMMAND_LIST_2;

	m_mTable[Symbols::NT_COMMAND][Symbols::T_KW_INT] = Rules::COMMAND_1;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_KW_DOUBLE] = Rules::COMMAND_1;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_KW_BOOL] = Rules::COMMAND_1;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_KW_STRING] = Rules::COMMAND_1;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_KW_AUTO] = Rules::COMMAND_1;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_IDENT] = Rules::COMMAND_2;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_WRITE] = Rules::COMMAND_3;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_WRITELN] = Rules::COMMAND_3;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_SEMICOL] = Rules::COMMAND_4;
	
	m_mTable[Symbols::NT_DECLARATION][Symbols::T_KW_INT] = Rules::DECLARATION_1;
	m_mTable[Symbols::NT_DECLARATION][Symbols::T_KW_DOUBLE] = Rules::DECLARATION_1;
	m_mTable[Symbols::NT_DECLARATION][Symbols::T_KW_STRING] = Rules::DECLARATION_1;
	m_mTable[Symbols::NT_DECLARATION][Symbols::T_KW_BOOL] = Rules::DECLARATION_1;
	m_mTable[Symbols::NT_DECLARATION][Symbols::T_KW_AUTO] = Rules::DECLARATION_1;

	m_mTable[Symbols::NT_DECLARATION_REST][Symbols::T_ASS] = Rules::DECLARATION_REST_1;
	m_mTable[Symbols::NT_DECLARATION_REST][Symbols::T_SEMICOL] = Rules::DECLARATION_REST_2;

	m_mTable[Symbols::NT_ASSIGN][Symbols::T_IDENT] = Rules::ASSIGN_1;
	m_mTable[Symbols::NT_EMPTY][Symbols::T_SEMICOL] = Rules::EMPTY;

	m_mTable[Symbols::NT_RIGHT_SIDE][Symbols::T_LBRACK] = Rules::RIGHT_SIDE_1;
	m_mTable[Symbols::NT_RIGHT_SIDE][Symbols::T_INTEGER] = Rules::RIGHT_SIDE_1;
	m_mTable[Symbols::NT_RIGHT_SIDE][Symbols::T_DOUBLE] = Rules::RIGHT_SIDE_1;
	m_mTable[Symbols::NT_RIGHT_SIDE][Symbols::T_IDENT] = Rules::RIGHT_SIDE_1;
	m_mTable[Symbols::NT_RIGHT_SIDE][Symbols::T_STRING] = Rules::RIGHT_SIDE_2;

	m_mTable[Symbols::NT_EXPR][Symbols::T_LBRACK] = Rules::EXPR;
	m_mTable[Symbols::NT_EXPR][Symbols::T_INTEGER] = Rules::EXPR;
	m_mTable[Symbols::NT_EXPR][Symbols::T_DOUBLE] = Rules::EXPR;
	m_mTable[Symbols::NT_EXPR][Symbols::T_IDENT] = Rules::EXPR;

	m_mTable[Symbols::NT_EXPR_REST][Symbols::T_PLUS] = Rules::EXPR_REST_1;
	m_mTable[Symbols::NT_EXPR_REST][Symbols::T_MINUS] = Rules::EXPR_REST_2;
	m_mTable[Symbols::NT_EXPR_REST][Symbols::T_SEMICOL] = Rules::EXPR_REST_3;
	m_mTable[Symbols::NT_EXPR_REST][Symbols::T_RBRACK] = Rules::EXPR_REST_3;

	m_mTable[Symbols::NT_MULTIPL][Symbols::T_LBRACK] = Rules::MULTIPL;
	m_mTable[Symbols::NT_MULTIPL][Symbols::T_INTEGER] = Rules::MULTIPL;
	m_mTable[Symbols::NT_MULTIPL][Symbols::T_DOUBLE] = Rules::MULTIPL;
	m_mTable[Symbols::NT_MULTIPL][Symbols::T_IDENT] = Rules::MULTIPL;

	m_mTable[Symbols::NT_MULTIPLE_REST][Symbols::T_MUL] = Rules::MULTIPL_REST_1;
	m_mTable[Symbols::NT_MULTIPLE_REST][Symbols::T_DIV] = Rules::MULTIPL_REST_2;
	m_mTable[Symbols::NT_MULTIPLE_REST][Symbols::T_PLUS] = Rules::MULTIPL_REST_3;
	m_mTable[Symbols::NT_MULTIPLE_REST][Symbols::T_MINUS] = Rules::MULTIPL_REST_3;
	m_mTable[Symbols::NT_MULTIPLE_REST][Symbols::T_SEMICOL] = Rules::MULTIPL_REST_3;
	m_mTable[Symbols::NT_MULTIPLE_REST][Symbols::T_RBRACK] = Rules::MULTIPL_REST_3;
	
	m_mTable[Symbols::NT_MULTIPLICANT][Symbols::T_LBRACK] = Rules::MULTIPLICANT_1;
	m_mTable[Symbols::NT_MULTIPLICANT][Symbols::T_IDENT] = Rules::MULTIPLICANT_2;
	m_mTable[Symbols::NT_MULTIPLICANT][Symbols::T_INTEGER] = Rules::MULTIPLICANT_3;
	m_mTable[Symbols::NT_MULTIPLICANT][Symbols::T_DOUBLE] = Rules::MULTIPLICANT_4;

	m_mTable[Symbols::NT_FACTOR][Symbols::T_FACTOR] = Rules::FACTOR_1;
	m_mTable[Symbols::NT_FACTOR][Symbols::T_PLUS] = Rules::FACTOR_2;
	m_mTable[Symbols::NT_FACTOR][Symbols::T_MINUS] = Rules::FACTOR_2;
	m_mTable[Symbols::NT_FACTOR][Symbols::T_MUL] = Rules::FACTOR_2;
	m_mTable[Symbols::NT_FACTOR][Symbols::T_DIV] = Rules::FACTOR_2;
	m_mTable[Symbols::NT_FACTOR][Symbols::T_SEMICOL] = Rules::FACTOR_2;
	m_mTable[Symbols::NT_FACTOR][Symbols::T_RBRACK] = Rules::FACTOR_2;

	m_mTable[Symbols::NT_STRING_EXPR][Symbols::T_STRING] = Rules::STRING_1;

	m_mTable[Symbols::NT_FUNCTION][Symbols::T_WRITE] = Rules::FUNCTION_1;
	m_mTable[Symbols::NT_FUNCTION][Symbols::T_WRITELN] = Rules::FUNCTION_2;

	m_mTable[Symbols::NT_DATA_TYPE][Symbols::T_KW_INT] = Rules::DATA_TYPE_1;
	m_mTable[Symbols::NT_DATA_TYPE][Symbols::T_KW_DOUBLE] = Rules::DATA_TYPE_2;
	m_mTable[Symbols::NT_DATA_TYPE][Symbols::T_KW_STRING] = Rules::DATA_TYPE_3;
	m_mTable[Symbols::NT_DATA_TYPE][Symbols::T_KW_BOOL] = Rules::DATA_TYPE_4;
	m_mTable[Symbols::NT_DATA_TYPE][Symbols::T_KW_AUTO] = Rules::DATA_TYPE_5;
}

int CParseTable::operator()(Symbols nt, Symbols t) const
{
	int iRetVal = -1;

	std::map<Symbols, std::map<Symbols, int>>::const_iterator it = m_mTable.find(nt);
	if (it != m_mTable.end())
	{
		std::map<Symbols, int>::const_iterator it2 = it->second.find(t);
		if (it2 != it->second.end())
		{
			iRetVal = it2->second;
		}
	}

	return iRetVal;
}