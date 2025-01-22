#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

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
Function inorder(ptr)
    // Step 1: Check if the current node is NULL
    If ptr is NOT NULL Then
        // Step 2: Recursively call inorder on the left subtree
        inorder(ptr->left)

        // Step 3: Process the current node (print its data)
        Print ptr->data

        // Step 4: Recursively call inorder on the right subtree
        inorder(ptr->right)
    End If
End Function
*/

void inorder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
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

    root->left = l1;
    root->right = r1;

    l1->left = l2;
    l1->right = l3;

    r1->left = r2;
    r1->right = r3;

    inorder(root);

    return 0;
}
