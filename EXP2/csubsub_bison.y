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


%%
/*����ʽ������д���в���ʽ����ʽ����*/
DefList : Def DefList {/*���嶯�����ڲ���ʽ֮��Ĭ�����嶯��Ϊ$$ = $1*/ 
						/*����ֵ�ľ���ֵͨ��yyval���壬���Ϳ���ͨ��type�����Ŷ���*/}
		| /*empty*/  /*emptyд��ע��ע�����*/
DecList : Dec
		| Dec COMMA DecList

Program : ExtDefList

ExtDefList : ExtDef ExtDefList
		| /*empty*/

ExtDef : Specifier ExtDecList SEMI
		| Specifier SEMI
		| Specifier FunDec CompSt

ExtDecList : VarDec
		| VarDec COMMA ExtDecList {$$ = $1 + $2}


%%

int main(){
	//...
}
