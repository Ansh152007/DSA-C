#include <stdio.h>
#define SIZE 100
struct Stack
{
    int arr[SIZE];
    int top;
};

int isFull(int top,int size)
{
   return (top == size - 1) ? 1 : 0;
}

int isEmpty(int top)
{
    return (top == -1) ? 1 : 0;
}

void push(int arr[], int *top, int size)
{
    if (isFull(*top,size))
    {
        printf("Stack Overflow!\n");
        return;
    }
    int n;
    printf("\nEnter the Element: ");
    scanf("%d", &n);
    ++(*top);
    arr[*top] = n;
}

void peek(int arr[], int top)
{
    if (isEmpty(top)) {
        printf("Stack is Empty!\n");
        return;
    }
    printf("\nThe top of the stack is %d.\n", arr[top]);
}

int pop(int arr[], int *top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow!\n");
        return 0;
    }
    int temp = arr[*top];
    (*top)--;
    return temp;
}

void display(int arr[], int top)
{
    if (isEmpty(top))
    {
        printf("Stack is Empty!\n");
        return;
    }
    printf("%d <--TOS\n", arr[top]);
    for (int i = top-1 && top!=0; i > -1 ; i --){
        printf("%d\n", arr[i]);
    }
}

int main()
{
    struct Stack st;
    st.top = -1;

    while (1)
    {
        int choice;
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push(st.arr, &st.top, SIZE);
                break;
            case 2:
                {
                    int poppedElement = pop(st.arr, &st.top);
                    if (poppedElement != 0)
                        printf("Popped Element: %d\n", poppedElement);
                }
                break;
            case 3:
                peek(st.arr, st.top);
                break;
            case 4:
                display(st.arr, st.top);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    printf("\n");
    }
}