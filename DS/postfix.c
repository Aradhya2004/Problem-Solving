#include <stdio.h>

#define SIZE 100
typedef struct stack
{
    int top;
    int data[SIZE];
}stack;

stack stk;
void push(int item)
{

    if (stk.top >= SIZE - 1) {
        printf("stack over flow");
        return;
    }
    else {
        stk.top++;
        stk.data[stk.top] = item;
    }
}

int pop()
{
    int item;
    if (stk.top < 0) {
        printf("stack under flow");
    }
    else {
        item = stk.data[stk.top];
        stk.top--;
        return item;
    }
}

void EvalPostfix(char postfix[])
{

    int i;
    char ch;
    int val;
    int A, B;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];
        if (ch>='0' && ch<='9') {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

            A = pop();
            B = pop();

            switch (ch) 
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }

            /* push the value obtained above onto the stack */
            push(val);
        }
    }
    printf("\n Result of expression evaluation : %d \n", pop());
}

int main()
{
    stk.top = -1;
    char expr[100];
    printf("Enter any expression\n");
    gets(expr);

    /* call function to evaluate postfix expression */

    EvalPostfix(expr);

    return 0;
}