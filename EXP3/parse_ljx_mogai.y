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
    $$ = upConstruct($1, "Program", @1.first_line, N_PROGRAM);
    myTree = $$;
};

ExtDefList : %empty{
        //修改$$ = insertNode(NULL, "ExtDefList", yylineno, NONTERMINAL);
        $$ = upConstruct(NULL, "ExtDefList", yylineno, N_EXT_DEF_L);
        myTree = $$;
    }
    |ExtDef ExtDefList{
        $$ = upConstruct($1, "ExtDefList", @1.first_line, N_EXT_DEF_L);
        $1->sibling = $2;
        myTree = $$;
    }
    
;

ExtDef : Specifier ExtDecList SEMI{
        $$ = upConstruct($1, "ExtDef", @1.first_line, N_EXT_DEF);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | Specifier SEMI{
        $$ = upConstruct($1, "ExtDef", @1.first_line, N_EXT_DEF);
        $1->sibling = $2;
        myTree = $$;
    }
    | Specifier FunDec CompSt{
        $$ = upConstruct($1, "ExtDef", @1.first_line, N_EXT_DEF);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
;

ExtDecList : VarDec{
        $$ = upConstruct($1, "ExtDecList", @1.first_line, N_EXT_DEC_L);
        myTree = $$;
    }
    | VarDec COMMA ExtDecList{
        $$ = upConstruct($1, "ExtDecList", @1.first_line, N_EXT_DEC_L);
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
        $$ = upConstruct($1, "Specifier", @1.first_line, N_SPECI);
        myTree = $$;
    } 
    | StructSpecifier{
        $$ = upConstruct($1, "Specifier", @1.first_line, N_SPECI);
        myTree = $$;
    }
;

StructSpecifier : STRUCT OptTag LC DefList RC{
        $$ = upConstruct($1, "StructSpecifier", @1.first_line, N_STRUCT_SPECI);
        $1->sibling = $2;
        $2->sibling = $3;
        $3->sibling = $4;
        $4->sibling = $5;
        myTree = $$;
    }
    | STRUCT Tag{
        $$ = upConstruct($1, "StructSpecifier", @1.first_line, N_STRUCT_SPECI);
        $1->sibling = $2;
        myTree = $$;
    }
;

OptTag :  %empty{
        $$ = upConstruct(NULL, "OptTag", yylineno, N_OPT_TAG);
        myTree = $$;
    }
    |ID{
        $$ = upConstruct($1, "OptTag", @1.first_line, N_OPT_TAG);
        myTree = $$;
    }
    
;

Tag : ID{
        $$ = upConstruct($1, "Tag", @1.first_line, N_TAG);
        myTree = $$;
}
;

 /*Declarators*/
VarDec : ID{
        $$ = upConstruct($1, "VarDec", @1.first_line, N_VAR_DEC);
        myTree = $$;
    }
    | VarDec LB INT RB{
        $$ = upConstruct($1, "VarDec", @1.first_line, N_VAR_DEC);
        $1->sibling = $2;
        $2->sibling = $3;
        $3->sibling = $4;
        myTree = $$;
    }
;

FunDec : ID LP VarList RP{
        $$ = upConstruct($1, "FunDec", @1.first_line, N_FUN_DEC);
        $1->sibling = $2;
        $2->sibling = $3;
        $3->sibling = $4;
        myTree = $$;
    }
    | ID LP RP{
        $$ = upConstruct($1, "FunDec", @1.first_line, N_FUN_DEC);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    } 
;

VarList : ParamDec COMMA VarList{
        $$ = upConstruct($1, "VarList", @1.first_line, N_VAR_L);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | ParamDec{
        $$ = upConstruct($1, "VarList", @1.first_line, N_VAR_L);
        myTree = $$;
    }
;

ParamDec : Specifier VarDec{
        $$ = upConstruct($1, "ParamDec", @1.first_line, N_PARAM_DEC);
        $1->sibling = $2;
        myTree = $$;
    }
;

 /*Statements*/
CompSt : LC DefList StmtList RC{
        $$ = upConstruct($1, "CompSt", @1.first_line, N_COMPST);
        $1->sibling = $2;
        $2->sibling = $3;
        $3->sibling = $4;
        myTree = $$;
   }
 ;

StmtList : Stmt StmtList{
        $$ = upConstruct($1, "StmtList", @1.first_line, N_STMT_L);
        $1->sibling = $2;
        myTree = $$;
    }
    | %empty{
        $$ = upConstruct(NULL, "StmtList", yylineno, N_STMT_L);
        myTree = $$;
    }
;
    
Stmt : Exp SEMI{
        $$ = upConstruct($1, "Stmt", @1.first_line, N_STMT);
        $1->sibling = $2;
        myTree = $$;
    }    
    | CompSt{
        $$ = upConstruct($1, "Stmt", @1.first_line, N_STMT);
        myTree = $$;
    }
    | RETURN Exp SEMI{
        $$ = upConstruct($1, "Stmt", @1.first_line, N_STMT);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | IF LP Exp RP Stmt{
        $$ = upConstruct($1, "Stmt", @1.first_line, N_STMT);
        $1->sibling = $2;
        $2->sibling = $3;
        $3->sibling = $4;
        $4->sibling = $5;
        myTree = $$;
    }
    | IF LP Exp RP Stmt ELSE Stmt{
        $$ = upConstruct($1, "Stmt", @1.first_line, N_STMT);
        $1->sibling = $2;
        $2->sibling = $3;
        $3->sibling = $4;
        $4->sibling = $5;
        $5->sibling = $6;
        $6->sibling = $7;
        myTree = $$;
    }
    | WHILE LP Exp RP Stmt{
        $$ = upConstruct($1, "Stmt", @1.first_line, N_STMT);
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
DefList : Def DefList{
        $$ = upConstruct($1, "DefList", @1.first_line, N_DEF_L);
        $1->sibling = $2;
        myTree = $$;
    }
    | %empty{
        $$ = upConstruct(NULL, "DefList", yylineno, N_DEF_L);
        myTree = $$;
    }
;

Def : Specifier DecList SEMI{
        $$ = upConstruct($1, "Def", @1.first_line, N_DEF);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
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

DecList : Dec{
        $$ = upConstruct($1, "DecList", @1.first_line, N_DEC_L);
        myTree = $$;
    }
    | Dec COMMA DecList{
        $$ = upConstruct($1, "DecList", @1.first_line, N_DEC_L);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
;

Dec : VarDec{
        $$ = upConstruct($1, "Dec", @1.first_line, N_DEC);
        myTree = $$;
    }
    | VarDec ASSIGNOP Exp{
        $$ = upConstruct($1, "Dec", @1.first_line, N_DEC);
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

 /*Expressions*/
Exp : Exp ASSIGNOP Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | Exp AND Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | Exp OR Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | Exp RELOP Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | Exp PLUS Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | Exp MINUS Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | Exp STAR Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | Exp DIV Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | LP Exp RP{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | MINUS Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
        $1->sibling = $2;
        myTree = $$;
    }
    | NOT Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
        $1->sibling = $2;
        myTree = $$;
    }
    | ID LP Args RP{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
        $1->sibling = $2;
        $2->sibling = $3;
        $3->sibling = $4;
        myTree = $$;
    }
    | ID LP RP{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | Exp LB Exp RB{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
        $1->sibling = $2;
        $2->sibling = $3;
        $3->sibling = $4;
        myTree = $$;
    }
    | Exp DOT ID{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | ID{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
    }
    | INT{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
    }
    | FLOAT{
        $$ = upConstruct($1, "Exp", @1.first_line, N_EXP);
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
        $$ = upConstruct($1, "Args", @1.first_line, N_ARGS);
        $1->sibling = $2;
        $2->sibling = $3;
        myTree = $$;
    }
    | Exp{
        $$ = upConstruct($1, "Exp", @1.first_line, N_ARGS);
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
    /*yylineno=1??*/
	yyrestart(f);
	yyparse();
    
    if(error_count == 0)
        preOrderTraverse(myTree, 0);
        
	return 0;
}

void yyerror(char *msg){
    //
}

void myerror(char *msg){

    fprintf(stderr, "Error type B at Line %d: %s \n", yylineno,  msg);
    error_count++;
}