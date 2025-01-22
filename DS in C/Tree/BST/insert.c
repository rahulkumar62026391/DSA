/*Function InsertBST(root, key):
    // Step 1: If the current root is NULL, create a new node with the key and return it
    If root == NULL:
        Return createNode(key)  // createNode creates a new node with the key
         
    // Step 2: If the key already exists in the tree, return the current root (no insertion)
    If root->data == key:
        Return root  // Key is already present, no insertion

    // Step 3: If the key is greater than the current root's data, insert into the right subtree
    If key > root->data:
        SET root->right = InsertBST(root->right, key)  // Recur to insert in the right subtree

    // Step 4: If the key is smaller than the current root's data, insert into the left subtree
    Else:
        SET root->left = InsertBST(root->left, key)  // Recur to insert in the left subtree

    // Step 5: Return the unchanged root (to maintain the tree structure)
    Return root

    Time Complexity:
    =================
    Best/Average Case:O(log n),where n is the number of nodes(balanced BST).
    Worst Case:O(n),when the tree degenerates into a linled list.

*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int key);
struct Node *insertBST(struct Node *root, int key);
void inorder(struct Node *root);

int main()
{
    struct Node *root = createNode(5);
    root = insertBST(root, 8);
    root = insertBST(root, 7);
    root = insertBST(root, 10);
    root = insertBST(root, 15);

    inorder(root);

    return 0;
}
/*
FUNCTION createNode(key)
// Allocate memory for a new node
   struct Node* newNode = ( struct Node*) malloc(sizeof( struct Node))
   Set temp->data=key
   Set temp->left=NULL
   Set temp->right=NULL
   Return temp
*/
// Function  is used to create Node
struct Node *createNode(int key)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
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