#pragma once

#include "stdafx.h"
#include "Symbols.h"

class CParseTable
{
public:
	CParseTable();
	~CParseTable();

private:
	std::map<Symbols, std::map<Symbols, int>> m_mTable;
};