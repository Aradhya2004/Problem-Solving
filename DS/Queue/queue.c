#include <stdio.h>
#define SIZE 10

typedef struct Linqueue
{
    int front;
    int rear;
    int data[SIZE];
} LinQueue;

LinQueue queue;

int isEmpty()
{
    return queue.front > queue.rear;
}

int isFull()
{
    return queue.rear == SIZE - 1;
}

void reset()
{
    queue.front = 0;
    queue.rear = -1;
}

void enQueue()
{
    if (isFull())
    {
        printf("Queue is Full\n");
    }
    else
    {
        int num;
        printf("Enter any number: ");
        scanf("%d", &num);
        queue.data[++queue.rear] = num;
        printf("Number inserted\n");
    }
}

void deQueue()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else if(queue.front == queue.rear){
        reset();
    }
    else
    {
        int item = queue.data[queue.front];
        queue.front += 1;
        printf("%d is deleted \n", item);
    }
}

void show()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("\nFront=%d Rear=%d\n",queue.front,queue.rear);
        printf("Queue elements are: ");
        for (int i = queue.front; i <= queue.rear; i++)
        {
            printf("%d ", queue.data[i]);
        }
        printf("\n");
    }
}

int main()
{
    reset();
    int choice;
    printf("Queue using stack implementation\n");
    printf("1....Enqueue\n");
    printf("2....Dequeue\n");
    printf("3....Display\n");
    printf("4....Exit\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enQueue();
            break;
        case 2:
            deQueue();
            break;
        case 3:
            show();
            break;
        case 4:
            break;
        default:
            printf("Invalid Choice \n");
            break;
        }
    }
    return 0;
}