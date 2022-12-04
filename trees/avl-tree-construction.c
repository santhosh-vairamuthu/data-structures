#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int data,height;
    struct Node *left,*right;
};
struct Node *getNode(int d){
    struct Node *node=malloc(sizeof(struct Node));
    node->data=d;
    node->height=1;
    node->left=node->right=NULL;
    return node;
}

struct Node *root=NULL;

int height(struct Node *ptr){
    if(ptr==NULL){
        return 0;
    }
    return ptr->height;
}
int max(int x,int y){
    if(x>y){
        return x;
    }else{
        return y;
    }
}
struct Node* leftRotate(struct Node* x){
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->right), height(x->left)) + 1;
    y->height = max(height(y->right), height(y->left)) + 1;

    return y;
}
struct Node* rightRotate(struct Node* y){
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(height(x->right),height(x->left)) + 1;
    y->height = max(height(y->right),height(y->left)) + 1;

    return x;
}
struct Node *construct(struct Node* ptr, int data){
    if (ptr == NULL){
        return  getNode(data);
    }
    if (data < ptr->data){
        ptr->left  = construct(ptr->left, data);
    }
    else if (data > ptr->data){
        ptr->right = construct(ptr->right, data);
    }
    ptr->height = 1 + max(height(ptr->left), height(ptr->right));
    int balance=height(ptr->left) - height(ptr->right);
    // Left Left Case
    if(balance>1 && data < ptr->left->data){
        printf("\nPerforming left left rotation at %d",ptr->data);
        return rightRotate(ptr);
    }
    // Right Right Case
    if(balance<-1 && data > ptr->right->data){
        printf("\nPerforming right right rotation at %d",ptr->data);
        return leftRotate(ptr);
    }
    // Left Right Case
    if(balance>1 && data > ptr->left->data){
        printf("\nPerforming left right rotation at %d",ptr->data);
        ptr->left = leftRotate(ptr->left);
        return rightRotate(ptr);
    }
    // Right Left Case
    if(balance<-1 && data < ptr->right->data){
        printf("\nPerforming right left rotation at %d",ptr->data);
        ptr->right = rightRotate(ptr->right);
        return leftRotate(ptr);
    }
    return ptr;
}
void preorder(struct Node *ptr){
    if(ptr==NULL){
        return;
    }
    printf("%d ",ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
}
int main(){
    int total;
    printf("Enter number of elements : ");
    scanf("%d",&total);
    printf("\n Enter element : ");
    while(total--){
        int data;
        scanf("%d",&data);
        root=construct(root,data);
    }
    printf("\nPreorder: ");
    preorder(root);
    printf("\n");
}
