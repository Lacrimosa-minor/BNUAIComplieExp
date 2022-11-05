enum var_type{
    V_INT,
    V_FLOAT,
    V_ARRAY

};

typedef struct node
{
    char *character;
    int line_no; //行号
    struct node *child;
    struct node *sibling;
    enum node_type type;
    union
    {
        int intVal;
        float floatVal;
        char *IDVal;
    } subtype;
} * treeNode;

typedef treeNode Tree;

//两个系统之间传递变量信息用
//并不是每一个值在每一个函数中都有用
struct var_dec
{
    //用枚举类表明变量的种类
    enum var_type type;
    
    //变量名字
    char* name;
    
    //变量出现的位置
    int line;
    
    //如果是个表的话，这里记录表的长度
    int len;
    
    //多维数组用这个指向下一个，如果值为NULL表明到头了
    var_dec* next_dimention;
};
typedef struct var_dec var_dec;


//两个系统之间传递函数信息用
typedef struct fun_dec
{
    //函数头声明的返回值
    enum var_type return_type;

    //函数名
    char* name;
    
    //函数声明所在行
    int line;

    //函数参数链表，最后一个为空值
    var_dec* next_para;

} fun_dec;

//两个系统之间传递结构体信息用
typedef struct struct_dec
{
    //结构体名字
    char* name;

    //定义出现的行数
    int line;

    //结构体内容物链表
    var_dec* next_para;

} struct_dec;