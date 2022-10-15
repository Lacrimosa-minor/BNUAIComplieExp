%{
	#include<stdio.h>
	#include"syntax_tree.h"
	#define YYSTYPE Node
	//����д�ļ���ͷ���ֵ����ݣ���Ҫ��ͷ�ļ�
}%

/*�ս�����֣�����δ�������ǵģ����Ƿ��ս��*/
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
/*�ս����д�����ս���շ�д�������õ�ϰ�ߺ�����*/
/*�������涨��ģ������Գ�ΪFlex�ķ���ֵ��*/    
/*���ȼ�������*/
/*���ȼ����⣬�Ȳ����壬�ȵ���һ�ֽ�������ˣ��ٴ������ȼ�����*/


%%
/*����ʽ������д���в���ʽ����ʽ����*/
// DefList : Def DefList {/*���嶯�����ڲ���ʽ֮��Ĭ�����嶯��Ϊ$$ = $1*/ 
// 						/*����ֵ�ľ���ֵͨ��yyval���壬���Ϳ���ͨ��type�����Ŷ���*/}
// 		| /*empty*/  /*emptyд��ע��ע�����*/
// DecList : Dec
// 		| Dec COMMA DecList

/*�߽׶���*/

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

/*���ػ��������д����⣬һ��if eles�����������Stmt,
�����ӵĻ���ȫ����д��һЩ���Ϸ��ľ��ӡ������ǵö��������*/ 
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