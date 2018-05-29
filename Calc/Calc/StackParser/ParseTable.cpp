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
	m_mTable[Symbols::NT_CODE][Symbols::T_SEMICOL] = 1;
	m_mTable[Symbols::NT_CODE][Symbols::T_WRITE] = 1;
	m_mTable[Symbols::NT_CODE][Symbols::T_WRITELN] = 1;
	m_mTable[Symbols::NT_CODE][Symbols::T_IDENT] = 1;
	m_mTable[Symbols::NT_CODE][Symbols::T_END] = 1;
	m_mTable[Symbols::NT_CODE][Symbols::T_KW_INT] = 1;
	m_mTable[Symbols::NT_CODE][Symbols::T_KW_DOUBLE] = 1;
	m_mTable[Symbols::NT_CODE][Symbols::T_KW_BOOL] = 1;
	m_mTable[Symbols::NT_CODE][Symbols::T_KW_STRING] = 1;
	m_mTable[Symbols::NT_CODE][Symbols::T_KW_AUTO] = 1;

	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_SEMICOL] = 2;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_WRITE] = 2;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_WRITELN] = 2;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_IDENT] = 2;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_END] = 3;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_KW_INT] = 2;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_KW_DOUBLE] = 2;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_KW_BOOL] = 2;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_KW_STRING] = 2;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_KW_AUTO] = 2;

	m_mTable[Symbols::NT_COMMAND][Symbols::T_SEMICOL] = 7;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_WRITE] = 6;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_WRITELN] = 6;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_IDENT] = 5;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_KW_INT] = 4;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_KW_DOUBLE] = 4;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_KW_BOOL] = 4;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_KW_STRING] = 4;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_KW_AUTO] = 4;

	m_mTable[Symbols::NT_DECLARATION][Symbols::T_KW_INT] = 8;
	m_mTable[Symbols::NT_DECLARATION][Symbols::T_KW_DOUBLE] = 8;
	m_mTable[Symbols::NT_DECLARATION][Symbols::T_KW_STRING] = 8;
	m_mTable[Symbols::NT_DECLARATION][Symbols::T_KW_BOOL] = 8;
	m_mTable[Symbols::NT_DECLARATION][Symbols::T_KW_AUTO] = 8;

	m_mTable[Symbols::NT_DECLARATION_REST][Symbols::T_ASS] = 9;
	m_mTable[Symbols::NT_DECLARATION_REST][Symbols::T_SEMICOL] = 10;

	m_mTable[Symbols::NT_RIGHT_SIDE][Symbols::T_LBRACK] = 13;
	m_mTable[Symbols::NT_RIGHT_SIDE][Symbols::T_INTEGER] = 13;
	m_mTable[Symbols::NT_RIGHT_SIDE][Symbols::T_DOUBLE] = 13;
	m_mTable[Symbols::NT_RIGHT_SIDE][Symbols::T_IDENT] = 13;
	m_mTable[Symbols::NT_RIGHT_SIDE][Symbols::T_STRING] = 14;

	m_mTable[Symbols::NT_ASSIGN][Symbols::T_IDENT] = 11;

	m_mTable[Symbols::NT_EMPTY][Symbols::T_SEMICOL] = 12;

	m_mTable[Symbols::NT_EXPR][Symbols::T_LBRACK] = 22;
	m_mTable[Symbols::NT_EXPR][Symbols::T_INTEGER] = 22;
	m_mTable[Symbols::NT_EXPR][Symbols::T_DOUBLE] = 22;
	m_mTable[Symbols::NT_EXPR][Symbols::T_IDENT] = 22;

	m_mTable[Symbols::NT_EXPR_REST][Symbols::T_PLUS] = 23;
	m_mTable[Symbols::NT_EXPR_REST][Symbols::T_MINUS] = 24;
	m_mTable[Symbols::NT_EXPR_REST][Symbols::T_SEMICOL] = 25;
	m_mTable[Symbols::NT_EXPR_REST][Symbols::T_RBRACK] = 25;

	m_mTable[Symbols::NT_MULTIPL][Symbols::T_LBRACK] = 26;
	m_mTable[Symbols::NT_MULTIPL][Symbols::T_INTEGER] = 26;
	m_mTable[Symbols::NT_MULTIPL][Symbols::T_DOUBLE] = 26;
	m_mTable[Symbols::NT_MULTIPL][Symbols::T_IDENT] = 26;

	m_mTable[Symbols::NT_MULTIPLE_REST][Symbols::T_MUL] = 27;
	m_mTable[Symbols::NT_MULTIPLE_REST][Symbols::T_DIV] = 28;
	m_mTable[Symbols::NT_MULTIPLE_REST][Symbols::T_PLUS] = 29;
	m_mTable[Symbols::NT_MULTIPLE_REST][Symbols::T_MINUS] = 29;
	m_mTable[Symbols::NT_MULTIPLE_REST][Symbols::T_SEMICOL] = 29;
	m_mTable[Symbols::NT_MULTIPLE_REST][Symbols::T_RBRACK] = 29;
	
	m_mTable[Symbols::NT_MULTIPLICANT][Symbols::T_LBRACK] = 30;
	m_mTable[Symbols::NT_MULTIPLICANT][Symbols::T_INTEGER] = 32;
	m_mTable[Symbols::NT_MULTIPLICANT][Symbols::T_DOUBLE] = 33;
	m_mTable[Symbols::NT_MULTIPLICANT][Symbols::T_IDENT] = 31;

	m_mTable[Symbols::NT_FACTOR][Symbols::T_PLUS] = 35;
	m_mTable[Symbols::NT_FACTOR][Symbols::T_MINUS] = 35;
	m_mTable[Symbols::NT_FACTOR][Symbols::T_MUL] = 35;
	m_mTable[Symbols::NT_FACTOR][Symbols::T_DIV] = 35;
	m_mTable[Symbols::NT_FACTOR][Symbols::T_SEMICOL] = 35;
	m_mTable[Symbols::NT_FACTOR][Symbols::T_RBRACK] = 35;
	m_mTable[Symbols::NT_FACTOR][Symbols::T_FACTOR] = 34;

	m_mTable[Symbols::NT_STRING_EXPR][Symbols::T_STRING] = 36;

	m_mTable[Symbols::NT_FUNCTION][Symbols::T_WRITE] = 75;
	m_mTable[Symbols::NT_FUNCTION][Symbols::T_WRITELN] = 76;

	m_mTable[Symbols::NT_DATA_TYPE][Symbols::T_KW_INT] = 100;
	m_mTable[Symbols::NT_DATA_TYPE][Symbols::T_KW_DOUBLE] = 101;
	m_mTable[Symbols::NT_DATA_TYPE][Symbols::T_KW_STRING] = 102;
	m_mTable[Symbols::NT_DATA_TYPE][Symbols::T_KW_BOOL] = 103;
	m_mTable[Symbols::NT_DATA_TYPE][Symbols::T_KW_AUTO] = 104;
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