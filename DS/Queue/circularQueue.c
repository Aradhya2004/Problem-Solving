#include <stdio.h>
#define SIZE 10

typedef struct Cirqueue
{
    int front;
    int rear;
    int data[SIZE];
} CirQueue;

CirQueue queue;

void reset()
{
    queue.rear = -1;
    queue.front = -1;
}

int isEmpty()
{
    return queue.front == -1;
}

int isFull()
{
    return (queue.rear + 1) % SIZE == queue.front;
}

void enQueue()
{
    if (isFull())
    {
        printf("Queue is Full\n");
    }
    else
    {
        if (queue.front == -1)
        {
            queue.front = 0;
        }
        int num;
        printf("Enter any number: ");
        scanf("%d", &num);
        queue.rear = (queue.rear + 1) % SIZE;
        queue.data[queue.rear] = num;
        printf("Number inserted\n");
    }
}

void deQueue()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        if (queue.front == queue.rear)
        {
            queue.front = queue.rear = -1;
        }
        else
        {
            int item = queue.data[queue.front];
            queue.front = (queue.front + 1) % SIZE;
            printf("%d is deleted \n", item);
        }
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
        printf("Numbers are: ");
        int i = queue.front;
        do
        {
            printf("%d ", queue.data[i]);
            i = (i + 1) % SIZE;
        } while (i != queue.rear);
        printf("\n");
    }
}

int main()
{
    reset();
    int choice;
    printf("Queue Using Stack Implementation\n");
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
