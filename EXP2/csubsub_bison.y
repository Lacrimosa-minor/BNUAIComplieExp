%{
	#include<stdio.h>
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

/*���ػ��������д����⣬һ��if eles�����������Stmt,
�����ӵĻ���ȫ����д��һЩ���Ϸ��ľ��ӡ������ǵö��������*/ 
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