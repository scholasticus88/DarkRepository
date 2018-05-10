#pragma once

#ifdef LEXER_DLL
	#define LEXER_DLL_EXPORT __declspec(dllexport)
#else
	#define LEXER_DLL_EXPORT __declspec(dllimport)
#endif

