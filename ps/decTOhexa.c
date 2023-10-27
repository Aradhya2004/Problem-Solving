#define size 10
#include<stdio.h>
typedef struct stack
{
    int data[size];
    int top;
}stack;

 stack stk;

int isEmpty(){
    return stk.top == -1;
}

int isFull()
{
    return stk.top == size-1;
}

void push(int n)
{
    if(! isFull()){
        stk.top++;
        stk.data[stk.top] = n;
    }
    else{
        printf("Stack is full");
    }
}

int pop(){
    if(! isEmpty()){
        int item;
        item = stk.data[stk.top];
        stk.top--;
        return item;
    }
    else{
        printf("Stack is empty");
        return 0;
    }
}

int main()
{
    stk.top = -1;
    int n;
    char digits[] = "0123456789ABCDEF";
    printf("Enter any number");
    scanf("%d",&n);

    while(n>0){
        int r = n%16;
        push(r);
        n = n/16;
    }
    while(!isEmpty()){
       printf("%c ",digits[pop()]);
    }
}