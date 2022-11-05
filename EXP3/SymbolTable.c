# include "tree.c"
# include <math.h>
# define TABLESIZE 128

enum Status { Active, Empty, Deleted };
enum DataType {Int, Float, Array, Struct, StructDomain}


typedef struct datanode1{
    char* varName;  //变量名
    enum DataType varType; //变量数据类型
    int numdim;     //若为数组，数组维度
    int* len_of_dims //每个维度的长度
    struct datanode1* next;
}dataNodeVar;  //变量符号表结点

dataNodeVar newNodeVar(char* name, enum DataType type, int nd){
    dataNodeVar newNode;
    sprintf(newNode.varName, name);
    newNode.varType = type;
    newNode.numdim = nd;
    if(nd > 0)  //若为数组，使用int* len_of_dims存储每个维度长度
        newNode.len_of_dims = (int*)calloc(newNode.numdim, sizeof(int));
    else        //若非数组，numdim传入0，len_of_dims为NULL
        len_of_dims = NULL;
    return newNode;
}

typedef struct datanode2{
    char* funcName;  //函数名
    enum DataType returnType; //函数返回值类型
    bool defined;   //函数是否定义
    dataNodeVar* args;   //函数形参表
}dataNodeFunc;  //函数符号表结点

dataNodeVar newNodeFunc(char* name, enum DataType type, bool de, dataNodeVar* ar){
    dataNodeFunc newNode;
    sprintf(newNode.funcName, name);
    newNode.returnType = type;
    newNode.defined = de;
    newNode.args = ar;
    return newNode;
}

typedef struct datanode3{
    char* structName;  //结构体名
    char* structTypeName;  //结构体类型名
    dataNodeVar* structDomains;  //结构体域，为一系列变量，存储为一个变量结点链表
}dataNodeStruct;  //结构体符号表结点

dataNodeVar newNodeStruct(char* name, char* tname){
    dataNodeStruct newNode;
    sprintf(newNode.structName, name);
    sprintf(newNode.structTypeName, tname);
    return newNode;
}

// typedef struct argnode{
//     enum DataType argType;
//     struct argnode* next;
// }argNode;  //函数形参表结点

typedef struct table1{
    int divitor;
 	int curSize;
    int tableSize;
    dataNodeVar* data;
    Status* sta;
}SymbolTableVar;  //变量符号表

void tableVarInit(SymbolTableVar st, int d, int sz){
    st.divitor = d;
    st.curSize = 0;
    st.tableSize = sz;
    st.data = (dataNodeVar*)calloc(sz, sizeof(dataNodeVar));
    st.sta = (Status*)calloc(sz, sizeof(Status));
    for(int i = 0; i < st.tableSize; i++)
        st.sta[i] = (Status)Empty;
    return;
}

typedef struct table2{
    int divitor;
 	int curSize;
    int tableSize;
    dataNodeFunc* data;
    Status* sta;
}SymbolTableFunc;  //函数符号表

void tableFuncInit(SymbolTableFunc st, int d, int sz){
    st.divitor = d;
    st.curSize = 0;
    st.tableSize = sz;
    st.data = (dataNodeFunc*)calloc(sz, sizeof(dataNodeFunc));
    st.sta = (Status*)calloc(sz, sizeof(Status));
    for(int i = 0; i < st.tableSize; i++)
        st.sta[i] = (Status)Empty;
    return;
}

typedef struct table3{
    int divitor;
 	int curSize;
    int tableSize;
    dataNodeStruct* data;
    Status* sta;
}SymbolTableStruct;  //结构体符号表

void tableStructInit(SymbolTableStruct st, int d, int sz){
    st.divitor = d;
    st.curSize = 0;
    st.tableSize = sz;
    st.data = (dataNodeStruct*)calloc(sz, sizeof(dataNodeStruct));
    st.sta = (Status*)calloc(sz, sizeof(Status));
    for(int i = 0; i < st.tableSize; i++)
        sta[i] = (Status)Empty;
    return;
}

int findPosVar(SymbolTableVar st, char* key){
    int i = abs(key[1] + key[2]) % st.divitor;
    int j = i;
    do {
		if (st.sta[j] == Empty || (st.sta[j] == Active && key == st.data[j].character))
			return j;
		j = (j + 1) % st.tableSize;
	} while (j != i);
    return j;
}

int findPosFunc(SymbolTableFunc st, char* key){
    int i = abs(key[1] + key[2]) % st.divitor;
    int j = i;
    do {
		if (st.sta[j] == Empty || (st.sta[j] == Active && key == st.data[j].character))
			return j;
		j = (j + 1) % st.tableSize;
	} while (j != i);
    return j;
}

int findPosStruct(SymbolTableStruct st, char* key){
    int i = abs(key[1] + key[2]) % st.divitor;
    int j = i;
    do {
		if (st.sta[j] == Empty || (st.sta[j] == Active && key == st.data[j].character))
			return j;
		j = (j + 1) % st.tableSize;
	} while (j != i);
    return j;
}

bool ifExistVar(SymbolTableVar st, char* key){
    int i = findPosVar(st, key);
    if(st.sta[i] == Active && st.data[i].character == key)
        return true;
    return false;
}

bool ifExistFunc(SymbolTableFunc st, char* key){
    int i = findPosFunc(st, key);
    if(st.sta[i] == Active && st.data[i].character == key)
        return true;
    return false;
}

bool ifExistStruct(SymbolTableStruct st, char* key){
    int i = findPosStruct(st, key);
    if(st.sta[i] == Active && st.data[i].character == key)
        return true;
    return false;
}

void InsertVar(SymbolTableVar st, dataNodeVar elem)
{
	int i = findPosVar(elem.varName);
	if (st.sta[i] != Active)
	{
		st.data[i] = elem;
		st.sta[i] = (Status)Active;
		st.curSize++;
	}
    else
        printf("Symbol table is full. Insert failed");
}

void InsertFunc(SymbolTableFunc st, dataNodeFunc elem)
{
	int i = findPosFunc(elem.funcName);
	if (st.sta[i] != Active)
	{
		st.data[i] = elem;
		st.sta[i] = (Status)Active;
		st.curSize++;
	}
    else
        printf("Symbol table is full. Insert failed");
}

void InsertStruct(SymbolTableStruct st, dataNodeStruct elem)
{
	int i = findPosStruct(elem.structName);
	if (st.sta[i] != Active)
	{
		st.data[i] = elem;
		st.sta[i] = (Status)Active;
		st.curSize++;
	}
    else
        printf("Symbol table is full. Insert failed");
}