/*This code generate a expression tree from an postfix string and print infix and prefix expression from that tree*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char data;
    struct Node *left, *right;
};
struct Node* getnode(){
    struct Node* node=malloc(sizeof(struct Node));
    return node;
}

struct Node* stack[100];
int top=-1;
char postfix[1000];
void push(struct Node*ptr){
    stack[++top]=ptr;
}
struct Node* pop(){
    struct Node *ptr=NULL;
    if(top>-1){
        ptr=stack[top];
        stack[top]='\0';
        top--;
    }
    return ptr;
}
void pushAndPop(char op){
    struct Node * left,*right,*ptr;
    right=pop();
    left=pop();
    ptr=getnode();
    ptr->data=op;
    ptr->left=left;
    ptr->right=right;
    push(ptr);
}
void createTree(){
    for(int i=0;i<strlen(postfix);i++){
        char t=postfix[i];
        if((t>=65 && t<=90)||(t>=97 && t<=122)){
            struct Node *ptr=getnode();
            ptr->data=t;
            ptr->left=ptr->right=NULL;
            push(ptr);
        }else{
            pushAndPop(t);
        }
    }
}
int isOperator(char t){
    if((t>=65 && t<=90)||(t>=97 && t<=122)){
        return 0;
    }else{
        return 1;
    }
}
void printInfix(struct Node* root)
{
    if (root == NULL) {
        return;
    }
    if (isOperator(root->data)){
        printf("(");
    }
    printInfix(root->left);
    printf("%c",root->data);
    printInfix(root->right);
    if (isOperator(root->data)) {
        printf(")");
    }
}
void printPrefix(struct Node* node)
{
    if (node == NULL)
        return;
    printf("%c ", node->data);
    printPrefix(node->left);
    printPrefix(node->right);
}
void printPostfix(struct Node* node)
{
    if (node == NULL)
        return;
    printPostfix(node->left);
    printPostfix(node->right);
    printf("%c ", node->data);
}

int main(){
    printf("Enter postfix expression : ");
    scanf("%[^\n]s",postfix);
    createTree();
    printf("Infix Expression : ");
    printInfix(stack[top]);
    printf("\n");
    printf("Prefix Expression : ");
    printPrefix(stack[top]);
    printf("\n");
    printf("Postix Expression : ");
    printPostfix(stack[top]);
    printf("\n");

}