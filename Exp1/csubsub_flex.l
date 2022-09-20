%option yylineno
%{
    int charLoc = 0;
    //记录现在读取到第几个字符，输出token要用,注意换行归零。
    //先暂时使用这个变量，这里面还有问题，所以肯定还是要改的
    //记录行数的就是yylineno
%}


//第一部分，正则表达式的部分
name regex
%%
//第二部分，识别部分
";" {/*A*/printf("SEMI at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"," {/*A*/printf("COMMA at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"=" {/*A*/printf("ASSIGNOP at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
">|<|>=|<=|==|!=" {/*A*/printf("RELOP at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"+" {/*A*/printf("PLUS at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"-" {/*A*/printf("MINUS at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"*" {/*A*/printf("STAR at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"/" {/*A*/printf("DIV at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"&&" {/*A*/printf("AND at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"||" {/*A*/printf("OR at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"." {/*A*/printf("DOT at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"!" {/*A*/printf("NOT at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"int|float" {/*A*/printf("TYPE at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"(" {/*A*/printf("LP at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
")" {/*A*/printf("RP at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"[" {/*A*/printf("LB at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"]" {/*A*/printf("RB at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"{" {/*A*/printf("LC at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"}" {/*A*/printf("RC at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"struct" {/*A*/printf("STRUCT at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"return" {/*A*/printf("RETURN at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"if" {/*A*/printf("IF at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"else" {/*A*/printf("ELSE at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}
"while" {/*A*/printf("WHILE at line %d,char %D: %s.\n",yylineno,charLoc,yytext);/*B*/charLoc += yyleng;/*C*/}


%%
// 第三部分 代码部分

//————————————————————————分割线
// 第一阶段任务： 
// 包睿负责写27个token中除了INT，FLOAT和ID之外的部分，不要写到regex里面，直接写到pattern部分,把第三部分的读取程序程序也写好
// 邵子轩研究一下INT,FLOAT和ID相关regex,以及未定义标识符的处理
// 丁春申把注释的识别和附加要求做了
// 然后开始第一次合代码debug，咱们要没时间了！！！
//————————————————————————分割线
//会议纪要：每个人的任务，时间安排，关于charLoc的注意事项（留下注释替换位置），
//关于忽略空白字符的问题（先忽略着，把基本东西拼出来），写作注意排序（先ID,后FLOAT）