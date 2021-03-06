grammar Calc;

code:				command_list;

command_list:		command command_list |
					;
					
command:			declaration |
					assign |
					function |
					empty;

// declaration command
declaration:		data_type IDENT declaration_rest SEMICOL;

declaration_rest:	ASS right_side |
					;
					
right_side:			expr |
					str_expr;

// assignment command
assign:				IDENT ASS right_side SEMICOL;

// empty command
empty:				SEMICOL;

// string expressionstr_expr
str_expr:	        STRING;

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
					IDENT factor |
					INTEGER factor |
					DOUBLE;

factor:				FACTOR |
					;

function:			WRITE L_BRACK IDENT P_BRACK |
					WRITELN L_BRACK IDENT P_BRACK;
					
data_type:			KW_STRING |
					KW_INT |
					KW_DOUBLE |
					KW_BOOL |
					KW_AUTO;



PLUS:				'+';
MINUS:				'-';

MUL:				'*';
DIV:				'/';	

L_BRACK:			'(';
P_BRACK:			')';

ASS:				'=';

SEMICOL:			';';

FACTOR:				'!';

APOSTOPH:			'"';

KW_STRING:			'string';

KW_INT:				'int';

KW_DOUBLE:			'double';

KW_BOOL:			'bool';

KW_AUTO:			'auto';

WRITE:				'write';

WRITELN:			'writeln';

INTEGER: 			INTEGRAL_PART;

DOUBLE:				INTEGRAL_PART DOT DECIMAL_PART;

IDENT:				LETTER (LETTER | DIGIT)?;

STRING:				APOSTOPH (LETTER | DIGIT | SPACE)+ APOSTOPH;




fragment
DOT	:				'.';

fragment
SPACE:				' ';

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