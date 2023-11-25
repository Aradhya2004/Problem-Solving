// #define size 100
// #include <stdio.h>

// typedef struct stack
// {
//     int data[size];
//     int top;
// } stack;

// stack stk;

// int isEmpty()
// {
//     return stk.top == -1;
// }

// int isFull()
// {
//     return stk.top == size - 1;
// }

// void push(int item)
// {
//     if (!isFull())
//     {
//         stk.top++;
//         stk.data[stk.top] = item;
//     }
// }
// int pop()
// {
//     if (!isEmpty())
//     {

//         return stk.data[stk.top--];
//     }
// }
// int peep()
// {
//     if (!isEmpty())
//     {

//         return stk.data[stk.top];
//     }
// }
// int validate(char expr[])
// {
//     int i = 0;
//     while (expr[i] != '\0')
//     {
//         char bracket = expr[i];
//         if (bracket == '(')
//         {
//             push(bracket);
//         }
//         else
//         {
//             if (!isEmpty)
//             {
//                 pop();
//             }
//             else
//             {
//                 return 0;
//             }
//         }
//         i++;
//     }
//     return isEmpty();
// }

// int main()
// {
//     stk.top = -1;
//     char expr[100];
//     printf("Enter any expression");
//     gets(expr);

//     if (validate(expr))
//     {
//         printf("Valid expression");
//     }
//     else
//     {
//         printf("Not valid");
//     }
//     return 0;
// }

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

void push(int num)
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

int validate(char ex[])
{
    int i = 0;
    while (ex[i] != '\0')
    {

        char bracket = ex[i];
        if (bracket == '(')
        {
            push(bracket);
        }
        else
        {
            if (!isEmpty())
            {
                pop();
            }
            else
            {
                return 0;
            }
        }
        i++;
    }
    return isEmpty();
}

int main(int argc, char const *argv[])
{
    stk.top = -1;
    char ex[100];
    printf("Enter any expression\n");
    gets(ex);

    if (validate(ex))
    {
        printf("Valid expression");
    }
    else
    {
        printf("Invalid expression");
    }

    return 0;
}