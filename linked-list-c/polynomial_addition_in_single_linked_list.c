/*STILL UNDER DEVELOPMENT & TESTING
SO IF ANY ERROR PLEASE IGNORE IT WILL BE DEBUGGED SHORTLY
IF ANY IDEA TO SOLVE ERROR PLEASE REPORT 
*/


#include<stdio.h>
#include<stdlib.h>
struct Node{
    int coeff;
    int power;
    struct Node* link;
};
struct Node* head1=NULL,*head2= NULL,*head3=NULL,*tail1=NULL,*tail2=NULL,*tail3=NULL;
struct Node* get_node()
{
    struct Node* node=malloc(sizeof(struct Node));
    return node;
}
void insert(int c,int p,int e)
{
    struct Node* new_node=get_node();
    new_node->coeff=c;
    new_node->power=p;
    new_node->link=NULL;
    if(e==1){
        if(head1==NULL){
            head1=new_node;
            tail1=new_node;
        }else{
            tail1->link=new_node;
            tail1=new_node;
        }
    }else{
        if(head2==NULL){
            head2=new_node;
            tail2=new_node;
        }else{
            tail2->link=new_node;
            tail2=new_node;
        }
    }

}
void swap(struct Node *a, struct Node *b) 
{ 
    int temp = a->power,tt=a->coeff; 
    a->power = b->power; 
    a->coeff=b->coeff;
    b->coeff=tt;
    b->power = temp; 
} 
void orderList(struct Node *head) 
{ 
    int swapped, i; 
    struct Node *ptr1; 
    struct Node *lptr = NULL; 
    if (head == NULL) 
        return; 
    do
    { 
        swapped = 0; 
        ptr1 = head;
        while (ptr1->link != lptr) 
        { 
            if (ptr1->power < ptr1->link->power) 
            { 
                swap(ptr1, ptr1->link); 
                swapped = 1; 
            } 
            ptr1 = ptr1->link; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

void sum(){
    struct Node* pptr=head1,*qptr=head2;
    while(pptr!=NULL && qptr!=NULL){
        struct Node* new_node=get_node();
        if((pptr->power == qptr->power)&&(pptr!=NULL && qptr!=NULL)){
            new_node->coeff=pptr->coeff+qptr->coeff;
            new_node->power=qptr->power;
            new_node->link=NULL;
            pptr=pptr->link;
            qptr=qptr->link;
        }else if((pptr->power > qptr->power)){
            new_node->coeff=pptr->coeff;
            new_node->power=pptr->power;
            new_node->link=NULL;
            pptr=pptr->link;
        }else if((pptr->power < qptr->power)){
            new_node->coeff=qptr->coeff;
            new_node->power=qptr->power;
            new_node->link=NULL;
            qptr=qptr->link;
        }
        if (head3==NULL){
            head3=tail3=new_node;
        }else{
            tail3->link=new_node;
            tail3=new_node;
        }
    }
    while(pptr!=NULL){
        struct Node* new_node=get_node();
        new_node->coeff=pptr->coeff;
        new_node->power=pptr->power;
        new_node->link=NULL;
        pptr=pptr->link;
        if (head3==NULL){
            head3=tail3=new_node;
        }else{
            tail3->link=new_node;
            tail3=new_node;
        }
    }
    while(qptr!=NULL){
        struct Node* new_node=get_node();
        new_node->coeff=qptr->coeff;
        new_node->power=qptr->power;
        new_node->link=NULL;
        qptr=qptr->link;
        if (head3==NULL){
            head3=tail3=new_node;
        }else{
            tail3->link=new_node;
            tail3=new_node;
        }
    }
}
void print(struct Node *ptr){
    while(ptr!=NULL){
        if(ptr->link==NULL){
            printf("%dx^%d\n",ptr->coeff,ptr->power);
            break;
        }
        printf("%dx^%d + ",ptr->coeff,ptr->power);
        ptr=ptr->link;
    }
    printf("\n");
}
int main()
{
    int n1,n2;
    printf("Enter number of polynomial terms in equation one : ");
    scanf("%d",&n1);
    int c1,p1,t1=1;
    while(t1<=n1)
    {
        printf("\nEnter the coefficient of term %d : ",t1);
        scanf("%d",&c1);
        printf("\nEnter the exponent %d : ",t1);
        scanf("%d",&p1);
        t1++;
        insert(c1,p1,1);
    }
    printf("\nEnter number of polynomial terms in equation two : ");
    scanf("%d",&n2);
    int c2,p2,t2=1;
    while(t2<=n2)
    {
        printf("\nEnter the coefficient of term %d : ",t2);
        scanf("%d",&c2);
        printf("\nEnter the exponent of term %d : ",t2);
        scanf("%d",&p2);
        t2++;
        insert(c2,p2,2);
    }
    orderList(head1);
    print(head1);
    orderList(head2);
    print(head2);
    sum();
    orderList(head3);
    printf("\nThe sum of two polynomial equation is ");
    print(head3);
}