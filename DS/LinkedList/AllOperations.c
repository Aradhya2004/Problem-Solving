#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Node
{
    int info;
    struct Node *next;
}Node;

void show(Node *temp)
{
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
}

void addBeg(Node **s, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = value;

    if (*s == NULL)
        newNode->next = NULL;
    else
        newNode->next = *s;

    *s = newNode;

    printf("Node is added\n");
}

void addLast(Node **s, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info=value;
    newNode->next=NULL;
    Node* temp = *s;


    if(*s==NULL){ //list is empty
        *s = newNode;
        return;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    
    }

    temp->next = newNode;
    printf("Node Added");
}

void addAfter(Node **s, int sinfo, int value){
    Node * temp = *s;
    if (*s==NULL)
        printf("List is Empty");
    while(temp!=NULL){
        if(temp->info == sinfo){
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL)
        printf("%d Not Found\n", sinfo);
    else{
        Node * newNode = (Node *)malloc(sizeof(Node));
        newNode->info = value;
        newNode->next = temp->next;
        temp->next = newNode;
    }
   
}

void delBeg(Node **s){
    if(*s ==NULL){
        printf("Empty List\n");
        return;
    }
    Node *temp = *s;
    *s = (*s)->next;
    free(temp);
    printf("Node Deleted");
}

void delLast(Node **s){
    if(*s==NULL){
        printf("Empty List\n");
        return;
    }
    if((*s)->next==NULL){
        *s = NULL;
        return;
    }
    Node * prev = *s;
    Node * current = (*s)->next;
    while(current->next!=NULL){
        current = current->next;
        prev = prev->next;
    }
    prev->next = NULL;

}

void delInfo(Node **s, int sinfo){
    if(*s == NULL){
        printf("Empty list\n");
        return;
    }
    if((*s)->info == sinfo){
        Node *temp = *s;
        *s = (*s)->next;
        free(temp);
        printf("Node Deleted");
    }
    Node* prev = *s;
    Node* curr = (*s)->next;
    while(curr!=NULL){
        if(curr->info == sinfo){
            break;
        }
        curr = curr->next;
        prev = prev->next;
    }
    if(curr==NULL){
        printf("%d info not found\n",sinfo);
    }
    else{
        prev->next = curr->next;
        free(curr);
    }
}   

int getInfo(){
    int value;
    printf("Enter Node Info: ");
    scanf("%d",&value);
    return value;
}
int getValue(){
    int value;
    printf("Enter a Value: ");
    scanf("%d",&value);
    return value;
}


int main()
{   
    int choice;
    Node *s = NULL;
    do{
        puts("\nSingle Linked List Primitive Operations");
        puts("1...............Insert at Beginning");
        puts("2...............Insert at Last");
        puts("3...............Insert in Between");
        puts("4...............Delete from Beginning");
        puts("5...............Delete from Last");
        puts("6...............Delete on info Basis");
        puts("7...............Show List");
        puts("8...............Exit");

        puts("Enter your Choice");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                addBeg((&s),getValue());
                break;
            case 2:
                addLast((&s),getValue());
                break;
            case 3:
                addAfter((&s),getInfo(), getValue());
                break;
            case 4:
                delBeg(&s);
                break;
            case 5:
                delLast(&s);
                break;
            case 6:
                delInfo(&s, getInfo());
                break;
            case 7:
                show(s);
                break;
            case 8:
                puts("Coded by Aditya");
                break;
            default:
                puts("Invalid Choice");
        }

    }while(choice!=8);

    return 0;
} 