#pragma once

enum Symbols
{
	// non-terminals
	NT_EXPR = 100,
	NT_MULTIPL = 101,
	NT_EXPR_REST = 102,
	NT_MULTIPL = 103,
	NT_MULTIPLE_REST = 104,


	// terminals
	INTEGER = 1000,
	DOUBLE = 1001,
	PLUS = 1003,
	MINUS = 1004,
	MUL = 1005,
	DIV = 1006,
	IDENT = 1007,

	// end of file
	END = 9999,
};