/*FUNCTION deleteBST(root, key)
    IF root IS NULL
        RETURN root

    // Traverse the tree to find the node to delete
    IF key < root->data
        SET root->left = deleteBST(root->left, key)

    ELSE IF key > root->data
        SET root->right = deleteBST(root->right, key)

    ELSE
        // Node to be deleted is found

        // Case 1: Node has no children (leaf node)
        IF root->left IS NULL AND root->right IS NULL
            FREE root  //free(root)
            SET root = NULL

        // Case 2: Node has one child
        ELSE IF root->left IS NULL
            SET temp = root->right
            FREE root  //free(root)
            RETURN temp

        ELSE IF root->right IS NULL
            SET temp = root->left
            FREE root   //free(root)
            RETURN temp

        // Case 3: Node has two children
        ELSE
            SET temp = findMin(root->right)  // Find inorder successor
            SET root->data = temp->data       // Copy successor's value to root
            SET root->right = deleteBST(root->right, temp->data) // Delete successor

    RETURN root
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

//Function to create to new Node
struct Node* createNode(int key){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}

//Function to insert element in tree
struct Node* insertBST(struct Node* root,int key){
    if(root == NULL)
    return createNode(key);

    if(root->data==key)
     return root;

     if(root->data < key){

        root->right=insertBST(root->right,key);
     }else{
        root->left=insertBST(root->left,key);
     }

        return root;
}

//Function to find minimum value in BST

struct Node* findMin(struct Node* node){
    while(node->left !=NULL){
        node=node->left;
    }
    return node;
}

//Function to delete Node in BST
struct Node* deleteBST(struct Node* root,int key){
        if(root==NULL)
        return root;

        if(root->data > key){

            root->left=deleteBST(root->left,key);

        }else if(root->data < key){

            root->right=deleteBST(root->right,key);

        }else{

            //Case 1: No child

            if(root->left == NULL && root->right == NULL){
                free(root);
                root=NULL;
            }

            //Case 2: One Child

            else if(root->left == NULL){
                struct Node* temp=root->right;
                free(root);
                return temp;
            }

            else if(root->right == NULL){
                struct Node* temp=root->left;
                free(root);
                return temp;
            }

            //Case 3: Two Children

            else{
                struct Node* temp=findMin(root->right);
                root->data=temp->data;
                root->right=deleteBST(root->right,temp->data);
            }
        }

        return root;
}

void inorder(struct Node* root){
    if(root !=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main(){
        
        struct Node* root=createNode(5);
        root=insertBST(root,4);
        root=insertBST(root,7);
        root=insertBST(root,1);
        root=insertBST(root,9);
        root=insertBST(root,15);
        root=insertBST(root,11);
        root=insertBST(root,20);
        root=insertBST(root,6);
        root=insertBST(root,2);

        inorder(root);

        printf("\n");

       root= deleteBST(root,20);
        inorder(root);

         printf("\n");

       root= deleteBST(root,1);
        inorder(root);

        printf("\n");

        root= deleteBST(root,9);
        inorder(root);

    return 0;
}