#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) ((a)>(b) ? a : b)


typedef struct node{
    int val;
    struct node *left;
    struct node *right;
    int height;
}*NODE;

int height(NODE cur){
    if(cur == NULL)
        return 0;
    return cur->height;
}

NODE newNode(int key){
    NODE new = (NODE)malloc(sizeof(struct node));
    new->val=key;
    new->height=1;
    new->left=NULL;
    new->right=NULL;
    return(new);
}

NODE rRotate(NODE y){
    NODE x = y->left;
    NODE T2 = x->right;

    //Rotate here
    x->right = y;
    y->left = T2;

    //Update height here
    y->height = MAX(height(y->left),height(y->right))+1;
    x->height = MAX(height(x->left),height(x->right))+1;

    return x; //new root
}

NODE lRotate(NODE y){
    NODE x = y->right;
    NODE T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = MAX(height(y->left),height(y->right))+1;
    x->height = MAX(height(x->left),height(x->right))+1;

    return x;
}

int balFactor(NODE cur){
    if(cur == NULL)
        return 0;
    return height(cur->left) - height(cur->right);
}

NODE insert(NODE new, int k){
    
    if(new == NULL)
        return(newNode(k));

    if(k < new->val)
        new->left = insert(new->left, k);
    else if(k > new->val)
        new->right = insert(new->right, k);
    else
        return new;

    new->height = MAX(height(new->left),height(new->right))+1;

    int bal = balFactor(new);

    //Now to check all four cases of imbalance we have:

    if(bal>1 && k < new->left->val) //LeftLeftCase
        return rRotate(new);

    if(bal<-1 && k > new->right->val)//RightRightCase
        return lRotate(new);

    if(bal>1 && k > new->left->val){//LeftRightCase
        new->left = lRotate(new->left);
        return rRotate(new);
    }
    
    if (bal<-1 && k < new->right->val){//RightLeftCase
        new->right = rRotate(new->right);
        return lRotate(new);
    }
    //return unchanged node
    return new;
}

void inorder(NODE cur){
    if(cur != NULL){
        inorder(cur->left);
        printf("%d ",cur->val);
        inorder(cur->right);
    }
}


int main(){
    NODE root = NULL;
    int ch,x;
    do{
        printf("\n1.Enter element(no duplicates)  2. Print inorder of AVL Tree  3.Exit    Enter choice : ");
        scanf("%d",&ch);
        switch (ch){
            case 1 : printf("Enter element : ");
                     scanf("%d",&x);
                     root = insert(root,x);
                     break;
            case 2 : printf("\nInorder traversal is : ");
                     inorder(root);
                     break;
            
            case 3 : break;

            default:
                break;
        }
    }while(ch != 3);
    return 0;
}