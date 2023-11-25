#include <stdio.h>
#include <malloc.h>

struct Node
{
    int coe;
    int pow;
    struct Node *next;
};

struct Node *createNode(int coe, int pow)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coe = coe;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

void addLast(struct Node **s, int coe, int pow)
{
    struct Node *newNode = createNode(coe, pow);
    if (*s == NULL)
    {
        *s = newNode;
    }
    else
    {
        struct Node *temp = *s;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void show(struct Node *temp)
{
    printf("%dx^%d ", temp->coe, temp->pow);
    temp = temp->next;
    while (temp != NULL)
    {
        if (temp->pow != 0)
        {
            if (temp->coe > 0)
            {
                printf("+ %dx^%d ", temp->coe, temp->pow);
            }
            else
            {
                printf("%dx^%d ", temp->coe, temp->pow);
            }
        }
        else
        {
            if (temp->coe > 0)
            {
                printf("+ %d ", temp->coe);
            }
            else
            {
                printf("%d ", temp->coe);
            }
        }
        temp = temp->next;
    }
    printf("\n");
}

struct Node *addPolynomial(struct Node *p1, struct Node *p2)
{
    struct Node *poly3 = NULL;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->pow == p2->pow)
        {
            addLast(&poly3, p1->coe + p2->coe, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow)
        {
            addLast(&poly3, p1->coe, p1->pow);
            p1 = p1->next;
        }
        else
        {
            addLast(&poly3, p2->coe, p2->pow);
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        addLast(&poly3, p1->coe, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        addLast(&poly3, p2->coe, p2->pow);
        p2 = p2->next;
    }
    return poly3;
}

struct Node *subPolynomial(struct Node *p1, struct Node *p2)
{
    struct Node *poly3 = NULL;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->pow == p2->pow)
        {
            addLast(&poly3, p1->coe - p2->coe, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow)
        {
            addLast(&poly3, p1->coe, p1->pow);
            p1 = p1->next;
        }
        else
        {
            addLast(&poly3, p2->coe, p2->pow);
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        addLast(&poly3, p1->coe, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        addLast(&poly3, p2->coe, p2->pow);
        p2 = p2->next;
    }
    return poly3;
}

int main()
{
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *poly3 = NULL;
    struct Node *poly4 = NULL;

    addLast(&poly1, 2, 3);
    addLast(&poly1, 39, 2);
    addLast(&poly1, -10, 0);

    addLast(&poly2, 10, 4);
    addLast(&poly2, 5, 3);
    addLast(&poly2, 20, 1);
    addLast(&poly2, 50, 0);

    show(poly1);
    show(poly2);

    poly3 = addPolynomial(poly1, poly2);
    printf("Polynomial Addition\n");
    show(poly3);

    poly4 = subPolynomial(poly1, poly2);
    printf("Polynomial Subtraction\n");
    show(poly4);

    return 0;
}