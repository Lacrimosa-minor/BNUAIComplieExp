LETTER [a-zA-Z]
ID ({LETTER}|_)({LETTER}|_|{DIGIT})*
DIGIT [0-9]
INTEGER ([0]|[[1-9]{DIGIT}*])
INT10 [+-]?{INTEGER}
INT8 ([0])([0-7])+
ERRORINT8 ([0])([8-9]|LETTER)+
INT16 (0x|0X)([0-9a-fA-F])+
ERRORINT16 (0x|0X)(f-zF-Z)+
FLOAT (DIGIT)*[.](DIGIT)*([Ee]{INT10})?
ERRORFLOAT ({INTEGER}*[Ee].|(DIGIT)*[.](DIGIT)*[Ee][^{INT10})

&&

{ID} {printf("ID at line %d,char %d: %s.\n",yylineno,charLoc,yytext);charLoc += yyleng;}
{INT10} {printf("INT10 at line %d,char %d: %s.\n",yylineno,charLoc,yytext);charLoc += yyleng;}
{INT8} {printf("INT8 at line %d,char %d: %s.\n",yylineno,charLoc,yytext);charLoc += yyleng;}
{ERRORINT8} {printf("ERRORINT8 at line %d,char %d: Illegal octal number: '%s'.\n",yylineno,charLoc,yytext);charLoc += yyleng;}
{INT16} {printf("INT16 at line %d,char %d: %s.\n",yylineno,charLoc,yytext);charLoc += yyleng;}
{ERRORINT16} {printf("ERRORINT16 at line %d,char %d: Illegal octal number: '%s'.\n",yylineno,charLoc,yytext);charLoc += yyleng;}
{FLOAT} {printf("FLOAT at line %d,char %d: %s.\n",yylineno,charLoc,yytext);charLoc += yyleng;}
{ERRORFLOAT} {printf("ERRORFLOAT at line %d,char %d: Illegal float number: '%s'.\n",yylineno,charLoc,yytext);charLoc += yyleng;}
\n {charLoc = 0}
" " {charLoc++}

&&
......
