#ifndef TREE_H
#define TREE_H

#include <string.h>
#define Node
typedef int NODE_TYPE;        // 结点类型
// 非终结符类型
#define NONTERMINAL 0         
// 终结符类型
#define INT_TYPE 1            // int 类型
#define FLOAT_TYPE 2          // float 类型
#define STRING_TYPE 3         // 可打印类型

struct Node {
    struct Node *child;       // 子结点
    struct Node *sib;     // 兄弟节点
    int lineno;              // 行号
    char *name;               // 结点名字
    NODE_TYPE type;           // 结点类型
    union {
        char *id_name;        // ID 名字
        int intValue;         // int 值
        float floatValue;     // float 值
    };
};

struct Node *head;              // 语法分析树的根结点
// 函数的声明们
struct Node *createNode(char *name, int line, NODE_TYPE type);
struct Node *insertNode(struct Node *node, char *name, int line, NODE_TYPE type);
void printNode(struct Node *node);
void printTree(struct Node* head, int depth);
#endif