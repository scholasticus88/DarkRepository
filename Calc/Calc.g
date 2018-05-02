grammar Calc;


expr:				multipl expr_rest;

expr_rest:			PLUS_MINUS multipl expr_rest |
					;

multipl:			INTEGER multipl_rest;

multipl_rest:		MUL_DIV INTEGER multipl_rest |
					;



INTEGER: 			INTEGRAL_PART;

DOUBLE:				INTEGRAL_PART DOT DECIMAL_PART;

PLUS_MINUS:			'+' | '-';

MUL_DIV:			'*' | '/';



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