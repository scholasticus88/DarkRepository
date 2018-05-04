#pragma once

enum Symbols
{
	// non-terminals
	NT_CODE = 100,
	NT_COMMAND_LIST = 101,
	NT_COMMAND = 102,
	NT_DECLARATION = 103,
	NT_ASSIGN = 104,
	NT_EMPTY = 105,

	NT_EXPR = 500,
	NT_EXPR_REST = 501,
	NT_MULTIPL = 502,
	NT_MULTIPLE_REST = 503,
	NT_MULTIPLICANT = 504,
	NT_FACTOR = 505,


	// terminals
	T_IDENT = 1000,
	T_INTEGER = 1001,
	T_DOUBLE = 1002,
	T_PLUS = 1003,
	T_MINUS = 1004,
	T_MUL = 1005,
	T_DIV = 1006,
	T_ASS = 1007,
	T_SEMICOL = 1008,
	T_LBRACK = 1009,
	T_RBRACK = 1010,
	T_FACTOR = 1011,


	// keywords
	T_VAR = 1500,


	// end of file
	END = 9999,
};