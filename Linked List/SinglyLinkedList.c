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
    if (pos == 1)
    {
        newNode->next = *start;
        *start = newNode;
        return;
    }
    
    struct Node *temp = *start;
    for(int i = 1; i<pos-1 && temp!=NULL; i++) //when i = 1 then temp points to 2nd node
        temp = temp->next; 

    if(temp == NULL)
    {
        printf("Position out of bounds! Inserting at last position\n");
        temp=newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Element inserted at position %d\n", pos);
}

void insertAtEnd(struct Node **start)
{
    
}

void insertAtStart(struct Node **start)
{

}

void DeleteAtPosition(struct Node **start)
{

}

void DeleteAtStart(struct Node **start)
{

}

void DeleteAtEnd(struct Node **start)
{

}


void reverseLinkedList(struct Node **start)
{

}

void display(struct Node *start)
{

}

int main()
{
    struct Node *START = NULL;

    while (1)
    {
        int choice;
        printf("\n1. Insert At End\n2. Insert At Start\n3. Insert At Position\n4. Delete At Start\n5. Delete At End\n6. Delete At Postion\n7. Reverse Linked List\n8. Display\n9. Exit\n");
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
                int pos;
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
                DeleteAtPosition(&START);
                break;
            case 7:
                reverseLinkedList(&START);
                break;
            case 8:
                display(START);
                break;
            case 9:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    printf("\n");
    }
}