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

void addBeg(struct Node **s, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->next = NULL;
    if(*s == NULL)
    {
        *s = newNode;
    }
    else{
        newNode->next = *s;
        *s = newNode;
    }
    printf("Node is added\n");
}

int main()
{
    struct Node *start = NULL;

    addBeg(&start,100);
    addBeg(&start,200);
    addBeg(&start,300);
    addBeg(&start,400);

    show(start);
    return 0;
}