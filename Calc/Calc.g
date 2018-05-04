grammar Calc;

code:				command_list;

command_list:		command command_list |
					;
					
command:			declaration |
					assign |
					empty;

// declaration command
declaration:		VAR IDENT declaration_rest;

declaration_rest:	ASS expr SEMICOL;

// assignment command
assign:				IDENT ASS expr SEMICOL;

// empty command
empty:				SEMICOL;

// math expression
expr:				multipl expr_rest;

expr_rest:			PLUS multipl expr_rest |
					MINUS multipl expr_rest |
					;

multipl:			multiplicant multipl_rest;

multipl_rest:		MUL multiplicant multipl_rest |
					DIV multiplicant multipl_rest |
					;

multiplicant:		L_BRACK expr P_BRACK factor |
					INTEGER factor |
					DOUBLE;

factor:				FACTOR |
					;



PLUS:				'+';
MINUS:				'-';	

MUL:				'*';
DIV:				'/';	

L_BRACK:			'(';
P_BRACK:			')';

ASS:				'=';

SEMICOL:			';';

FACTOR:				'!';

VAR:				'var';

INTEGER: 			INTEGRAL_PART;

DOUBLE:				INTEGRAL_PART DOT DECIMAL_PART;

IDENT:				LETTER (LETTER | DIGIT)?;




fragment
DOT	:				'.';

fragment
INTEGRAL_PART:		MARK? DIGIT+;

fragment
DECIMAL_PART:		DIGIT+ (EXPONENT DIGIT+);

fragment
DIGIT:				'0'..'9';

fragment
EXPONENT:   		'e' | 'E';

fragment
MARK:				'+' | '-';

fragment
LETTER:				'a'..'z' | 'A'..'Z';	