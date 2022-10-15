#include <malloc.h>
#include <stdio.h>
#include "syntax_tree.h"

struct Node *createNode(char *name, int line, NODE_TYPE type) {
    struct Node *pNode = (struct Node *) malloc(sizeof(struct Node));
    pNode->sib = NULL;         // 新结点的兄弟为空
    pNode->child = NULL;           // 新结点的子女为空
    pNode->lineNum = line;         // 记录行号，之后输出有�?
    pNode->type = type;            // 记录结点类型，根据结点类型来输出
    pNode->name = strdup(name);    // 使用字符串拷贝赋予新结点的结点名
    pNode->intValue = 1;           // �? int 值默认设�? 1
    return pNode;                  // 返回 pNode
}

struct Node *insertNode(struct Node *node, char *name, int line, NODE_TYPE type) {
    struct Node *father = (struct Node *) malloc(sizeof(struct Node));
    father->child = node;           // 给输入结点一个爹
    father->sib = NULL;         // 父亲结点的兄弟为�?
    father->lineNum = line;         // 记录行号，之后输出有�?
    father->type = type;            // 记录结点类型，根据结点类型来输出
    father->name = strdup(name);    // 使用字符串拷贝赋予新结点的结点名
    father->intValue = 1;           // �? int 值默认设�? 1
    head = father;                  // �? head 置为 father
    return father;                  // 返回 father
}


void printNode(struct Node *node) {
    if (node->type == STRING_TYPE)
        printf("%s : %s\n", node->name, node->id_name);     // string 类型的结点输出结点名和结点内�?
    else if (node->type == INT_TYPE)
        printf("INT : %d\n", node->intValue);               // int 类型的结点输�? INT 和结点�?
    else if (node->type == FLOAT_TYPE)
        printf("FLOAT : %f\n", node->floatValue);           // float 类型的结点输�? FLOAT 和结点�?
    else
        printf("%s (%d)\n", node->name, node->lineNum);     // 非终结符输出结点名字和行�?
}

void printTree(struct Node *head, int depth) {
    if (head == NULL) return;                       // 遇到空结点，函数结束
    for (int i = 0; i < depth; ++i)
        printf("\t");                         // 打印语法树所需的空白（制表符）
    printNode(head);
    printTree(head->child, depth + 1);       // 考虑该结点的孩子，深度加一，进入下一层递归
    printTree((head->sib), depth);       // 考虑该结点的兄弟，深度不变，进入下一层递归
}
