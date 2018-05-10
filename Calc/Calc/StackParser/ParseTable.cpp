#include "stdafx.h"
#include "ParseTable.h"

CParseTable::CParseTable()
{
	
}

CParseTable::~CParseTable()
{

}

void CParseTable::Init()
{
	m_mTable[Symbols::NT_CODE][Symbols::T_SEMICOL] = 1;
	m_mTable[Symbols::NT_CODE][Symbols::T_VAR] = 1;
	m_mTable[Symbols::NT_CODE][Symbols::T_WRITE] = 1;
	m_mTable[Symbols::NT_CODE][Symbols::T_WRITELN] = 1;
	m_mTable[Symbols::NT_CODE][Symbols::T_IDENT] = 1;
	m_mTable[Symbols::NT_CODE][Symbols::T_END] = 1;

	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_SEMICOL] = 2;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_VAR] = 2;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_WRITE] = 2;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_WRITELN] = 2;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_IDENT] = 2;
	m_mTable[Symbols::NT_COMMAND_LIST][Symbols::T_END] = 3;

	m_mTable[Symbols::NT_COMMAND][Symbols::T_SEMICOL] = 7;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_VAR] = 4;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_WRITE] = 6;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_WRITELN] = 6;
	m_mTable[Symbols::NT_COMMAND][Symbols::T_IDENT] = 5;

	m_mTable[Symbols::NT_DECLARATION][Symbols::T_VAR] = 8;
	m_mTable[Symbols::NT_DECLARATION_REST][Symbols::T_ASS] = 9;

	m_mTable[Symbols::NT_ASSIGN][Symbols::T_IDENT] = 10;

	m_mTable[Symbols::NT_EMPTY][Symbols::T_SEMICOL] = 11;

	m_mTable[Symbols::NT_EXPR][Symbols::T_LBRACK] = 12;
	m_mTable[Symbols::NT_EXPR][Symbols::T_INTEGER] = 12;
	m_mTable[Symbols::NT_EXPR][Symbols::T_DOUBLE] = 12;
	m_mTable[Symbols::NT_EXPR][Symbols::T_IDENT] = 12;

	m_mTable[Symbols::NT_EXPR_REST][Symbols::T_PLUS] = 13;
	m_mTable[Symbols::NT_EXPR_REST][Symbols::T_MINUS] = 14;
	m_mTable[Symbols::NT_EXPR_REST][Symbols::T_SEMICOL] = 15;

	m_mTable[Symbols::NT_MULTIPL][Symbols::T_LBRACK] = 16;
	m_mTable[Symbols::NT_MULTIPL][Symbols::T_INTEGER] = 16;
	m_mTable[Symbols::NT_MULTIPL][Symbols::T_DOUBLE] = 16;
	m_mTable[Symbols::NT_MULTIPL][Symbols::T_IDENT] = 16;

	m_mTable[Symbols::NT_MULTIPLE_REST][Symbols::T_MUL] = 17;
	m_mTable[Symbols::NT_MULTIPLE_REST][Symbols::T_DIV] = 18;
	m_mTable[Symbols::NT_MULTIPLE_REST][Symbols::T_PLUS] = 19;
	m_mTable[Symbols::NT_MULTIPLE_REST][Symbols::T_MINUS] = 19;
	m_mTable[Symbols::NT_MULTIPLE_REST][Symbols::T_SEMICOL] = 19;
	
	m_mTable[Symbols::NT_MULTIPLICANT][Symbols::T_LBRACK] = 20;
	m_mTable[Symbols::NT_MULTIPLICANT][Symbols::T_INTEGER] = 22;
	m_mTable[Symbols::NT_MULTIPLICANT][Symbols::T_DOUBLE] = 23;
	m_mTable[Symbols::NT_MULTIPLICANT][Symbols::T_IDENT] = 21;

	m_mTable[Symbols::NT_FACTOR][Symbols::T_PLUS] = 25;
	m_mTable[Symbols::NT_FACTOR][Symbols::T_MINUS] = 25;
	m_mTable[Symbols::NT_FACTOR][Symbols::T_MUL] = 25;
	m_mTable[Symbols::NT_FACTOR][Symbols::T_DIV] = 25;
	m_mTable[Symbols::NT_FACTOR][Symbols::T_SEMICOL] = 25;
	m_mTable[Symbols::NT_FACTOR][Symbols::T_VAR] = 24;

	m_mTable[Symbols::NT_FUNCTION][Symbols::T_WRITE] = 26;
	m_mTable[Symbols::NT_FUNCTION][Symbols::T_WRITELN] = 27;
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