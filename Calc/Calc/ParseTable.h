#pragma once

#include "stdafx.h"

class CParseTable
{
public:
	CParseTable();
	~CParseTable();

private:
	std::stack<Symbols, std::map<Symbols, int>> m_mTable;
};