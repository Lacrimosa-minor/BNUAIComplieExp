%{
	#include<stdio.h>
	//这里写文件开头部分的内容，主要是头文件
}%

/*终结符部分，凡是未在这里标记的，都是非终结符*/
%token INT
%token LP
...
/*终结符大写，非终结符驼峰写法是良好的习惯和美德*/
/*在这里面定义的，都可以成为Flex的返回值！*/    


%%
/*产生式区域，书写所有产生式，格式见下*/
DefList : Def DefList {/*语义动作附在产生式之后，默认语义动作为$$ = $1*/ 
						/*语义值的具体值通过yyval定义，类型可以通过type尖括号定义*/}
		| /*empty*/  /*empty写个注释注明最好*/
DecList : Dec
		| Dec COMMA DecList
%%

int main(){
	//...
}
