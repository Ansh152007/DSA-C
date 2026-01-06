#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} NODE;

NODE *HEAD = NULL;

int totalCount()
{
    int TotalNODES = 0;
    NODE *temp = HEAD;
    while (temp != NULL)
    {
        TotalNODES++;
        temp = temp->next;
    }
    return TotalNODES;
}

void append(int n)
{

    if (HEAD == NULL)
    {
        HEAD = (NODE *)malloc(sizeof(NODE));
        HEAD->data = n;
        HEAD->next = NULL;
        return;
    }
    NODE *temp = HEAD;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = n;
    newNode->next = NULL;
    temp->next = newNode;
}

void insertAtPosition(int POS)
{
    int n;
    printf("Enter the element: ");
    scanf("%d", &n);

    if (HEAD == NULL)
    {
        printf("No Node present :: Appending at the start!");
        append(n);
        return;
    }

    if (POS > totalCount() + 1)
    {
        printf("Position > Total Nodes :: Appending at the end!");
        append(n);
        return;
    }

    if (POS == 1)
    {
        NODE *newNode = (NODE *)malloc(sizeof(NODE));
        newNode->data = n;
        newNode->next = HEAD;
        HEAD = newNode;
        return;
    }

    NODE *temp = HEAD;

    for (int i = 1; i < POS - 1; i++)
    {
        temp = temp->next;
    }

    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = n;
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position :: %d", POS);
}

void insertATStart()
{
    insertAtPosition(1);
}

void deleteAtEnd()
{
    if(HEAD == NULL)
    {
        printf("Linked List is Empty!");
        return;
    }

    if(HEAD->next == NULL)
    {
        free(HEAD);
        HEAD = NULL;
        return;
    }

    NODE *temp = HEAD;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    printf("\nLast Node is Deleted Successfully!\n");
}

void deleteAtPosition(int POS)
{
    if(HEAD == NULL)
    {
        printf("Linked List is Empty!");
        return;
    }

    if( POS >= totalCount())
    {
        deleteAtEnd();
        return;
    }

    if(POS == 1)
    {
        NODE *deletedNode = HEAD;
        HEAD = HEAD->next;
        free(deletedNode);
        printf("\nNode deleted Successfully at position :: 1\n");
        return;
    }

    NODE *temp = HEAD;

    for ( int i = 1; i < POS - 1; i++)
    {
        temp = temp->next;
    }
    NODE *deletedNode = temp->next;
    temp->next = temp->next->next;
    free(deletedNode);
    printf("\nNode deleted Successfully at position :: POS\n");
}

void deleteAtStart()
{
    deleteAtPosition(1);
}

void display()
{

}

int main()
{
    int n;
    printf("Enter the element: ");
    scanf("%d", &n);
    printf("");
    return 0;
}