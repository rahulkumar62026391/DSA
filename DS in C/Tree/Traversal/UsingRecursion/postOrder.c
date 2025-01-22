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
}

/*
Function postorder(ptr)
    // Step 1: Check if the current node is NULL
    If ptr is NOT NULL Then
        // Step 2: Recursively call postorder on the left subtree
        postorder(ptr->left)

        // Step 3: Recursively call postorder on the right subtree
        postorder(ptr->right)

        // Step 4: Process the current node (print its data)
        Print ptr->data
    End If
End Function
*/

void postorder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
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

    postorder(root);

    return 0;
}
