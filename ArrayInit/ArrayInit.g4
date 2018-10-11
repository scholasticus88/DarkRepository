grammar ArrayInit;

list: LBRACK part (COMMA part)* RBRACK;

part: INT |
      list;


LBRACK:  '{';
RBRACK:  '}';
COMMA:   ',';
INT:     [0-9]+;

WS: [ \t\r\n]+ -> skip;