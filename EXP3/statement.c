%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "tree.c"

    #define YYSTYPE treeNode

    int line_check[5000];
    extern int yylineno;
    void yyerror(char*);
    void myerror(char *msg);
    int yylex();
    int error_count = 0;
%}
%token INT                         /* int 类型 */
%token FLOAT                       /* float 类型 */
%token TYPE                        /* TYPE 终结符 */
%token LF                          /* 换行符 \n */
%token ID                          /* 标识符 */ 
%token SEMI COMMA DOT              /* 结束符号 ; , */
%token ASSIGNOP RELOP              /* 比较赋值符号 = > < >= <= == != */
%token PLUS MINUS STAR DIV         /* 运算符 + - * / */
%token AND OR NOT                  /* 判断符号 && || ! */
%token LP RP LB RB LC RC           /* 括号 ( ) [ ] { } */
%token STRUCT                      /* struct */
%token RETURN                      /* return */
%token IF                          /* if */
%token ELSE                        /* else */
%token WHILE                       /* while */

// 定义结合性和优先级次序
%right ASSIGNOP
%left OR
%left AND
%nonassoc RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%right DOT LP LB RP RB
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%
//High-level Definitions

Program : ExtDefList{
    $$ = upConstruct($1, "Program", @1.first_line, NONTERMINAL);
    myTree = $$;
};

ExtDefList : %empty{
        //修改$$ = insertNode(NULL, "ExtDefList", yylineno, NONTERMINAL);
        $$ = upConstruct(NULL, "ExtDefList", yylineno, NONTERMINAL);
        myTree = $$;
    }
    |ExtDef ExtDefList{
        $$ = upConstruct($1, "ExtDefList", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        myTree = $$;
    }
    
;

ExtDef : Specifier ExtDecList SEMI{
        $$ = upConstruct($1, "ExtDef", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
		struct ast* p = $2;		//取ExtDecList
				while(p->child_num==3)	//如果有3个孩子结点，就是“ExtDecList->VarDec COMMA ExtDecList”
				{
					p = p->left->right->right;	//继续取ExtDecList
					char tag[128];
					strcpy(tag," \"");
					strcat(tag,p->content);
					strcat(tag,"\"");
					if(find_var(p)) myerror(tag,"Redefined variable",3);		//如果在变量符号表中发现了这个变量
					else 
					{	//没发现
						if($1->flag == 0 || $1->flag == 1) Insert_Var_Table(2,p,$1);	//创建新变量（基本变量和数组变量）
						else if($1->flag == 3) 	//结构体变量
						{
							if(find_struct($1->left->left->right)) Insert_Var_Table(2,p,$1->left->left->right);	//如果在结构体符号表中找到了结构体名称，说明已经定义过结构体，可以创建变量
						}
					}
				}
				//循环结束后是最后一个变量
				if(find_var($2))
				{
					char tag[128];
					strcpy(tag," \"");
					strcat(tag,$2->content);
					strcat(tag,"\"");
					myerror(tag,"Redefined variable",3);	//如果在符号表中找到该变量
				}
				
				else
				{	//没找到重复上面的步骤，查找结构体是否已经定义
					if($1->flag == 0 || $1->flag == 1) Insert_Var_Table(2,$2,$1);
					else if($1->flag == 3) 
					{
						if(find_struct($1->left->left->right)) Insert_Var_Table(2,$2,$1->left->left->right);
					}
				}
    }
    | Specifier SEMI{
        $$ = upConstruct($1, "ExtDef", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        myTree = $$;
    }
    | Specifier FunDec CompSt{
        $$ = upConstruct($1, "ExtDef", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
		struct Function *p = find_func($2);		//在函数表里查找函数名和形参
				if(p)	//如果找到了
				{
					int num,define=p->define,vacmp= !strcmp(p->valist_type,find_valist($2,&num));	
					//vacmp=0表示此时函数的形参列表与函数符号表中找到的同名函数的形参列表不相同；vacmp=1表明相同
					if(define && vacmp) //如果已经定义了但是函数的形参列表不同，说明这个函数名已经定义过了，不能再定义了
					{
						char tag[128];
						strcpy(tag," \"");
						strcat(tag,$2->content);
						strcat(tag,"\"");
						myerror(tag,"Redefined function",4);
					}
						
					else if(!define && vacmp) //如果没有定义并且形参列表相同，说明函数已经声明了
						p->define = 1;		//将该函数置为已定义
					else	//剩下的两种情况分别是①定义了而且形参列表相同②没定义而且形参列表不同
						Insert_Func_Table(2,$2,$1)->define = 1;		//定义函数，插入符号表
				}
				else if(!p) Insert_Func_Table(2,$2,$1)->define = 1;	//如果符号表里没找到这个函数，直接定义这个函数
				if(check_return_type($2,$3)) myerror("","Type mismatched for return",8);	//检查返回值类型是否和声明的一样
    }
	| Specifier FunDec SEMI		//函数声明
		{
			$$ = upConstruct($1,"ExtDef",@1.first_line, NONTERMINAL);
			struct Function *p = find_func($2);
			if(!p) {
				struct Function *f = Insert_Func_Table(2,$2,$1);
				f->define = 0;	//如果函数表里没有找到，则插入到函数表，但是define置为0
				f->statement = 1;
			}
			else if(p){
				int define = p->define;
				
				int num;
				//int vacmp = !strcmp(p->valist_type,find_valist($2,&num));
				int namecmp = !strcmp(p->funname,$2->content);
				
				int statement = p->statement;
				int define = p->define;
				
				//if(statement && !vacmp) 
				//	myerror($2->content," Incomplete definition of function1",19);
					
				if(statement && namecmp)
					myerror($2->content," Incomplete definition of function",19);
				
				if(!define)
				{
					char tag[128];
					strcpy(tag," \"");
					strcat(tag,$2->content);
					strcat(tag,"\"");
					myerror(tag,"Undefined function",18);	//如果没被定义
				}
				
				else{//如果定义了
					int num,vacmp= !strcmp(p->valist_type,find_valist($2,&num));
					if(!vacmp){	//函数声明的形参列表和定义的不同
						char tag[128];
						strcpy(tag," \"");
						strcat(tag,$2->content);
						strcat(tag,"\"");
						myerror(tag,"Inconsistent declaration of function",19);
					}
					else{
						if(!p->statement)	p->statement = 1;	//如果没有被声明
					}
				}
			}
		}
;

ExtDecList : VarDec{
        $$ = upConstruct($1, "ExtDecList", @1.first_line, NONTERMINAL);
        myTree = $$;
    }
    | VarDec COMMA ExtDecList{
        $$ = upConstruct($1, "ExtDecList", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    /*
    |VarDec error ExtDecList{
        if(line_check[@2.first_line-1]==0){
        line_check[@2.first_line-1]=1;
   }
        char msg[100];
        sprintf( msg, "Syntax error.");
        myerror( msg );
    }*/
;

 /*Specifiers*/
Specifier : TYPE{
        $$ = upConstruct($1, "Specifier", @1.first_line, NONTERMINAL);
        myTree = $$;
    } 
    | StructSpecifier{
        $$ = upConstruct($1, "Specifier", @1.first_line, NONTERMINAL);
        myTree = $$;
    }
;

StructSpecifier : STRUCT OptTag LC DefList RC{
        $$ = upConstruct($1, "StructSpecifier", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        $3->sibling = $4;
        $4->sibling = $5;
        myTree = $$;
		if(find_struct($2)) 
				{
					char tag[128];
					strcpy(tag," \"");
					strcat(tag,$2->content);
					strcat(tag,"\"");
					myerror(tag,"Duplicated name",16);	//如果结构体符号表里找到了该结构体，说明已经用过了这个名字
				}
				
				else Insert_Struct_Table(2, $2, $4);	//没找到就插入符号表
				$$->flag = 3;	//设置变量类型为3：结构体变量
				struct_flag = 0;	//结构体标志位置为0
    }
    | STRUCT Tag{
        $$ = upConstruct($1, "StructSpecifier", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        myTree = $$;
		if(!find_struct($2)) 
				{
					char tag[128];
					strcpy(tag," \"");
					strcat(tag,$2->content);
					strcat(tag,"\"");
					myerror(tag,"Undefined structure",17);		//如果在表中没找到
				}
				
				$$->flag=3;
    }
;

OptTag :  %empty{
        $$ = upConstruct(NULL, "OptTag", yylineno, NONTERMINAL);
        myTree = $$;
		$$->flag = 3;
			sprintf(struct_temp,"struct_temp_%d",s_temp++);
			strcpy(struct_name,struct_temp);
			struct_flag = 1;
    }
    |ID{
        $$ = upConstruct($1, "OptTag", @1.first_line, NONTERMINAL);
        myTree = $$;
		$$->flag=3;
			strcpy(struct_name,$$->content);		//将该非终结符属性赋给struct_name
			struct_flag = 1;		//置为1表明进入结构体的作用域
    }
    
;

Tag : ID{
        $$ = upConstruct($1, "Tag", @1.first_line, NONTERMINAL);
        myTree = $$;
}
;
  StructSpecifier : STRUCT OptTag LC DefList error	{}
  	;
//变量定义

 /*Declarators*/
VarDec : ID{
        $$ = upConstruct($1, "VarDec", @1.first_line, NONTERMINAL);
        myTree = $$;
    }//基本变量
    | VarDec LB INT RB{
        $$ = upConstruct($1, "VarDec", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        $3->sibling = $4;
        myTree = $$;//数组
;
//函数头
FunDec : ID LP VarList RP{
        $$ = upConstruct($1, "FunDec", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        $3->sibling = $4;
        myTree = $$;
    }
    | ID LP RP{
        $$ = upConstruct($1, "FunDec", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    } 
;
//形参列表
VarList : ParamDec COMMA VarList{
        $$ = upConstruct($1, "VarList", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | ParamDec{
        $$ = upConstruct($1, "VarList", @1.first_line, NONTERMINAL);
        myTree = $$;
    }
;
//类似于int a
ParamDec : Specifier VarDec{
        $$ = upConstruct($1, "ParamDec", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        myTree = $$;
    }
;
	
  FunDec : ID RP error RP	{}
  	;
  VarDec : VarDec LB INT error	{}
  	;
  FunDec : ID LP VarList error	{}
    | ID LP error	{}
    	;
 /*Statements*/
 //语句块{花括号括起来}
CompSt : LC DefList StmtList RC{
        $$ = upConstruct($1, "CompSt", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        $3->sibling = $4;
        myTree = $$;
   }
 ;
//语句列表
StmtList : Stmt StmtList{
        $$ = upConstruct($1, "StmtList", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        myTree = $$;
    }
    | %empty{
        $$ = upConstruct(NULL, "StmtList", yylineno, NONTERMINAL);
        myTree = $$;
    }
;
//单条语句   
Stmt : Exp SEMI{
        $$ = upConstruct($1, "Stmt", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        myTree = $$;
    }    
    | CompSt{
        $$ = upConstruct($1, "Stmt", @1.first_line, NONTERMINAL);
        myTree = $$;
    }
    | RETURN Exp SEMI{
        $$ = upConstruct($1, "Stmt", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | IF LP Exp RP Stmt{
        $$ = upConstruct($1, "Stmt", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        $3->sibling = $4;
        $4->sibling = $5;
        myTree = $$;
    }
    | IF LP Exp RP Stmt ELSE Stmt{
        $$ = upConstruct($1, "Stmt", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        $3->sibling = $4;
        $4->sibling = $5;
        $5->sibling = $6;
        $6->sibling = $7;
        myTree = $$;
    }
    | WHILE LP Exp RP Stmt{
        $$ = upConstruct($1, "Stmt", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        $3->sibling = $4;
        $4->sibling = $5;
        myTree = $$;
    }
    | Exp error{
        if(line_check[@2.first_line-1]==0){
        line_check[@2.first_line-1]=1;
   }
        char msg[100];
        sprintf( msg, "Stmt Missing \";\"");
        myerror( msg );
    }
;

 /*Local Definitions*/
 //变量定义
DefList : Def DefList{
        $$ = upConstruct($1, "DefList", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        myTree = $$;
    }
    | %empty{
        $$ = upConstruct(NULL, "DefList", yylineno, NONTERMINAL);
        myTree = $$;
    }
;
//一种类型的变量定义列表
Def : Specifier DecList SEMI{
        $$ = upConstruct($1, "Def", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
		struct ast* p = $2;
		while(p->child_num==3)		//对应“DecList->Dec COMMA DecList”
		{
			p = p->left->right->right;		//一直取DecList
			if(find_var(p)) 	//如果在符号表中找到了
				if(!struct_flag)
				{
					char tag[128];
					strcpy(tag," \"");
					strcat(tag,p->content);
					strcat(tag,"\"");
					myerror(tag,"Redefined variable",3);		//如果不是在结构体作用域内
				}
				
				else 
				{
					char tag[128];
					strcpy(tag," \"");
					strcat(tag,p->content);
					strcat(tag,"\"");
					myerror(tag,"Redefined field ",15);		//如果在结构体作用域内
				}
				
			else 		//符号表中没找到
			{
				if($1->flag == 0) 
				{
					if(strcmp($2->type,$1->content)&&strcmp($2->type,"no_value")){
						myerror("","Type mismatched for assignment",5);
					}
					Insert_Var_Table(2,p,$1);		//基本变量插入到符号表
				}
				else if($1->flag == 3) 		//结构体变量
				{
					if(find_struct($1->left->left->right)) Insert_Var_Table(2,p,$1->left->left->right);		//查找结构体符号表，定义了结构体就插入到符号表中
				}
			}
		}
		//最后一个变量，上述步骤重复一遍
		if(find_var($2)) 
			if(!struct_flag) 
			{
				char tag[128];
				strcpy(tag," \"");
				strcat(tag,$2->content);
				strcat(tag,"\"");
				myerror(tag,"Redefined variable",3);
			}
			
			else 
			{
				char tag[128];
				strcpy(tag," \"");
				strcat(tag,$2->content);
				strcat(tag,"\"");
				myerror(tag,"Redefined field ",15);
				myerror(tag,"Redefined variable ",3);
			}
			
		else
		{
			if($1->flag == 0) 
			{
				if(strcmp($2->type,$1->content)&&strcmp($2->type,"no_value")){
					myerror("","Type mismatched for assignment",5);
				}
				Insert_Var_Table(2,$2,$1);
			}
			else if($1->flag == 3) 
			{
				if(find_struct($1->left->left->right)) Insert_Var_Table(2,$2,$1->left->left->right);
			}
		}
}   
    |error DecList SEMI{
        if(line_check[@1.first_line-1]==0){
            line_check[@1.first_line-1]=1;
        }
        char msg[100];
        sprintf( msg, "Def syntax error");
        myerror( msg );
}

;
//变量列表
DecList : Dec{
        $$ = upConstruct($1, "DecList", @1.first_line, NONTERMINAL);
        myTree = $$;
    }
    | Dec COMMA DecList{
        $$ = upConstruct($1, "DecList", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
;
//变量名
Dec : VarDec{
        $$ = upConstruct($1, "Dec", @1.first_line, NONTERMINAL);
        myTree = $$;
    }
    | VarDec ASSIGNOP Exp{
        $$ = upConstruct($1, "Dec", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }/*
    | VarDec error{
        if(line_check[@1.first_line-1]==0){
            line_check[@1.first_line-1]=1;
        }
        char msg[100];
        sprintf( msg, "Def syntax error");
        myerror( msg );
    }*/
;
	
  Def : Specifier error SEMI	{}
  	;
  Def : Specifier DecList error	{}
  	;
 /*Expressions*/
Exp : Exp ASSIGNOP Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
		struct Variable* temp = find_var($1);
			if(!find_var($1)) //符号表中没找到等号左侧表达式，说明等号左侧不是一个定义的变量
				myerror("","The left-hand side of an assignment must be a variable",6);
			else 
			{
				if(strcmp(temp->type,$3->type)) //等号两侧表达式不是同种类型
				{
					myerror("","Type mismatched for assignment",5);
				}
			}
			
    }
    | Exp AND Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | Exp OR Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | Exp RELOP Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | Exp PLUS Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
		if(strcmp($1->type,$3->type))		//同上，加号两侧表达式不同类型
			{
				myerror("","Type mismatched for operands",7);
				$$->type[0] = '\0';
			}
			else
			{
				strcpy($$->type,$1->type);		//同种类型则将其中一个Exp的type拷贝给父结点
			}
    }
    | Exp MINUS Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
		if(strcmp($1->type,$3->type))		//和加法相同
		{
			myerror("","Type mismatched for operands",7);
			$$->type[0] = '\0';
		}
		else
		{
			strcpy($$->type,$1->type);
		}
    }
    | Exp STAR Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
		if(strcmp($1->type,$3->type))		//和加法相同
		{
			myerror("","Type mismatched for operands",7);
			$$->type[0] = '\0';
		}
		else
		{
			strcpy($$->type,$1->type);
		}
    }
    | Exp DIV Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
		if(strcmp($1->type,$3->type))		//和加法相同
		{	
			myerror("","Type mismatched for operands",7);
			$$->type[0] = '\0';
		}
		else
		{
			strcpy($$->type,$1->type);
		}
    }
    | LP Exp RP{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
		strcpy($$->type,$2->type);
    }
    | MINUS Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        myTree = $$;
		strcpy($$->type,$2->type);
    }
    | NOT Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        myTree = $$;
		strcpy($$->type,$2->type);
    }
    | ID LP Args RP//函数调用{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        $3->sibling = $4;
        myTree = $$;
		struct Function *p = find_func($1);		//函数表里查找该函数
			char msg[128],*tag = NULL;
			if(find_var($1)) {
				strcpy(msg,"\"");
				strcat(msg,$1->content);
				strcat(msg,"\" is not a function");
				myerror("",msg,11);		//如果在变量符号表里找到了这个函数的名字，说明这不是一个函数
			}
			else if (p && p->valist_num == 0) 
			{
				strcpy(msg,"function \"");
				strcat(msg,p->funname);
				strcat(msg,"(");
				strcat(msg,")\" failed to match parameters");
				tag = find_args($3);
				myerror(tag,msg,9);
			}
			else
			{
				if(!p) 
				{
					char tag1[128];
					strcpy(tag1," \"");
					strcat(tag1,$1->content);
					strcat(tag1,"\"");
					myerror(tag1,"Undefined function ",2);	//如果没找到这个函数，说明没有定义
				}
				else if (p && strcmp(p->valist_type,"void"))	//如果找到了，但是没有形参 
				{
					strcpy(msg,"Function \"");
					strcat(msg,p->funname);
					strcat(msg,"(");
					strcat(msg,p->valist_type);
					strcat(msg,")\" is not applicable for arguments");
					tag = find_args($3);
					if(strcmp(tag,p->valist_type)) myerror(tag,msg,9);
				}
				if(p) strcpy($$->type,p->return_type);		//找到了就将函数返回值类型赋给父结点
			}
    }
    | ID LP RP//没有形参的函数调用{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
		struct Function *p = find_func($1);		//函数表里查找函数
			char msg[128];char* tag = NULL;
			if(find_var($1)) {
				strcpy(msg,"\"");
				strcat(msg,$1->content);
				strcat(msg,"\" is not a function");
				myerror("",msg,11);		//如果在变量符号表里找到了这个函数的名字，说明这不是一个函数
			}
			else if (p && p->valist_num != 0) 
			{
				strcpy(msg,"function \"");
				strcat(msg,p->funname);
				strcat(msg,"(");
				strcat(msg,")\" failed to match parameters");
				tag = find_args($3);
				myerror(tag,msg,9);
			}
			else			//同上
			{
				if(!p) 
				{
					char tag1[128];
					strcpy(tag1," \"");
					strcat(tag1,$1->content);
					strcat(tag1,"\"");
					myerror(tag1,"Undefined function ",2);
				}
				
				else if (p && strcmp(p->valist_type,"void")) 
				{
					strcpy(msg,"Function \"");
					strcat(msg,p->funname);
					strcat(msg,"(");
					strcat(msg,p->valist_type);
					strcat(msg,")\" is not applicable for arguments");
					myerror("\"(void)\"",msg,9);
				}
			}
    }
    | Exp LB Exp RB{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        $3->sibling = $4;
        myTree = $$;
		char msg[128];
			if(find_var($1)->dimension == 0) {
				strcpy(msg,"\"");
				strcat(msg,$1->content);
				strcat(msg,"\" is not an array");
				myerror("",msg,10);		//变量表里该变量的维度为0，表明不是数组
			}
			if(!strcmp($3->type,"float"))
			{
				strcpy(msg,"\"");
				strcat(msg,$3->content);
				strcat(msg,"\" is not an integer");
				myerror("",msg,12);		//方括号中有浮点数
			}
			else strcpy($$->type,var_type($1));		//拷贝类型
    }
    | Exp DOT ID{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
		int exist = Find_Field_Var(find_var($1),find_var($3));		//在结构体中存在定义的变量
			if(exist == -1) 
			{
				char tag[128];
				strcpy(tag," \"");
				strcat(tag,$2->content);
				strcat(tag,"\"");
				myerror(tag,"Illegal use of '.'",13);
			}
			else if(exist == 1) 
			{
				char tag[128];
				strcpy(tag," \"");
				strcat(tag,$3->content);
				strcat(tag,"\"");
				myerror(tag,"Non-existent field",14);
			}
    }
    | ID{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
		if(!find_var($1)) 
			{
				char tag[128];
				strcpy(tag," \"");
				strcat(tag,$1->content);
				strcat(tag,"\"");
				myerror(tag,"Undefined variable",1);		//符号表中没找到
			}
			struct Variable* p = find_var($1);
			if(p){
			strcpy($$->type,p->type);
			}
    }
    | INT{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
		strcpy($$->type,"int");
    }
    | FLOAT{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
		strcpy($$->type,"float");
    }
    | LP error RP {
        if(line_check[@2.first_line-1]==0){
        line_check[@2.first_line-1]=1;
   }
        char msg[100];
        sprintf( msg, "Exp Syntax error");
        myerror( msg );
    }
    | ID LP error RP {
        if(line_check[@2.first_line-1]==0){
        line_check[@2.first_line-1]=1;
   }
        char msg[100];
        sprintf( msg, "Exp Syntax error");
        myerror( msg );
    }
    | Exp LB error RB {
        if(line_check[@2.first_line-1]==0){
        line_check[@2.first_line-1]=1;
   }
        char msg[100];
        sprintf( msg, "Exp Missing \"]\"");
        myerror( msg );
    }
    | Exp ASSIGNOP error{
       if(line_check[@2.first_line-1]==0){
        line_check[@2.first_line-1]=1;
   }
        char msg[100];
        sprintf( msg, "Exp syntax error");
        myerror( msg );
    }
    ;


Args : Exp COMMA Args{
        $$ = upConstruct($1, "Args", @1.first_line, NONTERMINAL);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, NONTERMINAL);
    }
    ;

%%

#include "lex.yy.c"

int main(int argc, char** argv)
{
	if(argc <= 1) return 1;
	FILE* f = fopen(argv[1], "r");
	if(!f){
		perror(argv[1]);
		return 1;
	}
	varihead = (struct Variable*)malloc(sizeof(struct Variable));
	varihead->next = NULL;
	varitail = varihead;
	funchead = (struct Function*)malloc(sizeof(struct Function));
	funchead->next = NULL;
	functail = funchead;
	structhead = (struct Structure*)malloc(sizeof(struct Structure));
	structhead->Next = NULL;
	structtail = structhead;
    /*yylineno=1??*/
	yyrestart(f);
	yyparse();
    
    if(error_count == 0)
        preOrderTraverse(myTree, 0);

	fclose(f);  
	return 0;
}

void yyerror(char *msg){
    //
}

void myerror(char *msg){

    fprintf(stderr, "Error type B at Line %d: %s \n", yylineno,  msg);
    error_count++;
}