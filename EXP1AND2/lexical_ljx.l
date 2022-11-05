%option yylineno
%{
  #include "parse_ljx_mogai.tab.h"
  //#include "tree.c"
  #include <stdio.h>
  #include <stdlib.h>
  //extern int line_check[5000];
  int yycolumn = 1;
  #define TABLEN 4
  #define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
        yylloc.first_column = yycolumn; \
        yylloc.last_column = yycolumn + yyleng - 1; \
        yycolumn += yyleng;
%}

INT (0|[1-9][0-9]*)|(0[0-7]+)|(0[xX][0-9A-Fa-f]+)
ILLEGALINT8 0[0-7]*[8-9]+[0-9]*
ILLEGALINT16 0[xX][0-9A-Fa-f]*[g-zG-Z]+[0-9a-zA-Z]*
FLOAT ([0-9]+{DOT}[0-9]*|{DOT}[0-9]+)|(([0-9]+{DOT}[0-9]*|{DOT}[0-9]+)[eE][+-]?[0-9]+)
ILLEGALFLOAT (([0-9]*)*(([eE][+-]?[0-9]*\.[0-9]*)|([eE][a-zA-Z]*)))|({FLOAT}(([eE][+-]?[0-9]*\.[0-9]*)|([eE][a-zA-Z]*)))|(([0-9]*)*[eE][+-]?[0-9]+)
SEMI ;
COMMA ,
ASSIGNOP =
RELOP >|<|>=|<=|==|!=
PLUS \+
MINUS -
STAR \*
DIV \/
AND &&
OR \|\|
DOT \.
NOT !
TYPE int|float
LP \(
RP \)
LB \[
RB \]
LC \{
RC \}
STRUCT struct
RETURN return
IF if
ELSE else
WHILE while 
SPACES [ \t]+
LF [\n\r\f\v]+
ID [_a-zA-Z][_0-9a-zA-Z]*

%%
"/*" {
    char c;
    int line = yylineno;
    while ((c = input()) != EOF) {
        if (c == '*') {
            c = input();
            if (c == '/'){
                break;
            }
        }
    }
    line_check[line - 1] = 1;
    if (c == EOF) printf("Error type B at Line %d: LACK OF */.\n", yylineno);
}

"//" {   
    char c;
    while ((c = input()) != '\n');
}

{INT} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "INT", yylineno, NULL, NULL, N_INT);
    node->subtype.intVal = atoi(yytext);
    yylval = node;
    return INT;
}
{ILLEGALINT8} {
    error_count += 1;
    printf("ERROR TYPE A at line %d: Illegal octal number: '%s'\n",yylineno,yytext);
}

{ILLEGALINT16} {
    error_count += 1;
    printf("ERROR TYPE A at line %d: Illegal hexadecimal number: '%s'\n",yylineno,yytext);
    }

{SEMI} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "SEMI", yylineno, NULL, NULL, N_SEMI);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return SEMI;
    }
{COMMA} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "COMMA", yylineno, NULL, NULL, N_COMMA);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return COMMA;
    }
{ASSIGNOP} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "ASSIGNOP", yylineno, NULL, NULL, N_ASSIGNOP);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return ASSIGNOP;
    }
{RELOP} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "RELOP", yylineno, NULL, NULL, N_RELOP);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return RELOP;
    }
{PLUS} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "PLUS", yylineno, NULL, NULL, N_PLUS);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return PLUS;
    }
{MINUS} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "MINUS", yylineno, NULL, NULL, N_MINUS);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return MINUS;
    }
{STAR} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "STAR", yylineno, NULL, NULL, N_STAR);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return STAR;
    }
{DIV} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "DIV", yylineno, NULL, NULL, N_DIV);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return DIV;
    }
{AND} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "AND", yylineno, NULL, NULL, N_AND);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return AND;
    }
{OR} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "OR", yylineno, NULL, NULL, N_OR);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return OR;
    }
{DOT} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "DOT", yylineno, NULL, NULL, N_DOT);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return DOT;
    }
{NOT} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "NOT", yylineno, NULL, NULL, N_NOT);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return NOT;
    }
{TYPE} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "TYPE", yylineno, NULL, NULL, N_TYPE);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return TYPE;
    }
{LP} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "LP", yylineno, NULL, NULL, N_LP);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return LP;
    }
{RP} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "RP", yylineno, NULL, NULL, N_RP);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return RP;
    }
{LB} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "LB", yylineno, NULL, NULL, N_LB);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return LB;
    }
{RB} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "RB", yylineno, NULL, NULL, N_RB);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return RB;
    }
{LC} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "LC", yylineno, NULL, NULL, N_LC);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return LC;
    }
{RC} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "RC", yylineno, NULL, NULL, N_RC);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return RC;
    }
{STRUCT} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "STRUCT", yylineno, NULL, NULL, N_STRUCT);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return STRUCT;
    }
{RETURN} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "RETURN", yylineno, NULL, NULL, N_RETURN);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return RETURN;
    }
{IF} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "IF", yylineno, NULL, NULL, N_IF);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return IF;
    }
{ELSE} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "ELSE", yylineno, NULL, NULL, N_ELSE);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return ELSE;
    }
{WHILE} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "WHILE", yylineno, NULL, NULL, N_WHILE);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return WHILE;
    }
{ID} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "ID", yylineno, NULL, NULL, N_ID);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    return ID;
    }
{FLOAT} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "FLOAT", yylineno, NULL, NULL, N_FLOAT);
    node->subtype.floatVal= atof(yytext);
    yylval = node;
    return FLOAT;
    }
{ILLEGALFLOAT} {
    error_count += 1;
    printf("ERROR TYPE A at line %d: Illegal float number: '%s'\n",yylineno,yytext);
    }

{LF} {
    treeNode node = (treeNode)malloc(sizeof(struct node));
    nodeInit(node, "OR", yylineno, NULL, NULL, (int)ID);
    node->subtype.IDVal = strdup(yytext);
    yylval = node;
    yycolumn = 1;
    }//换行
{SPACES} { yycolumn ++; }
[^{SPACES}{LF}] {
    error_count += 1;
    if(line_check[yylineno - 1] == 0)
        line_check[yylineno - 1] = 1;
    printf("ERROR TYPE A at line %d: Mysterious character: '%s'.\n",yylineno,yytext);
    }



%%

/*int main(int argc, char** argv)
{
	if(argc <= 1) return 1;
	FILE* f = fopen(argv[1], "r");
	if(!f){
		perror(argv[1]);
		return 1;
	}
	yyrestart(f);
	yyparse();
	return 0;
}*/
		
