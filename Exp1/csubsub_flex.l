%option yylineno

%{
    int charLoc = 1;
    //��¼���ڶ�ȡ���ڼ����ַ����tokenҪ��,ע�⻻�й��㡣
    //����ʱʹ��������������滹�����⣬���Կ϶�����Ҫ�ĵ�
    //��¼����ľ���yylineno
%}

SINGLECOMMENT \/\/.*
MULTICOMMENT \/\*(.*?\n)*?.*?\*\/
OCTINT 0[1-7][0-7]*
HEXINT 0x(?i)[0-9|a-f]*
EFLOAT [1-9].[0-9]*E[+,-][1-9][0-9]*

%%
"\n" {charLoc = 1;}
"\t+" {charLoc += yyleng;}
" +" {charLoc += yyleng;}

{SINGLECOMMENT} {/*A*/printf("COMMENT at line %d, char %D: %s.\n", yylineno, charLoc, yytext);/*B*/charLoc += yyleng;/*C*/}
{MULTICOMMENT} {/*A*/printf("COMMENT at line %d, char %D: %s.\n", yylineno, charLoc, yytext);/*B*/charLoc += yyleng;/*C*/}
{OCTINT} {/*A*/printf("OCTINT at line %d, char %D: %s.\n", yylineno, charLoc, yytext);/*B*/charLoc += yyleng;/*C*/}
{HEXINT} {/*A*/printf("HEXINT at line %d, char %D: %s.\n", yylineno, charLoc, yytext);/*B*/charLoc += yyleng;/*C*/}
{EFLOAT} {/*A*/printf("EFLOAT at line %d, char %D: %s.\n", yylineno, charLoc, yytext);/*B*/charLoc += yyleng;/*C*/}

";" {/*A*/printf("SEMI at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"," {/*A*/printf("COMMA at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"=" {/*A*/printf("ASSIGNOP at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
">|<|>=|<=|==|!=" {/*A*/printf("RELOP at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"+" {/*A*/printf("PLUS at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"-" {/*A*/printf("MINUS at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"*" {/*A*/printf("STAR at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"/" {/*A*/printf("DIV at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"&&" {/*A*/printf("AND at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"||" {/*A*/printf("OR at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"." {/*A*/printf("DOT at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"!" {/*A*/printf("NOT at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"int|float" {/*A*/printf("TYPE at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"(" {/*A*/printf("LP at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
")" {/*A*/printf("RP at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"[" {/*A*/printf("LB at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"]" {/*A*/printf("RB at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"{" {/*A*/printf("LC at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"}" {/*A*/printf("RC at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"struct" {/*A*/printf("STRUCT at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"return" {/*A*/printf("RETURN at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"if" {/*A*/printf("IF at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"else" {/*A*/printf("ELSE at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"while" {/*A*/printf("WHILE at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}

%%

int main(int argc, char** argv){
    if(argc>1){
        if(!(yyin=fopen(argv[1],"r"))){
            perror(argv[1]);
            return 1;
        }
    }
    while (yylex()!=0);
    return 0;
}