#define size 10
#include<stdio.h>
#include<string.h>

typedef struct stack
{
    char str1[size];
    char str2[size];
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

void push(char c)
{
    if(! isFull()){
        stk.top++;
        stk.str1[stk.top] = c;
    }
    else{
        printf("Stack is full");
    }
    peep();
}

void peep()
{
    if(!isEmpty()){
        stk.str2[stk.top] =  stk.str1[stk.top];
    }
    else{
        printf("stack is empty\n");
    }
}

int main()
{
    stk.top = -1;
    char s[] = "lool";

    for(int i =0;i<strlen(s);i++){
        push(s[i]);
    }

    if(stk.str2 == stk.str1){
        printf("String is Palindrome");
    }
    else{
        printf("Not Palindrome");
    }

}
