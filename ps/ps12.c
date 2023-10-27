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
    }
}

int peep()
{
    if(!isEmpty()){
        return stk.data[stk.top];
    }
    else{
        printf("stack is empty\n");
    return -1;
    }
}

void show()
{
    if(! isEmpty()){
        for(int i=stk.top;i>=0;i--)
        {
            printf("%d\n",stk.data[i]);
        }
    }
    else{
        printf("Stack is Empty");
    }
}


int main()
{
    stk.top = -1;
    int ch;
    int n,x;

    do{
        printf("\n1.....push");
        printf("\n2.....pop");
        printf("\n3.....peep");
        printf("\n4.....show\n");
        printf("5.....Exit\n");

        printf("Enter Choice :");
        scanf("%d",&ch); 

        switch (ch)
        {
        case 1: printf("Enter data : ");
                scanf("%d",&n);
                push(n);
            break;
        
        case 2: pop();
            break;
        case 3 : x = peep();
                printf("%d",x);
            break;
        case 4: show();
            break;
        case 5: break;
        default: printf("Invalid Syntax");
        }
    }
    while(ch!=5);
}