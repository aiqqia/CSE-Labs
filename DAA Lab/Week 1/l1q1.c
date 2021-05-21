#include<stdio.h>
#include<stdlib.h>

typedef struct Node* Nodeptr;

typedef struct Node{
    int data;
    Nodeptr left;
    Nodeptr right;
}Node;

Nodeptr search(Nodeptr root, int key){
    if(!root){
        Nodeptr temp = (Nodeptr)malloc(sizeof(Node));
        temp->data = key;
        temp->left = temp->right = NULL;
        printf("Element inserted\n");
        return temp;
    }
    if(root->data == key){
        printf("Element Found.\n");
    }
    else if(root->data > key)
        root->left = search(root->left, key);
    else
        root->right = search(root->right, key);
    return root;
    }

void preorder(Nodeptr root){
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Nodeptr root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(Nodeptr root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    int op;
    Nodeptr root = NULL;
    int flag = 1;
    while(flag){
        printf("Enter option : \n");
        printf("1:Enter Key for search/insert  2:PreOrder  3:Inorder  4:PostOrder\n");
        scanf("%d",&op);
        switch(op){
            case 1 : printf("Enter Key : ");
                     int a;
                     scanf("%d",&a);
                     root = search(root, a);
                     break;
            case 2 : printf("Preorder Traversal : \n");
                     preorder(root);
                     printf("\n");
                     break;
            case 3 : printf("Inorder Traversal : \n");
                     inorder(root);
                     printf("\n");
                     break;
            case 4 : printf("Postorder Traversal : \n");
                     postorder(root);
                     printf("\n");
                     break;
            default : flag = 0;
        }
    }
    return 0;
}