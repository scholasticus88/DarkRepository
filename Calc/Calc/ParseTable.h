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