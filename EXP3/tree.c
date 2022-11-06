#include <string.h>
#include <malloc.h>
#include <stdio.h>
//# include "tree.h"
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


void nodeInit(treeNode *node, char *character, int line_no, treeNode *child, treeNode *sibling, node_type mytype)
{
    // strncpy(node->character, character, 500);

    node->character = strdup(character);
    node->child = child;
    node->sibling = sibling;
    node->line_no = line_no;
    node->nodeType = mytype;
    return;
}

treeNode *upConstruct(treeNode *node, char *character, int line_no, node_type mytype)
{
    treeNode *parent = (treeNode*)malloc(sizeof(treeNode));
    nodeInit(parent, character, line_no, node, NULL, mytype);
    // myTree = parent;
    return parent;
}

// void upConstruct(treeNode node, treeNode parent){
//     parent->child = node;
//     return;
// }

//打印不同类型的结点内容
void printNode(treeNode *node)
{
    if (node->nodeType == N_INT)
        printf("INT: %d\n", node->subtype.intVal);
    else if (node->nodeType == N_FLOAT)
        printf("FLOAT: %f\n", node->subtype.floatVal);
    
    
    else if ((int)node->nodeType > 100)
        printf("%s: %s\n", node->character, node->subtype.IDVal);
    
    
    else
        printf("%s (%d)\n", node->character, node->line_no);
    return;
}

//树的先根次序遍历
/*
void preOrderTraverse(Tree t, int depth){
    if(t == NULL)
        return;
    treeNode current = t;
    for(int i = 0;i < depth; i++)
        printf("\t");
    printNode(current);
    current = current->child;
    preOrderTraverse(current, ++depth);
    while(current != NULL){
        preOrderTraverse(current->sibling, depth);
        current = current->sibling;
    }
    return;
}*/

/***************************************
 *           以下为实验三新增           *
 *************************************/
/*栈实现树的遍历：
根节点入栈，每次从栈顶取出一个节点 u，把 u 的所有子节点逆序推入栈*/

// https://blog.csdn.net/qq_40663787/article/details/83342603?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166748364716782412563744%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166748364716782412563744&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-2-83342603-null-null.142^v62^pc_search_tree,201^v3^control_2,213^v1^t3_control1&utm_term=c%E8%AF%AD%E8%A8%80n%E5%8F%89%E6%A0%91%E9%81%8D%E5%8E%86&spm=1018.2226.3001.4187
typedef struct stack //栈结构
{
    treeNode *tree[1000];
    int top;
} seqStack;

void push(seqStack *s, treeNode *t) // push
{
    s->tree[s->top] = t;
    s->top += 1;
    // t->flag = 0;不需要了
}

void rev_push(seqStack *s, treeNode *t)
{ //反方向入栈
    s->tree[s->top - 1] = t;
    s->top -= 1;
    // t->flag = 0;
}

treeNode* pop(seqStack *s) // pop
{
    treeNode* t;
    if (s->top != 0)
    {
        s->top--;
        treeNode* t = s->tree[s->top];
        return t;
    }
    else
        printf("ERROR: pop when stack NULL");
    return;
}

treeNode *top(seqStack *s) //查看栈顶
{
    return s->tree[s->top - 1];
}

void initStack(seqStack *s) //初始化栈
{
    s->top = 0;
}

int isEmpty(seqStack *s) //检查是否栈空
{
    if (s->top == 0)
        return 1;
    else
        return 0;
}

int count_child(treeNode *t)
{ //计算t的儿子数量
    treeNode *p = t->child;
    int count_child = 1;
    while (!p->sibling)
    {
        p = p->sibling;
        count_child += 1;
    }
    return count_child;
}

void reversed_insert(seqStack *s, treeNode *t)
{ //使节点t的孩子调转顺序入栈
    int count = count_child(t);
    s->top += count;
    treeNode *p = t->child;
    rev_push(s, p);
    while (!p->sibling)
    {
        p = p->sibling;
        rev_push(s, p);
    }
    s->top += count; //重新指向栈顶
}

void Pre_order(treeNode *t) //用栈实现遍历tree
{
    seqStack *s;
    initStack(&s);

    push(s, t); //根节点入栈

    while (!isEmpty(s))
    {
        treeNode* n; 
        n = pop(s); //节点出栈

        //处理该节点
        if (!n->child)
        {
            reversed_insert(s, n); // n的孩子逆序入栈
        }
    }
}
