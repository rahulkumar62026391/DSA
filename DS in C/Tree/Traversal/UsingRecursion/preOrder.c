#include <stdio.h>
#include <malloc.h>

// Create structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create Node
struct Node *createNode(int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

/*
Function preorder(ptr)
    // Step 1: Check if the current node is NULL
    If ptr is NOT NULL Then
        // Step 2: Process the current node (print its data)
        Print ptr->data

        // Step 3: Recursively call preorder on the left subtree
        preorder(ptr->left)

        // Step 4: Recursively call preorder on the right subtree
        preorder(ptr->right)
    End If
End Function
*/

void preorder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
int main()
{
    struct Node *root = createNode(5);
    struct Node *l1 = createNode(10);
    struct Node *l2 = createNode(15);
    struct Node *l3 = createNode(20);
    struct Node *r1 = createNode(25);
    struct Node *r2 = createNode(30);
    struct Node *r3 = createNode(35);

    // linking nodes of tree

    root->left = l1;
    root->right = r1;

    l1->left = l2;
    l1->right = l3;

    r1->left = r2;
    r1->right = r3;

    preorder(root);

    return 0;
}