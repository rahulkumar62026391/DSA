// C program to find the height of a binary tree using depth-first search (DFS) approach.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Returns "height" which is the number of edges along the longest path from the root node down
// to the farthest leaf node.

/*
FUNCTION height(root)
    IF root == NULL THEN
      Return -1

    //Compute the of left and right subtree
       SET lHeight=height(root->left)
       SET rHeight=height(root->right)

      Return (lHeight > rHeight ? lHeight : rHeight) +1

   END FUNCTION
*/
int height(struct Node *root)
{
    if (root == NULL)
        return -1;

    // compute the height of left and right subtrees
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return (lHeight > rHeight ? lHeight : rHeight) + 1;
}

struct Node *createNode(int val)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function is used to insert new Node
struct Node *insertBST(struct Node *root, int key)
{

    if (root == NULL)
    {
        return createNode(key);
    }

    if (root->data == key)
        return root;

    if (root->data < key)
    {
        root->right = insertBST(root->right, key);
    }
    else
    {
        root->left = insertBST(root->left, key);
    }

    return root;
}

// Function to print element in inorder
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main()
{

    // Representation of the input tree:
    //     6
    //    / \
    //   4   7
    //  / \
    // 3   5
    struct Node *root = createNode(6);
    root = insertBST(root, 4);
    root = insertBST(root, 3);
    root = insertBST(root, 5);
    root = insertBST(root, 7);

    inorder(root);

    printf("\n");

    printf("%d\n", height(root));

    return 0;
}