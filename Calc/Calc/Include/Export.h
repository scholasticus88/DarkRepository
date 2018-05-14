#pragma once

#ifdef LEXER_DLL
	#define LEXER_DLL_EXPORT __declspec(dllexport)
#else
	#define LEXER_DLL_EXPORT __declspec(dllimport)
#endif


#ifdef PARSER_DLL
	#define PARSER_DLL_EXPORT __declspec(dllexport)
#else 
	#define PARSER_DLL_EXPORT __declspec(dllimport)
#endif