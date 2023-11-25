#include <stdio.h>
#include <malloc.h>
struct Node
{
    int info;
    struct Node *next;
};
void show(struct Node *temp)
{
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
}

void addlast(struct Node **s, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->next = NULL;
    struct Node *temp = *s;
    // checkig if list is empty
    if (*s == NULL)
    {
        *s = newNode;
    }
    else{
            while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    }
    printf("node addded\n");
}

int main()
{
    struct node *start = NULL;
    addlast(&start, 100);
    addlast(&start, 200);
    addlast(&start, 300);
    show(start);
    return 0;
}