#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) ((a)>(b) ? a : b)


typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}*NODE;

NODE insert(NODE root, int x){
    NODE cur = root;
    NODE new = (NODE)malloc(sizeof(struct node));
    new->val=x;
    new->right = NULL; new->left = NULL;
    if(cur == NULL){
        root = new;
    }
    else{
        while(cur){
            if(x > cur->val){
                if(cur->right == NULL){
                    cur->right = new;
                    break;
                }
                cur=cur->right;
            }
            else if(x < cur->val){
                if(cur->left == NULL){
                    cur->left = new;
                    break;
                }
                cur=cur->left;
            }
        }
    }
    return root;
}

// NODE insert(NODE root,int x){
//     if(root==NULL){
//         root=(NODE)malloc(sizeof(struct node));
//         root->val=x;
//         root->left=root->right=NULL;
//     }
//     else if(x>root->val)
//         root->right=insert(root->right,x);
//     else if(x<root->val)
//         root->left=insert(root->left,x);
//     else{
//         printf("Duplicate node\n");
//         exit(0);
//     }
//     return(root);
// }

void inorder(NODE cur){
    if(cur){
        inorder(cur->left);
        printf("%4d",cur->val);
        inorder(cur->right);
    }
}

int main(){
    NODE root = NULL;
    int ch,x;
    do{
        printf("\n1.Enter element(no duplicates)  2. Print inorder  3.Exit    Enter choice : ");
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