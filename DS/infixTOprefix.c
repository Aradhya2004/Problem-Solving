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

void prefix(char infix[])
{
    int i = 0, j = 0;
    char prefix[size];

    while (infix[i] != '\0')
    {
        char s = infix[i++];
        if (s >= 'a' && s <= 'z' || s >= 'A' && s <= 'Z' || s >= '0' && s <= '9')
        {
            prefix[j++] = s;
        }
        else if (isEmpty() || s == '(')
        {
            push(s);
        }
        else if (s == ')')
        {
            while (peep() != '(')
            {
                prefix[j++] = pop();
            }
            pop();
        }
        else
        {
            while (!isEmpty() && peep() != '(' && precedence(peep(), s))
            {
                prefix[j++] = pop();
            }
            push(s);
        }
    }
    while (!isEmpty())
    {
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
    printf("\nPostfix = %s", prefix);
}

int main(int argc, char const *argv[])
{
    stk.top = -1;
    char infix[size];
    printf("Enter any expression: ");
    gets(infix);

    int n = sizeof(infix)/sizeof(infix[0]);
    int j = n - 1; 
    for (int i = 0; i < j; i++) { 
        char temp = infix[i]; 
        infix[i] = infix[j]; 
        infix[j] = temp; 
        j--; 
    } 
    printf("\nInfix = %s", infix);
    // prefix(infix);

    return 0;
}

// qwerty