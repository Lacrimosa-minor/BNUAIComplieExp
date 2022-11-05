# include <string.h>
# include <malloc.h>
# include <stdio.h>
//# include "tree.h"
enum node_type
{
    // NONTERMINAL
    N_PROGRAM,
    N_EXT_DEF_L,
    N_EXT_DEF,
    N_FUN_DEC,
    
    //TERMINAL
    NONTERMINAL,
    N_INT,
    N_FLOAT,
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
};

typedef struct node{
    char* character;  
    int line_no;  //行号
    struct node* child;
    struct node* sibling;
    // int nodeType;
    enum node_type type;
    union {
        int intVal;
        float floatVal;
        char* IDVal;
    }subtype;
}*treeNode;

typedef treeNode Tree;
Tree myTree;

void nodeInit(treeNode node, char* character, int line_no,treeNode child, treeNode sibling, enum node_type in_type){
    //strncpy(node->character, character, 500);

    node->character = strdup(character);
    node->child = child;
    node->sibling = sibling;
    node->line_no = line_no;
    node->type = in_type;
    return;
}

treeNode upConstruct(treeNode node, char* character, int line_no, enum node_type in_type){
    treeNode parent = (treeNode) malloc(sizeof(struct node));
    nodeInit(parent, character, line_no, node, NULL, in_type);
    //myTree = parent;
    return parent;
}

// void upConstruct(treeNode node, treeNode parent){
//     parent->child = node;
//     return;
// }

//打印不同类型的结点内容
void printNode(treeNode node){
    if(node->type == N_INT)
        printf("INT: %d\n", node->subtype.intVal);
    else if(node->type == N_FLOAT)
        printf("FLOAT: %f\n", node->subtype.floatVal);
    else if(node->type == N_ID)
        printf("%s: %s\n", node->character, node->subtype.IDVal);
    else
        printf("%s (%d)\n", node->character, node->line_no);
    return;
}

//树的先根次序遍历
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
}

