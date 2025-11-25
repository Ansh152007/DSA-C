// Develop a C program to implement Binary search tree, traversal of Binary tree, largest node, smallest node and count number of nodes

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void insertNode(struct Node **root, int data)
{
    if (*root == NULL)
    {
        *root = createNode(data);
        return;
    }
    if (data < (*root)->data)
    {
        insertNode(&((*root)->left), data);
    }
    else
    {
        insertNode(&((*root)->right), data);
    }
}

void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void PreOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

void PostOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void findLargestNode(struct Node *root)
{
    struct Node *current = root;
    while (current->right != NULL)
    {
        current = current->right;
    }
    printf("Largest Node: %d\n", current->data);
}

void findsmallestNode(struct Node *root)
{
    struct Node *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
}

int NumberoFNodes(struct Node *root)
{
    if (root != NULL)
    {
        return 1 + NumberoFNodes(root->left) + NumberoFNodes(root->right);
    }
    return 0;
}

int main()
{
    struct Node *root = NULL;
    int choice;
    while (1)
    {
        printf("\n1. Insert Node\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Find Largest Node\n6. Find Smallest Node\n7. Count Number of Nodes\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int data;
            printf("Enter value to insert: ");
            scanf("%d", &data);
            insertNode(&root, data);
            break;
        }
        case 2:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder Traversal: ");
            PreOrderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder Traversal: ");
            PostOrderTraversal(root);
            printf("\n");
            break;
        case 5:
            findLargestNode(root);
            break;
        case 6:
            findsmallestNode(root);
            break;
        case 7:
            printf("Number of Nodes: %d\n", NumberoFNodes(root));
            break;
        case 8:
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }  
}
