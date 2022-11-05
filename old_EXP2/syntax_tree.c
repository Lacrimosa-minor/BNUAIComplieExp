#include <malloc.h>
#include <stdio.h>
#include "syntax_tree.h"

struct Node *createNode(char *name, int line, NODE_TYPE type) {
    struct Node *pNode = (struct Node *) malloc(sizeof(struct Node));
    pNode->brother = NULL;         // 鏂扮粨鐐圭殑鍏勫紵涓虹┖
    pNode->child = NULL;           // 鏂扮粨鐐圭殑瀛愬コ涓虹┖
    pNode->lineNum = line;         // 璁板綍琛屽彿锛屼箣鍚庤緭鍑烘湁鐢?
    pNode->type = type;            // 璁板綍缁撶偣绫诲瀷锛屾牴鎹粨鐐圭被鍨嬫潵杈撳嚭
    pNode->name = strdup(name);    // 浣跨敤瀛楃涓叉嫹璐濊祴浜堟柊缁撶偣鐨勭粨鐐瑰悕
    pNode->intValue = 1;           // 灏? int 鍊奸粯璁よ涓? 1
    return pNode;                  // 杩斿洖 pNode
}

struct Node *insertNode(struct Node *node, char *name, int line, NODE_TYPE type) {
    struct Node *father = (struct Node *) malloc(sizeof(struct Node));
    father->child = node;           // 缁欒緭鍏ョ粨鐐逛竴涓埞
    father->brother = NULL;         // 鐖朵翰缁撶偣鐨勫厔寮熶负绌?
    father->lineNum = line;         // 璁板綍琛屽彿锛屼箣鍚庤緭鍑烘湁鐢?
    father->type = type;            // 璁板綍缁撶偣绫诲瀷锛屾牴鎹粨鐐圭被鍨嬫潵杈撳嚭
    father->name = strdup(name);    // 浣跨敤瀛楃涓叉嫹璐濊祴浜堟柊缁撶偣鐨勭粨鐐瑰悕
    father->intValue = 1;           // 灏? int 鍊奸粯璁よ涓? 1
    head = father;                  // 灏? head 缃负 father
    return father;                  // 杩斿洖 father
}


void printNode(struct Node *node) {
    if (node->type == STRING_TYPE)
        printf("%s : %s\n", node->name, node->id_name);     // string 绫诲瀷鐨勭粨鐐硅緭鍑虹粨鐐瑰悕鍜岀粨鐐瑰唴瀹?
    else if (node->type == INT_TYPE)
        printf("INT : %d\n", node->intValue);               // int 绫诲瀷鐨勭粨鐐硅緭鍑? INT 鍜岀粨鐐瑰€?
    else if (node->type == FLOAT_TYPE)
        printf("FLOAT : %f\n", node->floatValue);           // float 绫诲瀷鐨勭粨鐐硅緭鍑? FLOAT 鍜岀粨鐐瑰€?
    else
        printf("%s (%d)\n", node->name, node->lineNum);     // 闈炵粓缁撶杈撳嚭缁撶偣鍚嶅瓧鍜岃鍙?
}

void printTree(struct Node *head, int depth) {
    if (head == NULL) return;                       // 閬囧埌绌虹粨鐐癸紝鍑芥暟缁撴潫
    for (int i = 0; i < depth; ++i)
        printf("\t");                         // 鎵撳嵃璇硶鏍戞墍闇€鐨勭┖鐧斤紙鍒惰〃绗︼級
    printNode(head);
    printTree(head->child, depth + 1);       // 鑰冭檻璇ョ粨鐐圭殑瀛╁瓙锛屾繁搴﹀姞涓€锛岃繘鍏ヤ笅涓€灞傞€掑綊
    printTree((head->brother), depth);       // 鑰冭檻璇ョ粨鐐圭殑鍏勫紵锛屾繁搴︿笉鍙橈紝杩涘叆涓嬩竴灞傞€掑綊
}
