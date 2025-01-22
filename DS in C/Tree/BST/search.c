/*Function searchBST(root, key):
    // Step 1: Check if the root is NULL or if the key matches the root's data
    If root == NULL OR root->data == key:
        Return root   // If root is NULL, key is not found (return NULL). 
                       // If root's data equals the key, return the root node.

    // Step 2: If the key is greater than the current root's data, search the right subtree
    If key > root->data:
        Return searchBST(root->right, key)  // Recursively search in the right subtree.

    // Step 3: If the key is smaller than the current root's data, search the left subtree
    Else:
        Return searchBST(root->left, key)  // Recursively search in the left subtree.

*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

//Function to Create new  Node
struct Node* createNode(int key){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}

//Function to insert node 
struct Node* insertBST(struct Node* root,int key){
    if(root == NULL){
       return createNode(key);
    }

    if(root->data==key){
        return root;
    }

    if(root->data<key){
        root->right=insertBST(root->right,key);
    }else{
        root->left=insertBST(root->left,key);
    }

    return root;
}
//Function to search element 
struct Node* searchBST(struct Node *root,int key){

    if(root == NULL || root->data == key)
             return root;

      if(root->data<key){
           return searchBST(root->right,key);
      }else{
          return searchBST(root->left,key);
      }

}

//Function to print in inorder
void inorder(struct Node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main(){

    struct Node* root=createNode(5);
    root=insertBST(root,4);
    root=insertBST(root,8);
    root=insertBST(root,18);
    root=insertBST(root,10);
    root=insertBST(root,7);

    inorder(root);

    printf("\n");

    printf(searchBST(root,10) !=NULL ? "Found\n" : "Not Found\n");
    printf(searchBST(root,11) !=NULL ? "Found\n" :"Not Found\n");

    return 0;
}