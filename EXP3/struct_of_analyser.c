#include <stdio.h>
#include "SymbolTable.c"

//这里给了一个node_type定义，其实树的头里面已经给过了
//这里只是为了方便编译不报错，最后应该当删除
typedef enum node_type
{
    // NONTERMINAL
    N_PROGRAM,
    N_EXT_DEF_L,
    N_EXT_DEF,
    N_EXT_DEC_L,
    N_FUN_DEC,
    N_SPECI,
    N_STRUCT_SPECI,
    N_OPT_TAG,
    N_TAG,
    N_VAR_DEC,
    N_VAR_L,
    N_EXP,
    N_STMT,
    N_PARAM_DEC,
    N_COMPST,
    N_STMT_L,
    N_DEF_L,
    N_DEF,
    N_DEC,
    N_DEC_L,
    N_ARGS,

    //TERMINAL
    N_INT ,
    N_FLOAT = 100,
    N_ID,
    N_TYPE,
    N_LF,
    N_SEMI,
    N_COMMA,
    N_DOT,
    N_ASSIGNOP,
    N_RELOP,
    N_PLUS,
    N_MINUS,
    N_STAR,
    N_DIV,
    N_AND,
    N_OR,
    N_NOT,
    N_LP,
    N_RP,
    N_LB,
    N_RB,
    N_LC,
    N_RC,
    N_STRUCT,
    N_RETURN,
    N_IF,
    N_ELSE,
    N_WHILE
} node_type;

typedef struct node
{
    char *character;
    int line_no; //行号
    struct node *child;
    struct node *sibling;
    node_type nodeType;
    // int flag;//遍历标记
    union
    {
        int intVal;
        float floatVal;
        char *IDVal;
    } subtype;
} treeNode;

typedef treeNode Tree;

// //表明继续执行深度优先遍历
// //最终形态可能并非这样一个函数，这里有待商讨
// treeNode *deep_search();

// //从def_node所有子节点中收集完整的变量信息，再交给作用域管理部分处理
// var_dec node_to_info(treeNode *def_node);

// //和上面那个函数类似，就是收集函数定义然后返回
// fun_dec node_to_fun(treeNode *def_node);

// //类似，返回一个结构体定义的信息
// struct_dec node_to_struct(treeNode *def_node);

// //...其实应该有很多很多种节点需要处理，这里列举的是最重要的判定函数，变量，结构体定义的部分，总之就是，一大堆函数咯

// //开辟新的作用域，扫描到左大括号调用
// int new_block();

// //创建变量，函数和结构体定义，正常返回0，不正常就返回错误编号
// int creat_var(var_dec info);
// int creat_fun(fun_dec info);
// int creat_struct(struct_dec info);

// //查询此处用到的变量是否合法，根据程序获取的信息查询，正常就返回0，不正常就返回错误编号
// int query_var_legal(var_dec myvar);
// int query_fun_legal(fun_dec myfun);
// int query_struct_legal(struct_dec mystruct);

// //关闭当前作用域，退到上一层作用域
// int close_block();

int tree_analys(treeNode *mytree)
{
    treeNode* temp;
    seqStack myStack;
    initStack(&myStack);
    push(&myStack, mytree)
    
    
    //不停的深度遍历树，一个一个节点的处理
    do
    {
        //根据收到的不同符号调用不同的处理函数
        switch (tempNode->nodeType)
        {
        case N_EXT_DEF_L:
            //...
            break;
        // 还有许多其他的，省略了...
        default:
            break;
        }
        //节点处理完了，下一个
        tempNode = deep_search();
    } while (tempNode != NULL);

    //后续的程序等等...先不写了，我也不清楚
}




int ext_def(var_dec *out0, fun_dec *out1, struct_dec *out2)
{
    treeNode sub_tree_root;
    treeNode child = sub_tree_root->child->sibling;
    switch (child->type)
    {
    case N_EXT_DEF_L:
        out0 = global_var(sub_tree_root);
        return 0;
        break;

    case N_SEMI:
        out1 = global_fun(sub_tree_root);
        return 1;
        break;

    case N_FUN_DEC:
        out2 = global_struct(sub_tree_root);
        return 2;
    default:
        printf("ERROR: wrong syntax tree\n");
        break;
    }
}


int specifiers(){

}
