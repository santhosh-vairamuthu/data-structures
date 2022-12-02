/*UNDER DEVELOPMENT*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int data;
    struct Node *left,*right;
};
struct Node *root=NULL;
struct Node * getnode(){
    struct Node * node=malloc(sizeof(struct Node));
    return node;
}
void construct(int d){
        struct Node *ptr=getnode(),*actual,*temp;
        ptr->data=d;
        ptr->left=ptr->right=NULL;
        if(root==NULL){
            root=ptr;
        }else{
            temp=root;
            while(temp){
                actual=temp;
                if(d<temp->data){
                    temp=temp->left;
                }else{
                    temp=temp->right;
                }
            }
            if(d<actual->data){
                actual->left=ptr;
            }else{
                actual->right=ptr;
            }
        }
}
struct Node *min(struct Node *node){
    struct Node *ptr = node;
    while (ptr->left != NULL){
        ptr = ptr->left;
    }
    return ptr;
}
struct Node* delete(struct Node* ptr,int d)
{
    struct Node* temp;
    int flag=0;
    if(root->data==d){
        flag=1;
    }
    if(ptr==NULL){
        return NULL;
    }else if(d < ptr->data){
        ptr->left=delete(ptr->left, d);
    }else if(d>ptr->data){
        ptr->right=delete(ptr->right, d);
    }else if(ptr->left && ptr->right){
        temp=min(ptr->right);
        ptr->data=temp->data;
        ptr->right=delete(ptr->right,ptr->data);
    }
    else{
        temp=ptr;
        if(ptr->left==NULL){
            ptr=ptr->right;
        }else if(ptr->right==NULL){
            ptr=ptr->left;
        }
        free(temp);
    }
    if(flag){
        root=ptr;
    }
    return ptr;
}
void inorder(struct Node *ptr){
    if(ptr==NULL){
        return;
    }
    
    inorder(ptr->left);
    printf("%d ",ptr->data);
    inorder(ptr->right);
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
    int n,d,del;
    printf("Enter number of elements to be inserted : ");
    scanf("%d",&n);
    int t=n;
    while(n--){
        printf("\nEnter Element %d : ",t-n);
        scanf("%d",&d);
        construct(d);
    }
    printf("\nPreorder Expression : ");
    preorder(root);
    printf("\n");
    while(root){
        printf("\nEnter element to be deleted : ");
        scanf("%d",&del);
        delete(root,del);
        printf("\nPreorder Expression : ");
        preorder(root);
        printf("\n");
    }
}
