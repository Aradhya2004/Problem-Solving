// Primitive Operations on Linked list
#include<stdio.h>

struct Node{
    int info;
    struct Node *next;
};

void show(struct Node *temp)
{   
    if (temp == NULL){
        printf("Empty List");
    }

    else{
        while(temp != NULL){
            printf("%d ",temp->info);
            temp = temp->next;
        }
    }
}

int main()
{   
    struct Node *start;
    struct Node b;
    struct Node c;
    struct Node d;
    struct Node e;
    struct Node f;

    b.info = 100;
    // b.next = NULL;

    // printf("%d\n",b.info);

    start = &b;
    // printf("%d\n",start->info);

    c.info = 200;
    c.next = NULL;
    b.next = &c;

    d.info = 300;
    d.next = NULL;
    c.next = &d;

    e.info = 400;
    f.info = 500;

    d.next = &e;
    e.next = &f;
    
    show(start);

    return 0;
}