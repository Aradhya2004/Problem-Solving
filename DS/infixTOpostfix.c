#include <stdio.h>
#include <string.h>

#define size 100

typedef struct stack
{
    char arr[size];
    int top;
} stack;

stack stk;

int isEmpty()
{
    return stk.top == -1;
}

int isFull()
{
    return stk.top == size - 1;
}

void push(char num)
{
    if (!isFull())
    {
        stk.top++;
        stk.arr[stk.top] = num;
    }
    else
    {
        printf("stack full");
    }
}

int pop()
{
    if (!isEmpty())
    {
        int item;
        item = stk.arr[stk.top];
        stk.top--;
        return item;
    }
    else
    {
        printf("empty");
    }
}

int peep()
{
    if (!isEmpty())
    {
        return stk.arr[stk.top];
    }
}
// peep(,symbol)
int precedence(char top_op, char op2)
{
    if (top_op == '^' || top_op == '*' || top_op == '/' || top_op == '%')
    {
        return op2 != '^';
    }
    else
    {
        if (op2 == '+' || op2 == '-')
        {
            return 1;
        }
        return 0;
    }
}

void postfix(char infix[])
{
    int i = 0, j = 0;
    char postfix[size];

    while (infix[i] != '\0')
    {

        char s = infix[i++];
        if (s >= 'a' && s <= 'z' || s >= 'A' && s <= 'Z' || s >= '0' && s <= '9')
        {
            postfix[j++] = s;
        }
        else if (isEmpty() || s == '(')
        {
            push(s);
        }
        else if (s == ')')
        {
            while (peep() != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else
        {
            while (!isEmpty() && peep() != '(' && precedence(peep(), s))
            {
                postfix[j++] = pop();
            }
            push(s);
        }
    }
    while (!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("\nPostfix = %s", postfix);
}

int main(int argc, char const *argv[])
{
    stk.top = -1;
    char infix[size];
    printf("Enter any expression: ");
    gets(infix);

    postfix(infix);

    return 0;
}

//  A+B*C/D^E^F*G
