grammar Calc;


expr:				multipl expr_rest;

expr_rest:			PLUS multipl expr_rest |
					MINUS multipl expr_rest |
					;

multipl:			INTEGER multipl_rest;

multipl_rest:		MUL INTEGER multipl_rest |
					DIV INTEGER multipl_rest |
					;



INTEGER: 			INTEGRAL_PART;

DOUBLE:				INTEGRAL_PART DOT DECIMAL_PART;

PLUS:				'+';
MINUS:				'-';	

MUL:				'*';
DIV:				'/';	



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