#include <stdio.h>
#define MAX 5

int STACK[MAX];
int TOP = -1;

int isEmpty()
{
    if (TOP == -1)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if (TOP == MAX-1)
    {
        return 1;
    }
    return 0;
}

void PUSH()
{
    if (isFull())
    {
        printf("Stack Overflow!\n");
        return;
    }
    int n;
    printf("Enter the element : ");
    scanf("%d", &n);
    TOP++;
    STACK[TOP]=n;
}

void POP()
{
    if(isEmpty())
    {
        printf("Stack Underflow!\n");
        return;
    }

    printf("Popped Element : %d \n", STACK[TOP]);
    TOP--;
}

void PEEK()
{
    if(isEmpty())
    {
        printf("Stack is Empty!");
        return;
    }

    printf("TOP --> %d \n", STACK[TOP]);
}

void DISPLAY()
{
    if(isEmpty())
    {
        printf("Stack is Empty!");
        return;
    }

    printf("TOP --> %d \n", STACK[TOP]);
    for (int i = (TOP-1); i >= 0; i-- )
    {
        printf("%d\n",STACK[i]);
    }
}

int main()
{
    int ch;
    {
        while (1)
        {
            printf("1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY \n5. Exit");
            printf("\nENTER YOUR CHOICE : ");
            scanf("%d", &ch);
            switch(ch)
            {
                case 1: PUSH();
                        break;
                case 2: POP();
                        break;
                case 3: PEEK();
                        break;
                case 4: DISPLAY();
                        break;
                case 5: return 0;
                default: printf("Invalid Choice!");
                        break;
            }

        }
    }
    return 0;
}