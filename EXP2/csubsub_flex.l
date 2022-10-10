%option yylineno

%{
    #include "syntax.tab.h"
    int yycolumn=1;
    int charLoc = 1;
    #define YY_USER_ACTION
    yylloc.first_line=yylloc.last_line=yylineno;\
    yylloc.first_column=yycolumn;\
    yylloc.last_column=yycolumn+yyleng-1;\
    yycolumn+=yyleng;
%}

ID [a-zA-Z_][a-zA-Z0-9_]*
INT [+-]?(0|[1-9][0-9]*)
FLOAT [+-]?([0-9]+\.[0-9]*)|([0-9]*\.[0-9]+)
SINGLECOMMENT \/\/.*
MULTICOMMENT \/\*(.*?\n)*?.*?\*\/
OCT 0[0-7][0-7]*
HEX 0[xX][0-9a-fA-F]*
EFLOAT ({FLOAT}|{INT}\.)[Ee]{INT}
ERROROCT [0]([0-7]*[89]+)+[0-9]*
ERRORHEX 0[xX]([0-9a-fA-F]*[g-zG-Z]+)+[0-9a-zA-Z]*
ERRORFLOAT ({FLOAT}|{INT})[Ee][a-zA-Z]?({FLOAT})?
SPACE [ \s]+
TAB \t+
TYPE (int)|(float)
RELOP >|<|(>=)|(<=)|(==)|(!=)

%%
"\n" {charLoc = 1; yycolumn = 1; }
{SPACE} {charLoc += yyleng;}
{TAB} {charLoc += yyleng * 4;}
"struct" { return STRUCT ; }
"return" { return RETURN ; }
"if" { return IF ; }
"else" { return ELSE ; }
"while" { return WHILE ; }
{ERRORFLOAT} { printf("ERROR at line %d, char %d: Illegal float: %s.\n", yylineno, charLoc, yytext); charLoc += yyleng; }
{ERRORHEX} { printf("ERROR at line %d, char %d: Illegal Hex %s.\n", yylineno, charLoc, yytext); charLoc += yyleng; }
{ERROROCT} { printf("ERROR at line %d, char %d: Illegal Oct %s.\n", yylineno, charLoc, yytext); charLoc += yyleng; }
{EFLOAT} { return FLOAT ; }
{FLOAT} {return FLOAT ;}
{HEX} { return HEX ; }
{INT} {return INT ;}
{OCT} { return OCT ; }
{SINGLECOMMENT} { return COMMENT ; }
{MULTICOMMENT} { return COMMENT ; }
{TYPE} { return TYPE ; }
";" { return SEMI ; }
"," { return COMMA ; }
"=" { return ASSIGNOP ; }
{RELOP} { return RELOP ; }
"+" { return PLUS ; }
"-" { return MINUS ; }
"*" { return STAR ; }
"/" { return DIV ; }
"&&" { return AND ; }
"||" { return OR ; }
"." { return DOT ; }
"!" { return NOT ; }
"(" { return LP ; }
")" { return RP ; }
"[" { return LB ; }
"]" { return RB ; }
"{" { return LC ; }
"}" { return RC ; }
{ID} { return ID ; }
. { printf("ERROR at line %d,char %d, Myterious character: '%s'.\n",yylineno,charLoc,yytext); charLoc += yyleng; }

%%


int main(int argc, char** argv){
    if(argc<=1) return 1;
    FILE* f=fopen(argv[1],"r");
    if(!f){
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    yyparse();
    return 0;
}

// ERROROCT ([0])([0-9]|LETTER)+
// ERRORHEX 0[x,X][LETTER|DIGIT]+
// ERRORFLOAT [0-9]*\.
// ERROREEFLOAT 
// {ERROROCT} { printf("ERROR at line %d,char %d: Illegal octal number: '%s'.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
// {ERRORHEX} { printf("ERROR at line %d,char %d: Illegal octal number: '%s'.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
// {ERRORFLOAT} {printf("ERROR at line %d,char %d: Illegal float number: '%s'.\n",yylineno,charLoc,yytext);charLoc += yyleng;}