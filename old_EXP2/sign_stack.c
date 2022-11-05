#include<stdio.h>
#define S_LP 1
#define S_LB 2
#define S_LC 3
#define S_START1 4
#define S_START2 5
#define S_SEMI 6
#define S_RC 7
#define S_RB 8
#define S_RP 9
#define S_COTENT int
#define S_ERROR '#'

typedef struct sign_stack
{
    int top;
    S_COTENT stack[256];
    int Waiting_RC_Flag;
}sign_stack;

int push(S_COTENT input, sign_stack* mystack){
    // printf("STACK: %d recieved\nNow the top is %d, stack is: \t", input, mystack -> top);
    // for(int i = 0; i < (mystack -> top); i++){
        // printf("%d\t", mystack -> stack[i]);
    // }
    // printf("\n");
    if((mystack -> top) == 0){
        mystack -> stack[(mystack -> top)++] = input;
        // if(mystack -> stack[(mystack -> top) - 1] == 5){
        //     mystack -> Waiting_RC_Flag = 1; 
        // }
        return 0;
    }

    int is_start = (mystack -> stack[(mystack -> top) - 1] == S_START1 ||\
    mystack -> stack[(mystack -> top) - 1] == S_START2);

    int temp = 0;
    int cnt = 0;

    switch (input)
    {
        case S_START1 :
        case S_START2 :
            mystack -> stack[(mystack -> top)++] = input;
            break;

        case S_LC :
            // printf("NOW is LC in\n");
            cnt = 0;
            do{
                cnt++;
                temp = mystack -> stack[(mystack -> top) - cnt];
                // printf("in the loop they all: %d, %d, %d.\n", cnt , temp, (mystack -> top));
            }while(temp == S_START1 && cnt <= (mystack -> top));
            if(temp == S_START2){
                // printf("in the start 2 process they all: %d, %d, %d.\n", cnt , temp, (mystack -> top));
                (mystack -> top) = (mystack -> top) - cnt;
            }
            mystack -> stack[(mystack -> top)++] = input;
            // printf("in the end they all: %d, %d, %d.\n", cnt , temp, (mystack -> top));

            break;

        case S_LB :
        case S_LP :
            mystack -> stack[(mystack -> top)++] = input;
            break;
        case S_SEMI:
            cnt = 1;
            do{
                temp = mystack -> stack[(mystack -> top) - cnt];
                cnt++;
            }while(temp == S_START1);
            if(temp != S_START2){
                cnt--;
            }
            (mystack -> top) = (mystack -> top) - cnt + 1;
            // mystack -> stack[(mystack -> top)++] = input;
            
            
            // if(mystack -> stack[(mystack -> top) - 1] + input == 10 || \
            // mystack -> stack[(mystack -> top) - 1] + input == 11 ){
            //     (mystack -> top)--;
            // }else{
            //     printf("unexpected fault in stack! Located in S_SEMI\n");
            //     return 0;
            // }
            break; 
        case S_RP :
        case S_RB :
            cnt = 1;
            do{
                temp = mystack -> stack[(mystack -> top) - cnt];
                cnt++;
            }while(temp == S_START1 || temp == S_START2);
            if(temp + input == 10){
                (mystack -> top) = (mystack -> top) - cnt + 1;
            }

            break;
        case S_RC :
            if(mystack -> stack[(mystack -> top) - 1] + input == 10){
                (mystack -> top)--;
            }else{
                mystack -> stack[(mystack -> top)++] = input;
                // printf("fault in stack! Located in S_RC\n");
                return 0;
            }
            break;

        default:
            printf("unexpected fault in stack!Unknow input\n");
            return 0;
            break;
    }
    // printf("push success\n");
    // printf("Now the top is %d, stack is: \t", mystack -> top);
    // for(int i = 0; i < (mystack -> top); i++){
        // printf("%d\t", mystack -> stack[i]);
    // }
    // printf("\n");
    return 0;
}

char MAC_to_char(S_COTENT input){
    switch (input)
    {
        case S_SEMI :
            return ';';

        case S_RC :
            return '}';
        case S_RP :
            return ')';
            
        case S_RB :
            return ']';
            
 
        default:
            return '#';
    }
}


char s_pop(sign_stack* mystack){
    S_COTENT temp;
    int stack_search = mystack -> top;
    // printf("begin to find missing character\n");
    do{
        temp = mystack -> stack[--stack_search]; 
    }while(stack_search > 0 &&(temp == S_START1 || temp == S_START2));

    if(stack_search == 0){
        return ';';
    }

    switch (temp)
    {
        case S_LB :
            temp = S_RB;
            break;
        case S_LP :
            temp = S_RP;
            break;
        default:
            S_COTENT stacktop = mystack -> stack[mystack -> top - 1];
            (mystack -> top)--;
            temp = S_SEMI;
            push(temp, mystack);
            push(stacktop, mystack);
            return ';';
            break;
    }

    push(temp, mystack);
    return MAC_to_char(temp);

}