%option yylineno

%{
    #define YYSTYPE Node*
    #include "sign_stack.c"
    typedef struct yyltype{
        int first_line;
        int first_column;
        int last_line;
        int last_column;
        int missing_flag;
        sign_stack* stackptr; 
        char missing_char;
    }yyltype;
    #define YYLTYPE yyltype
    #include "syntax_tree.c"
    #include "csubsub_bison.tab.h"

    int yycolumn = 1;
    int charLoc = 1;
    sign_stack mystack;

    #define YY_USER_ACTION yylloc.first_line=yylloc.last_line=yylineno;\
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
"struct" { 
    struct Node *pNode = createNode("STRUCT", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    push(S_START1, yylloc.stackptr);
    return STRUCT;  }
"return" { 
    struct Node *pNode = createNode("RETURN", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    push(S_START1, yylloc.stackptr);
    return RETURN; 
}
"if" { 
    struct Node *pNode = createNode("IF", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    push(S_START2, yylloc.stackptr);
    return IF; 
}
"else" { 
    struct Node *pNode = createNode("ELSE", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    push(S_START2, yylloc.stackptr);
    return ELSE; 
}
"while"  { 
    struct Node *pNode = createNode("WHILE", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    push(S_START2, yylloc.stackptr);
    return WHILE; 
}

{ERRORFLOAT} { printf("ERROR type A at line %d, char %d: Illegal float: %s.\n", yylineno, charLoc, yytext); charLoc += yyleng; }
{ERRORHEX} { printf("ERROR type A at line %d, char %d: Illegal Hex %s.\n", yylineno, charLoc, yytext); charLoc += yyleng; }
{ERROROCT} { printf("ERROR type A at line %d, char %d: Illegal Oct %s.\n", yylineno, charLoc, yytext); charLoc += yyleng; }

{EFLOAT} {  
    struct Node *pNode = createNode("FLOAT", 0, FLOAT_TYPE);
    yylval = pNode;
    pNode->floatValue = atof(yytext);
    push(S_START1, yylloc.stackptr);
    return FLOAT;  }
{FLOAT} { 
    struct Node *pNode = createNode("FLOAT", 0, FLOAT_TYPE);
    yylval = pNode;
    pNode->floatValue = atof(yytext);
    push(S_START1, yylloc.stackptr);
    return FLOAT; }
{HEX} { struct Node *pNode = createNode("INT", 0, INT_TYPE);
        yylval = pNode;
        pNode->intValue = atoi(yytext);
        push(S_START1, yylloc.stackptr);
        return INT ; }
{INT} { struct Node *pNode = createNode("INT", 0, INT_TYPE);
        yylval = pNode;
        pNode->intValue = atoi(yytext);
        push(S_START1, yylloc.stackptr);
        return INT; }
{OCT} { struct Node *pNode = createNode("INT", 0, INT_TYPE);
        yylval = pNode;
        pNode->intValue = atoi(yytext);
        push(S_START1, yylloc.stackptr);
        return INT ; }
{SINGLECOMMENT} {} 
{MULTICOMMENT} {}
{TYPE} { 
    struct Node *pNode = createNode("TYPE", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    push(S_START2, yylloc.stackptr);
    return TYPE;  }
";" { 
    struct Node *pNode = createNode("SEMI", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    push(S_SEMI, yylloc.stackptr);
    return SEMI;  }
"," { 
    struct Node *pNode = createNode("COMMA", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    return COMMA;  }
"=" {  
    struct Node *pNode = createNode("ASSIGNOP", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    return ASSIGNOP;  }
{RELOP}  { 
    struct Node *pNode = createNode("RELOP", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    return RELOP; 
}
"+" { 
    struct Node *pNode = createNode("PLUS", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    return PLUS; 
}
"-"  { 
    struct Node *pNode = createNode("MINUS", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    return MINUS; 
}
 "*" { 
    struct Node *pNode = createNode("STAR", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    return STAR; 
}
 "/" { 
    struct Node *pNode = createNode("DIV", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    return DIV; 
}
"&&" { 
    struct Node *pNode = createNode("AND", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    return AND; 
}
"||" { 
    struct Node *pNode = createNode("OR", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    return OR; 
}
 "!" { 
    struct Node *pNode = createNode("NOT", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    return NOT; 
}
"("  { 
    struct Node *pNode = createNode("LP", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    push(S_LP, yylloc.stackptr);
    return LP; 
}
")" { 
    struct Node *pNode = createNode("RP", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    push(S_RP, yylloc.stackptr);
    return RP; 
}
"[" { 
    struct Node *pNode = createNode("LB", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    push(S_LB, yylloc.stackptr);
    return LB; 
}
"]"  { 
    struct Node *pNode = createNode("RB", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    push(S_RB, yylloc.stackptr);
    return RB; 
}
"{" { 
    struct Node *pNode = createNode("LC", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    push(S_LC, yylloc.stackptr);
    return LC; 
}
"}" { 
    struct Node *pNode = createNode("RC", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    push(S_RC, yylloc.stackptr);
    return RC; 
}


"." { 
    struct Node *pNode = createNode("DOT", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    return DOT; }

{ID} { 
    struct Node *pNode = createNode("ID", 0, STRING_TYPE);
    yylval = pNode;
    pNode->id_name = strdup(yytext);
    push(S_START1, yylloc.stackptr);
    return ID;  
}
. {printf("ERROR type A at line %d,char %d, Mysterious character: '%s'.\n",yylineno,charLoc,yytext); charLoc += yyleng;}

%%


// int main(int argc, char** argv){
//     if(argc<=1) return 1;
//     FILE* f=fopen(argv[1],"r");
//     if(!f){
//         perror(argv[1]);
//         return 1;
//     }
//     yyrestart(f);
//     yyparse();
//     return 0;
// }

