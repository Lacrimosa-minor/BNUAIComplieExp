%option yylineno

%{
    int charLoc = 1;
    //记录现在读取到第几个字符，输出token要用,注意换行归零。
    //先暂时使用这个变量，这里面还有问题，所以肯定还是要改的
    //记录行数的就是yylineno
%}

SINGLECOMMENT \/\/.*
MULTICOMMENT \/\*(.*?\n)*?.*?\*\/
OCTINT 0[1-7][0-7]*
HEXINT 0x(?i)[0-9|a-f]*
EFLOAT [1-9].[0-9]*E[+,-][1-9][0-9]*

%%
{pattern} {/*A*/printf("test");/*B*/charLoc += yyleng;/*C*/}

{SINGLECOMMENT} {/*A*/printf("COMMENT at line %d, char %D: %s.\n", yylineno, charLoc, yytext);/*B*/charLoc += yyleng;/*C*/}
{MULTICOMMENT} {/*A*/printf("COMMENT at line %d, char %D: %s.\n", yylineno, charLoc, yytext);/*B*/charLoc += yyleng;/*C*/}
{OCTINT} {/*A*/printf("OCTINT at line %d, char %D: %s.\n", yylineno, charLoc, yytext);/*B*/charLoc += yyleng;/*C*/}
{HEXINT} {/*A*/printf("HEXINT at line %d, char %D: %s.\n", yylineno, charLoc, yytext);/*B*/charLoc += yyleng;/*C*/}
{EFLOAT} {/*A*/printf("EFLOAT at line %d, char %D: %s.\n", yylineno, charLoc, yytext);/*B*/charLoc += yyleng;/*C*/}

"\n" {charLoc = 1;}
"\s+" {charLoc += yyleng;}

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