grammar Hello;

greet: 'Hello' ID ;


ID : [A-Z,a-z]+ ;
WS : [ \t\r\n]+ -> skip ;