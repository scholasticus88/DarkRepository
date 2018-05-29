#pragma once

#include "stdafx.h"
#include "Symbols.h"

class CParseTable
{
public:
	CParseTable();
	~CParseTable();

	int operator()(Symbols nt, Symbols t) const;

private:
	void Init();

	std::map<Symbols, std::map<Symbols, int>> m_mTable;
};




enum Rules
{
	CODE = 1,

	COMMAND_LIST_1,
	COMMAND_LIST_2,
	
	COMMAND_1,
	COMMAND_2,
	COMMAND_3,
	COMMAND_4,

	DECLARATION_1,
	DECLARATION_REST_1,
	DECLARATION_REST_2,

	ASSIGN_1,
	EMPTY,

	RIGHT_SIDE_1,
	RIGHT_SIDE_2,

	EXPR,
	EXPR_REST_1,
	EXPR_REST_2,
	EXPR_REST_3,

	MULTIPL,
	MULTIPL_REST_1,
	MULTIPL_REST_2,
	MULTIPL_REST_3,

	MULTIPLICANT_1,
	MULTIPLICANT_2,
	MULTIPLICANT_3,
	MULTIPLICANT_4,

	FACTOR_1,
	FACTOR_2,

	STRING_1,

	FUNCTION_1,
	FUNCTION_2,


	DATA_TYPE_1,
	DATA_TYPE_2,
	DATA_TYPE_3,
	DATA_TYPE_4,
	DATA_TYPE_5,

};