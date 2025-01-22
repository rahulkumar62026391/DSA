#include<stdio.h>
#include<stdlib.h>
#define bool int

struct tNode{
    int data;
    struct tNode* left;
    struct tNode* right;
};

struct sNode{
    struct tNode* node;
    struct sNode* next;
};


void push();
struct tNode* pop();
bool isEmpty();

void inorder(struct tNode* root){

    struct tNode* current=root;

    struct sNode* s=NULL;

    bool done=0;

    while(!done){

        if(current !=NULL){
            push(&s,current);
            current=current->left;
        }else{
            if(!isEmpty(s)){
                current=pop(&s);
                printf("%d ",current->data);

                current=current->right;
            }else{
                done=1;
            }
        }
    }
}

void push(){
    
}