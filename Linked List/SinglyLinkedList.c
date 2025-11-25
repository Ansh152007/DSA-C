// Menu driven Program to implement a singly linked-list and operations performed on it.
// C program to implement reversal of a singly linked list
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int countNodes(struct Node *start) {
    int count = 0;
    while (start != NULL) {
        count++;
        start = start->next;
    }
    return count;
}

void insertAtPosition(struct Node **start, int pos)
{
    int n;
    printf("Enter the Element: ");
    scanf("%d",&n);
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = n;
    newNode->next = NULL;

    if (pos == 1 || *start == NULL)
    {
        newNode->next = *start;
        *start = newNode;
        printf("Element inserted at position %d\n", pos);
        return;
    }

    struct Node *temp = *start;
    for(int i = 1; i < pos-1 && temp->next != NULL; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Element inserted at position %d\n", pos);
}

void insertAtEnd(struct Node **start)
{
    int n;
    printf("Enter the Element: ");
    scanf("%d",&n);
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = n;
    newNode->next = NULL;
    if (*start == NULL)
    {
        *start = newNode;
        return;
    }
    struct Node *temp = *start;
    while(temp-> next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtStart(struct Node **start)
{
    int n;
    printf("Enter the Element: ");
    scanf("%d",&n);
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = n;
    newNode->next = *start;
    *start = newNode;
}

void DeleteAtPosition(struct Node **start, int pos)
{
    if(*start == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if (pos == 1)
    {
        struct Node *toDelete = *start;
        *start = (*start)->next;
        free(toDelete);
        printf("Element Deleted at position %d\n", pos);
        return;
    }

    struct Node *prev = *start;
    for(int i = 1; i < pos-1 && prev != NULL; i++)
        prev = prev->next;

    if(prev == NULL || prev->next == NULL)
    {
        printf("Position out of bounds!\n");
        return;
    }
    struct Node *toDelete = prev->next;
    prev->next = toDelete->next;
    free(toDelete);
    printf("Element Deleted at position %d\n", pos);
}

void DeleteAtStart(struct Node **start)
{
    if(*start == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = *start;
    *start = (*start)->next;
    free(temp);
}

void DeleteAtEnd(struct Node **start)
{
    if(*start == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if ((*start)->next == NULL) {
        free(*start);
        *start = NULL;
        return;
    }
    struct Node *temp = *start;
    while(temp-> next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void reverseLinkedList(struct Node **start)
{
    struct Node *prev = NULL;
    struct Node *current = *start;
    struct Node *next = NULL;
    while (current != NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    *start = prev;
}

void display(struct Node *start)
{
    if (start == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = start;
    printf("Linked List: ");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *START = NULL;

    while (1)
    {
        int choice;
        int pos;
        printf("\n1. Insert At End\n2. Insert At Start\n3. Insert At Position\n4. Delete At Start\n5. Delete At End\n6. Delete At Postion\n7. Reverse Linked List\n8. Count of Nodes \n9. Display\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertAtEnd(&START);
                break;
            case 2:
                insertAtStart(&START);
                break;
            case 3:
                printf("Enter the postion: ");
                scanf("%d",&pos);
                insertAtPosition(&START,pos);
                break;
            case 4:
                DeleteAtStart(&START);
                break;
            case 5:
                DeleteAtEnd(&START);
                break;
            case 6:
                printf("Enter the postion: ");
                scanf("%d",&pos);
                DeleteAtPosition(&START, pos);
                break;
            case 7:
                reverseLinkedList(&START);
                break;
            case 8:
                printf("Number of Nodes: %d\n", countNodes(START));
                break;
            case 9:
                display(START);
                break;
            case 10:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    printf("\n");
    }
}