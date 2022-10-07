%option yylineno

%{
    int charLoc = 1;
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
"\n" {charLoc = 1;}
{SPACE} {charLoc += yyleng;}
{TAB} {charLoc += yyleng * 4;}
"struct" { printf("STRUCT at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"return" { printf("RETURN at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"if" { printf("IF at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"else" { printf("ELSE at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"while" { printf("WHILE at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
{ERRORFLOAT} { printf("ERROR at line %d, char %d: Illegal float: %s.\n", yylineno, charLoc, yytext); charLoc += yyleng; }
{ERRORHEX} { printf("ERROR at line %d, char %d: Illegal Hex %s.\n", yylineno, charLoc, yytext); charLoc += yyleng; }
{ERROROCT} { printf("ERROR at line %d, char %d: Illegal Oct %s.\n", yylineno, charLoc, yytext); charLoc += yyleng; }
{EFLOAT} { printf("FLOAT at line %d, char %d: %s.\n", yylineno, charLoc, yytext); charLoc += yyleng; }
{FLOAT} {printf("FLOAT at line %d,char %d: %s.\n",yylineno,charLoc,yytext);charLoc += yyleng;}
{HEX} { printf("HEX at line %d, char %d: %s.\n", yylineno, charLoc, yytext); charLoc += yyleng; }
{INT} {printf("INT at line %d,char %d: %s.\n",yylineno,charLoc,yytext);charLoc += yyleng;}
{OCT} { printf("OCT at line %d, char %d: %s.\n", yylineno, charLoc, yytext); charLoc += yyleng; }
{SINGLECOMMENT} { printf("COMMENT at line %d, char %d: %s.\n", yylineno, charLoc, yytext); charLoc += yyleng; }
{MULTICOMMENT} { printf("COMMENT at line %d, char %d: %s.\n", yylineno, charLoc, yytext); charLoc += yyleng; }
{TYPE} { printf("TYPE at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
";" { printf("SEMI at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"," { printf("COMMA at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"=" { printf("ASSIGNOP at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
{RELOP} { printf("RELOP at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"+" { printf("PLUS at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"-" { printf("MINUS at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"*" { printf("STAR at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"/" { printf("DIV at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"&&" { printf("AND at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"||" { printf("OR at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"." { printf("DOT at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"!" { printf("NOT at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"(" { printf("LP at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
")" { printf("RP at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"[" { printf("LB at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"]" { printf("RB at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"{" { printf("LC at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
"}" { printf("RC at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
{ID} { printf("ID at line %d,char %d: %s.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
. { printf("ERROR at line %d,char %d, Myterious character: '%s'.\n",yylineno,charLoc,yytext); charLoc += yyleng; }

%%


int main(int argc, char** argv){
    if(argc>1){
        if(!(yyin=fopen(argv[1],"r"))){
            perror(argv[1]);
            return 1;
        }
    }
    while (yylex()!=0)
    return 0;
}

// ERROROCT ([0])([0-9]|LETTER)+
// ERRORHEX 0[x,X][LETTER|DIGIT]+
// ERRORFLOAT [0-9]*\.
// ERROREEFLOAT 
// {ERROROCT} { printf("ERROR at line %d,char %d: Illegal octal number: '%s'.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
// {ERRORHEX} { printf("ERROR at line %d,char %d: Illegal octal number: '%s'.\n",yylineno,charLoc,yytext); charLoc += yyleng; }
// {ERRORFLOAT} {printf("ERROR at line %d,char %d: Illegal float number: '%s'.\n",yylineno,charLoc,yytext);charLoc += yyleng;}