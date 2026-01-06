// Linear Queue implementation in C

#include <stdio.h>
#define MAX 5

int QUEUE[MAX];
int front,rear;
front = -1;
rear = -1;

int isFull()
{
    if (rear == MAX-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if ( rear == -1 && front == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue()
{
    int n;
    printf("Enter the element : ");
    scanf("%d", &n);

    if(isFull())
    {
        printf("Queue Overflow!\n");
        return;
    }

    if ( rear == -1 && front == -1)
    {
        front = rear = 0;
        QUEUE[rear] = n;
        return;
    }

    QUEUE[++rear] = n;
}

void dequeue()
{
    if(isEmpty())
    {
        printf("Queue Underflow!\n");
        return;
    }

    if (front == rear)
    {
        front = rear = -1;
        return;
    }

    front++;
}

void peek()
{
    if(isEmpty())
    {
        printf("QUEUE is Empty!\n");
        return;
    }
    printf("FRONT --> %d", QUEUE[front]);
    printf("\n");
}

void display()
{
    if(isEmpty())
    {
        printf("QUEUE is Empty!\n");
        return;
    }

    int temp = front;
    while (temp!= rear)
    {
        printf("%d ", QUEUE[temp]);
        temp++;
    }
    printf("%d ", QUEUE[temp]);
    printf("\n");
}

int main() {
    int ch;
    {
        while (1)
        {
            printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. display: \n5. Exit");
            printf("\nENTER YOUR CHOICE : ");
            scanf("%d", &ch);
            switch(ch)
            {
                case 1: enqueue();
                        break;
                case 2: dequeue();
                        break;
                case 3: peek();
                        break;
                case 4: display();
                        break;
                case 5: return 0;
                default: printf("Invalid Choice!");
                        break;
            }

        }
    }
    return 0;
}