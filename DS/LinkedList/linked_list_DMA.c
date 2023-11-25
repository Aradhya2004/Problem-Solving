#include <stdio.h>
#include<malloc.h>
struct Node
{
    int info;
    struct Node *next;
};

void show(struct Node *temp)
{
    if (temp == NULL)
    {
        printf("Empty List");
    }

    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->next;
        }
    }
}

int main()
{
    struct Node *start;
    struct Node *temp;
    for (int i = 1; i <= 5; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->info = i * 10;
        if (i == 1)
        {
            start = temp;
            start->next = NULL;
        }
        else
        {
            temp->next = start;
            start = temp;
        }
    }
    show(start);
    return 0;
}