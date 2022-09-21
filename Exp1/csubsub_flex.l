%option yylineno

%{
    int charLoc = 1;
%}

CUTTER [^0-9A-Za-z_]
ID [a-zA-Z_][a-zA-Z0-9_]*/{CUTTER}
INT [+-]?[1-9][0-9]+
FLOAT ([0-9]+\.[0-9]*)|([0-9]*\.[0-9]+)
SINGLECOMMENT \/\/.*
MULTICOMMENT \/\*(.*?\n)*?.*?\*\
OCT 0[1-7][0-7]*
HEX 0[x,X][0-9a-fA-F]*
EFLOAT [1-9]\.[0-9]+[Ee][+,-]?[1-9][0-9]*
SPACE [ \s\t]+
TYPE (int)|(float)
RELOP >|<|(>=)|(<=)|(==)|(!=)

%%
"\n" {charLoc = 1;}
{SPACE} {charLoc += yyleng;}

"struct" {/*A*/printf("STRUCT at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"return" {/*A*/printf("RETURN at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"if" {/*A*/printf("IF at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"else" {/*A*/printf("ELSE at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"while" {/*A*/printf("WHILE at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
{EFLOAT} {/*A*/printf("FLOAT at line %d, char %d: %s.\n", yylineno, charLoc, yytext);/*B*/charLoc += yyleng;/*C*/}
{FLOAT} {printf("FLOAT at line %d,char %d: %s.\n",yylineno,charLoc,yytext);charLoc += yyleng;}
{HEX} {/*A*/printf("HEX at line %d, char %d: %s.\n", yylineno, charLoc, yytext);/*B*/charLoc += yyleng;/*C*/}
{INT} {printf("INT at line %d,char %d: %s.\n",yylineno,charLoc,yytext);charLoc += yyleng;}
{OCT} {/*A*/printf("OCT at line %d, char %d: %s.\n", yylineno, charLoc, yytext);/*B*/charLoc += yyleng;/*C*/}
{SINGLECOMMENT} {/*A*/printf("COMMENT at line %d, char %d: %s.\n", yylineno, charLoc, yytext);/*B*/charLoc += yyleng;/*C*/}
{MULTICOMMENT} {/*A*/printf("COMMENT at line %d, char %d: %s.\n", yylineno, charLoc, yytext);/*B*/charLoc += yyleng;/*C*/}
{TYPE} {/*A*/printf("TYPE at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
";" {/*A*/printf("SEMI at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"," {/*A*/printf("COMMA at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"=" {/*A*/printf("ASSIGNOP at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
{RELOP} {/*A*/printf("RELOP at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"+" {/*A*/printf("PLUS at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"-" {/*A*/printf("MINUS at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"*" {/*A*/printf("STAR at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"/" {/*A*/printf("DIV at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"&&" {/*A*/printf("AND at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"||" {/*A*/printf("OR at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"." {/*A*/printf("DOT at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"!" {/*A*/printf("NOT at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"(" {/*A*/printf("LP at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
")" {/*A*/printf("RP at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"[" {/*A*/printf("LB at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"]" {/*A*/printf("RB at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"{" {/*A*/printf("LC at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"}" {/*A*/printf("RC at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
{ID} {/*A*/printf("ID at line %d,char %d: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
. {/*A*/printf("ERROR at line %d,char %d, Myterious character: '%s'.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}

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
// {ERROROCT} {/*A*/printf("ERROR at line %d,char %d: Illegal octal number: '%s'.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
// {ERRORHEX} {/*A*/printf("ERROR at line %d,char %d: Illegal octal number: '%s'.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
// {ERRORFLOAT} {printf("ERROR at line %d,char %d: Illegal float number: '%s'.\n",yylineno,charLoc,yytext);charLoc += yyleng;}