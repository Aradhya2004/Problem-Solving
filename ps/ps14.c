#define size 10
#include<stdio.h>
#include<string.h>

typedef struct stack
{
    char str[size];
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
        stk.str[stk.top] = c;
    }
    else{
        printf("Stack is full");
    }
}
char pop(){
    if(! isEmpty()){
        char item;
        item = stk.str[stk.top];
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
    char s[size];
    char rev[size];
    gets(s);

    int i = 0;
    while(s[i] != '\0'){
        push(s[i]);
        i++;
    }
    i = 0;
    while(!isEmpty){
        rev[i] = pop();
        i++;
    }
rev[i] = '\0';
puts(rev);

}
