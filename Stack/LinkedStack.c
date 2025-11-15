#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack *next;
};

int isEmpty(struct Stack *top)
{
    return top == NULL ? 1 : 0;
}

void push(struct Stack **top)
{
    int n;
    printf("Enter the Element: ");
    scanf("%d", &n);
    struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
    newNode->data = n;
    newNode->next = *top;
    *top = newNode;
}

void peek(struct Stack *top)
{
    if (isEmpty(top))
    {
        printf("Stack is Empty!");
        return;
    }
    printf("\nThe top of the stack is %d.\n", top->data);
}

int pop(struct Stack *top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow!");
        return 0;
    }
    struct Stack *temp = top;
    top = top->next;
    int popedValue = temp->data;
    free(temp);
    return popedValue;
}

void display(struct Stack *top)
{
    if (isEmpty(top))
    {
        printf("Stack is Empty!");
        return;
    }
    printf("%d <--TOS",top->data);
    for(struct Stack *temp = top->next; temp!=NULL; temp = temp->next)
    {
        printf("%d \n",temp->data);
    }
}

int main()
{
    struct Stack *TOP = NULL;

    while (1)
    {
        int choice;
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push(&TOP);
                break;
            case 2:
                {
                    int poppedElement = pop(&TOP);
                    if (poppedElement != 0)
                        printf("Popped Element: %d\n", poppedElement);
                }
                break;
            case 3:
                peek(TOP);
                break;
            case 4:
                display(TOP);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    printf("\n");
    }
}