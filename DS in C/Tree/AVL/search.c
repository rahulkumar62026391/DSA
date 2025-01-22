/*Function searchAVL(root, key):
    // Step 1: Check if the root is NULL or if the key matches the root's data
    If root == NULL OR root->data == key:
        Return root   // If root is NULL, key is not found (return NULL). 
                       // If root's data equals the key, return the root node.

    // Step 2: If the key is greater than the current root's data, search the right subtree
    If key > root->data:
        Return searchAVL(root->right, key)  // Recursively search in the right subtree.

    // Step 3: If the key is smaller than the current root's data, search the left subtree
    Else:
        Return searchAVL(root->left, key)  // Recursively search in the left subtree.

*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

//Function to create new Node
struct Node* createNode(int key){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1; //New leaf Node has height 1
    return temp;
}

//Function to get height of node
int getHeight(struct Node* node){
    return (node==NULL)? 0 : node->height;
}

//Function to get Balance Fator
int balanceFactor(struct Node* node){
    if(node== NULL)
    return 0;

    return getHeight(node->left)-getHeight(node->right);
}

//Function to get max value
int max(int a,int b){
    return (a>b) ? a : b ;
}

/*
     y                               x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y 
  / \       < - - - - - - -            / \
 T1  T2     Left Rotation            T2  T3
*/

struct Node* rightRotation(struct Node* y){
    struct Node* x=y->left;
    struct Node* T2=x->right;                                     

    //Perform Rotation
     x->right=y;
     y->left=T2;

     //Update Heights
     y->height=max(getHeight(y->left),getHeight(y->right)) + 1;
     x->height=max(getHeight(x->left),getHeight(x->right)) + 1;

     //Return new Node
     return x;
}

struct Node* leftRotation(struct Node* x){
        struct Node* y=x->right;
        struct Node* T2=y->left;

        //Perform Rotation
         y->left=x;
         x->right=T2;

        //Update Heights
        x->height=max(getHeight(x->left),getHeight(x->right)) + 1;
        y->height=max(getHeight(y->left),getHeight(y->right)) + 1;
         
  }

    //Function to insert new node
  struct Node* insertAVL(struct Node* root,int key){

        if(root==NULL)
        return createNode(key);

        if(key<root->data){
            root->left=insertAVL(root->left,key);
        }
        else if(key>root->data){
            root->right=insertAVL(root->right,key);
        }
        else{
            return root;  //Equal keys are not allowed in AVL
        }

        //Update the height of current root
        root->height=max(getHeight(root->left),getHeight(root->right)) + 1;

        //Get Balance Factor
        int bal_Factor=balanceFactor(root);

        //If node becomes unbalanced,then there are 4 cases:

        //Left-Left Case
        if(bal_Factor>1 && key<root->left->data){
            return rightRotation(root);
        }

        //Right-Right Case
        if(bal_Factor<-1 && key>root->right->data){
            return leftRotation(root);
        }

        //Left-Right Case
        if(bal_Factor>1 && key>root->left->data){
            root->left=leftRotation(root->left);
              return rightRotation(root);
        }

        //Right-Left Case
        if(bal_Factor<-1 && key<root->right->data){
            root->right=rightRotation(root->right);
            return leftRotation(root);
        }

        return root;

  }

  //Function to search element 
struct Node* searchAVL(struct Node *root,int key){

    if(root == NULL || root->data == key)
             return root;

      if(root->data<key){
           return searchAVL(root->right,key);
      }else{
          return searchAVL(root->left,key);
      }

}


  void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
  }

int main(){
    struct Node* root=NULL;

    root=insertAVL(root,50);
    root=insertAVL(root,40);
    root=insertAVL(root,30);
    root=insertAVL(root,20);
    root=insertAVL(root,35);
    root=insertAVL(root,32);
    root=insertAVL(root,70);
    root=insertAVL(root,80);

    inorder(root);

     printf("\n");

    printf(searchAVL(root,32) !=NULL ? "Found\n" : "Not Found\n");
    printf(searchAVL(root,38) !=NULL ? "Found\n" :"Not Found\n");


    return 0;
}