%{
	#include<stdio.h>
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
%token COMMENT
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

ExtDefList : ExtDef ExtDefList
		| /*empty*/

ExtDef : Specifier ExtDecList SEMI
		| Specifier SEMI
		| Specifier FunDec CompSt

ExtDecList : VarDec
		| VarDec COMMA ExtDecList


/*Specifiers*/

Specifier : TYPE
		| StructSpecifier

StructSpecifier : STRUCT OptTag LC DefList RC
		| STRUCT Tag

OptTag : ID
		| /*empty*/

Tag : ID

/*Declarators*/

VarDec : ID
		| VarDec LB INT RB

FunDec : ID LP VarList RP
		| ID LP RP

VarList : ParamDec COMMA VarList
		| ParamDec

ParamDec : Specifier VarDec

/*Statements*/

CompSt : LC DefList StmtList RC

StmtList : Stmt StmtList
		| /*empty*/

/*严重怀疑这里有大问题，一种if eles语句后面跟的是Stmt,
这样子的话完全可以写出一些不合法的句子。。。记得多回来看看*/ 
Stmt : Exp SEMI
		| CompSt
		| RETURN Exp SEMI
		| IF LP Exp RP Stmt
		| IF LP Exp RP Stmt ELSE Stmt
		| WHILE LP Exp RP Stmt

/*Local Definitions*/

DefList : Def DefList
		| /*empty*/

Def : Specifier DecList SEMI

DecList : Dec
		| Dec COMMA DecList

Dec : VarDec
		| VarDec ASSIGNOP Exp

/*Expressions*/

Exp : Exp ASSIGNOP Exp
		| Exp AND Exp
		| Exp OR Exp
		| Exp RELOP Exp
		| Exp PLUS Exp
		| Exp MINUS Exp
		| Exp STAR Exp
		| Exp DIV Exp
		| LP Exp RP
		| MINUS Exp
		| NOT Exp
		| ID LP Args RP
		| ID LP RP
		| Exp LB Exp RB
		| Exp DOT ID
		| ID
		| INT
		| FLOAT

Args : Exp COMMA Args
		| Exp

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