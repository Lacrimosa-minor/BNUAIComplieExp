%{
	#include<stdio.h>
	#include"syntax_tree.h"
	#define YYSTYPE Node
	//这里写文件开头部分的内容，主要是头文件
}%

/*终结符部分，凡是未在这里标记的，都是非终结符*/
%token STRUCT
%token RETURN
%token IF
%token ELSE
%token WHILE
%token FLOAT
%token INT
// %token COMMENT
%token TYPE
%token SEMI
%token COMMA
%token ASSIGNOP
%token RELOP
%token PLUS
%token MINUS
%token STAR
%token DIV
%token AND
%token OR
%token DOT
%token NOT
%token LP
%token RP
%token LB
%token RB
%token LC
%token RC
%token ID
/*终结符大写，非终结符驼峰写法是良好的习惯和美德*/
/*在这里面定义的，都可以成为Flex的返回值！*/    
/*优先级在这里*/
/*优先级问题，先不定义，等到第一轮结果出来了，再处理优先级问题*/


%%
/*产生式区域，书写所有产生式，格式见下*/
// DefList : Def DefList {/*语义动作附在产生式之后，默认语义动作为$$ = $1*/ 
// 						/*语义值的具体值通过yyval定义，类型可以通过type尖括号定义*/}
// 		| /*empty*/  /*empty写个注释注明最好*/
// DecList : Dec
// 		| Dec COMMA DecList

/*高阶定义*/

Program : ExtDefList

ExtDefList : ExtDef ExtDefList { $$ = insertNode($1, "ExtDefList", @1.first_line, NONTERMINAL);
								 $1 -> brother = $2;}
		| /*empty*/ { $$ = insertNode(NULL, "ExtDefList", -1 , NONTERMINAL);}

ExtDef : Specifier ExtDecList SEMI { $$ = insertNode($1, "ExtDef", @1.first_line, NONTERMINAL);
									 $1 -> brother = $2;
									 $2 -> brother = $3;}
		| Specifier SEMI{ $$ = insertNode($1, "ExtDef", @1.first_line, NONTERMINAL);
						  $1 -> brother = $2;}
		| Specifier FunDec CompSt { $$ = insertNode($1, "ExtDef", @1.first_line, NONTERMINAL);
									$1 -> brother = $2;
									$2 -> brother = $3;}

ExtDecList : VarDec { $$ = insertNode($1, "ExtDecList", @1.first_line, NONTERMINAL);}
		| VarDec COMMA ExtDecList { $$ = insertNode($1, "ExtDecList", @1.first_line, NONTERMINAL);
									 $1 -> brother = $2;
									 $2 -> brother = $3;}


/*Specifiers*/

Specifier : TYPE { $$ = insertNode($1, "Specifier", @1.first_line, NONTERMINAL);}
		| StructSpecifier { $$ = insertNode($1, "Specifier", @1.first_line, NONTERMINAL);}

StructSpecifier : STRUCT OptTag LC DefList RC { $$ = insertNode($1, "StructSpecifier", @1.first_line, NONTERMINAL);
												  $1 -> brother = $2;
												  $2 -> brother = $3;
												  $3 -> brother = $4;
												  $4 -> brother = $5;}
		| STRUCT Tag { $$ = insertNode($1, "StructSpecifier", @1.first_line, NONTERMINAL);
					   $1 -> brother = $2;}

OptTag : ID { $$ = insertNode($1, "OptTag", @1.first_line, NONTERMINAL);}
		| /*empty*/ { $$ = insertNode(NULL, "Specifier", -1, NONTERMINAL);}

Tag : ID { $$ = insertNode($1, "Tag", @1.first_line, NONTERMINAL);}

/*Declarators*/

VarDec : ID { $$ = insertNode($1, "VarDec", @1.first_line, NONTERMINAL);}
		| VarDec LB INT RB {$$ = insertNode($1, "VarDec", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;
							$3 -> brother = $4;}

FunDec : ID LP VarList RP {$$ = insertNode($1, "FunDec", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;
							$3 -> brother = $4;}
		| ID LP RP {$$ = insertNode($1, "FunDec", @1.first_line, NONTERMINAL);
					$1 -> brother = $2;
					$2 -> brother = $3;}

VarList : ParamDec COMMA VarList{$$ = insertNode($1, "VarList", @1.first_line, NONTERMINAL);
					$1 -> brother = $2;
					$2 -> brother = $3;}
		| ParamDec {$$ = insertNode($1, "VarList", @1.first_line, NONTERMINAL);}

ParamDec : Specifier VarDec {$$ = insertNode($1, "ParamDec", @1.first_line, NONTERMINAL);
					$1 -> brother = $2;}

/*Statements*/

CompSt : LC DefList StmtList RC {$$ = insertNode($1, "CompSt", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;
							$3 -> brother = $4;}

StmtList : Stmt StmtList {$$ = insertNode($1, "StmtList", @1.first_line, NONTERMINAL);
					$1 -> brother = $2;}
		| /*empty*/ { $$ = insertNode(NULL, "StmtList", -1, NONTERMINAL);}

/*严重怀疑这里有大问题，一种if eles语句后面跟的是Stmt,
这样子的话完全可以写出一些不合法的句子。。。记得多回来看看*/ 
Stmt : Exp SEMI
		| CompSt
		| RETURN Exp SEMI {$$ = insertNode($1, "Stmt", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;}
		| IF LP Exp RP Stmt {$$ = insertNode($1, "Stmt", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;
							$3 -> brother = $4;
							$4 -> brother = $5;}
		| IF LP Exp RP Stmt ELSE Stmt {$$ = insertNode($1, "Stmt", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;
							$3 -> brother = $4;
							$4 -> brother = $5;
							$5 -> brother = $6;
							$6 -> brother = $7;}
		| WHILE LP Exp RP Stmt {$$ = insertNode($1, "Stmt", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;
							$3 -> brother = $4;
							$4 -> brother = $5;}

/*Local Definitions*/

DefList : Def DefList {$$ = insertNode($1, "DefList", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;}
		| /*empty*/ {$$ = insertNode(NULL, "DefList", @1.first_line, NONTERMINAL);}

Def : Specifier DecList SEMI {$$ = insertNode($1, "Def", @1.first_line, NONTERMINAL);
							  $1 -> brother = $2;
							  $2 -> brother = $3;}

DecList : Dec   {$$ = insertNode($1, "DecList", @1.first_line, NONTERMINAL);}
		| Dec COMMA DecList {$$ = insertNode($1, "DecList", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;}

Dec : VarDec {$$ = insertNode($1, "Dec", @1.first_line, NONTERMINAL);}
		| VarDec ASSIGNOP Exp {$$ = insertNode($1, "Dec", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;}

/*Expressions*/

Exp : Exp ASSIGNOP Exp {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;}
		| Exp AND Exp {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;}
		| Exp OR Exp {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;}
		| Exp RELOP Exp {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;}
		| Exp PLUS Exp {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;}
		| Exp MINUS Exp {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;}
		| Exp STAR Exp {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;}
		| Exp DIV Exp {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;}
		| LP Exp RP {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;}
		| MINUS Exp {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;}
		| NOT Exp {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;}
		| ID LP Args RP {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;
							$3 -> brother = $4;}
		| ID LP RP {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;}
		| Exp LB Exp RB {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;
							$3 -> brother = $4;}
		| Exp DOT ID {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;}
		| ID {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);}
		| INT {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);}
		| FLOAT {$$ = insertNode($1, "Exp", @1.first_line, NONTERMINAL);}

Args : Exp COMMA Args {$$ = insertNode($1, "Args", @1.first_line, NONTERMINAL);
							$1 -> brother = $2;
							$2 -> brother = $3;}
		| Exp {$$ = insertNode($1, "Args", @1.first_line, NONTERMINAL);}

%%

int main(int argc char** argv){
   	if(argc <=1) {return 1};
   	FILE* f = fopen(argv[1], "r");
   	if(!f){
		perror(argv[1]);
    	return 1;
    }
   	yyrestart(f);
   	yyparse();
   	return 0;  
}