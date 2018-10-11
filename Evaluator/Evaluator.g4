grammar Evaluator;

prog:	cmd+;

cmd:	ID ASS expr COMMA					# AssignmentCommand
	|   expr								# ExpressionCommand
	;

expr:	expr op=(MUL | DIV) expr			# MulDiv
	|	expr op=(PLUS | MINUS) expr			# AddSub
	|   LBRACK expr RBRACK factor			# BrackExpr
	|	ID factor							# VariableFactor
	|	NUM factor							# NumberFactor
	;

factor:	FACTOR
	|
	;


ID:		[a-zA-Z]+;
NUM:	[0-9]+;
FACTOR:	'!';
COMMA:	';';
LBRACK: '(';
RBRACK: ')';
MUL:	'*';
DIV:	'/';
PLUS:	'+';
MINUS:	'-';
ASS:	'=';

WS:		[ \r\n\t] -> skip;