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
        printf("\n");
    }
}

void delLast(struct Node **s)
{
    if(*s == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*s)->next == NULL)
    {
        *s = NULL;
        return;
    }
    struct Node *prev, *curr;
    curr = (*s)->next;
    prev = *s;
    while(curr->next != NULL)
    {
        curr = curr->next;
        prev = prev->next;
    }
    free(curr);
    prev->next = NULL;
}

int main()
{
    struct Node *start = NULL;

    struct Node b;
    struct Node c;
    struct Node d;
    struct Node e;
    struct Node f;

    b.info = 100;
    start = &b;
    c.info = 200;
    b.next = &c;
    d.info = 300;
    c.next = &d;
    e.info = 400;
    f.info = 500;
    d.next = &e;
    e.next = &f;
    f.next = NULL;
    
    show(start);

    delLast(&start);

    show(start);
      
    return 0;
}