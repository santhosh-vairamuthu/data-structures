#include<stdio.h>
#include<stdlib.h>
int size=0;
struct Node{
    int data;
    struct Node* link;
};
struct Node* head=NULL,*tail=NULL;

struct Node* get_node(){
    struct Node* node=malloc(sizeof(struct Node));
    return node;
}

void create(int n){
    //struct Node* node=malloc(sizeof(struct Node));
    struct Node* node=get_node();
    node->data=n;
    node->link=NULL;
    if (head==NULL){
        head=node;
        tail=node;
    }else{
        tail->link=node;
        tail=node;
    }

}
void traversing(){
    struct Node* ptr=head;
    printf("\n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}
int searching(int n){
    int element;
    if(!n){
        printf("\nEnter an element to be search : ");
        scanf("%d",&element);
    }else{
        element=n;
    }
    int count=0,prog=0;
    struct Node* ptr=head;
    while(1){
        count++;
        if(ptr->data == element){
            //printf("\nThe element is found and its position is %d ",count);
            prog=1;
            break;
        }
        if(ptr->link==NULL){
            break;
        }
        ptr=ptr->link;
    }
    if(!n){
        if(!prog){
            printf("\nThe element is not present in the list !!!\n");
        }else{
            printf("\nThe element is found and its position is %d ",count);
        }
    }
    return prog;
}
void insert_beginning(){
    int element;
    printf("\nEnter an element to be inserted : ");
    scanf("%d",&element);
    struct Node* new_node=get_node();
    new_node->data=element;
    new_node->link=head;
    head=new_node;
}
int insert_position(){
    int element;
    printf("\nEnter an element to be inserted : ");
    scanf("%d",&element);
    struct Node* new_node=get_node();
    new_node->data=element;
    int position;
    printf("\nEnter the position : ");
    scanf("%d",&position);
    int count =1;
    struct Node* ptr=head,*ptr1=NULL;
    if(position<=size){
        if(position==1){
            new_node->link=head;
            head=new_node;
        }else{
            while(ptr!=NULL){
                if(count == position){
                    new_node->link=ptr;
                    ptr1->link=new_node;
                    break;
                }else{
                    count++;
                    ptr1=ptr;
                    ptr=ptr->link;
                }
            }
        }
        return 1;
    }else{
        printf("\nInvalid Position\n");
        return 0;
    }

}

void insert_end(){
    int element;
    printf("\nEnter an element to be inserted : ");
    scanf("%d",&element);
    struct Node* new_node=get_node();
    new_node->data=element;
    new_node->link=NULL;
    tail->link=new_node;

}

void insertion(){
    int ch,prog=1;;
    printf("\nInsertion at beginning - 1\nInsertion at a position - 2\nInsertion at ending - 3\n\n");
    printf("\nEnter your choise : ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            insert_beginning();
            break;
        case 2:
            prog=insert_position();
            break;
        case 3:
            insert_end();
            break;
        default:
            printf("\nInvalid choise !!!\n");
            prog=0;
            break;
    }
    if(prog){
        size++;
        traversing();
    }
}
void delete_beginning(){
    struct Node*ptr=head->link;
    free(head);
    head=ptr;

}
void delete_ending(){
    struct Node* ptr=head;
    struct Node* ptr1=ptr->link;
    while(ptr!=NULL){
        if(ptr1->link==NULL){
            ptr->link=NULL;
            free(ptr1);
        }else{
            ptr=ptr->link;
            ptr1=ptr1->link;
        }

    }
}

int delete_position(){

    int position;
    printf("\nEnter the position : ");
    scanf("%d",&position);
    int count=1;
    struct Node* ptr=head;
    if(position <=size){
        if(position==count){
            struct Node*ptr=head->link;
            free(head);
            head=ptr;
        }else{
            while(ptr!=NULL){
                count++;
                if(count == position){
                    struct Node * temp=ptr->link;
                    ptr->link=ptr->link->link;
                    free(temp);
                    break;
                }else{
                    ptr=ptr->link;
                }

            }
        }
        return 1;
    }else{
        printf("\nInvalid Position !!!\n");
        return 0;
    }

}
int delete_value(){
    int element;
    printf("\nEnter the element to delete : ");
    scanf("%d",&element);
    struct Node* ptr=head,*ptr1=NULL;
    int count=0;
    int drive= searching(element);
    if(drive){
        while(ptr!=NULL){
            count++;
            if(ptr->data==element && count == 1 ){
                delete_beginning();
                break;
            }else if(ptr->data==element && count == size){
                delete_ending();
                break;
            }else if(ptr->data==element){
                ptr1->link=ptr->link;
                free(ptr);
                break;
            }
            ptr1=ptr;
            ptr=ptr->link;
        }
        return 1;
    }else{
        printf("\nThe element not present in the list !!!\n");
        return 0;
    }
}

void deletion(){
    int ch,prog=1;
    printf("\nDelete at beginning - 1\nDelete at ending - 2\nDelete by position - 3\nDelete by value - 4\n\n");
    printf("\nEnter your choise : ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            delete_beginning();
            break;
        case 2:
            delete_ending();
            break;
        case 3:
            prog=delete_position();
            break;
        case 4:
            prog=delete_value();
            break;
        default :
            printf("Invalid Choise !!!\n");
            prog=0;
            break;
    }
    if(prog){
        size--;
        traversing();
    }

}


void merging(){
    struct Node* head2=NULL,*tail2=NULL;
    int size2;
    printf("Enter number of elements to be inserted in the list 2 : ");
    scanf("%d",&size2);
    if(size2==0){
        printf("\n The size must be greater than zero \n");
    }else{
        printf("\nEnter the elements separated by a space : ");
        int store;
        for(int i=0;i<size;i++){
            scanf("%d",&store);
            struct Node* node=get_node();
            node->data=store;
            node->link=NULL;
            if (head2==NULL){
                head2=node;
                tail2=node;
            }else{
                tail2->link=node;
                tail2=node;
            }
        }
        tail->link=head2;
        traversing();
        size+=size2;
    }
}

int Continue(){
	char con;
	printf("\nDo you want to continue (y/n) : ");
    scanf("\n%c",&con);
    if(con=='n'){
        return 0;
    }else{
		return 1;
	}
}
int main(){
    printf("Enter number of elements to be inserted in the list : ");
    scanf("%d",&size);
    printf("\nEnter the elements separated by a space : ");
    int store;
    for(int i=0;i<size;i++){
        scanf("%d",&store);
        create(store);
    }
    do{
        int choise;
        printf("\n\nTraversing - 1\nInsertion - 2\nDeletion - 3\nSearching - 4\nMerging - 5\n\n");
        printf("\nEnter your choise : ");
        scanf("%d",&choise);
        switch(choise){
            case 1:
                traversing();
                break;
            case 2:
                insertion();
                break;
            case 3:
                deletion();
                break;
            case 4:
                searching(0);
                break;
            case 5:
                merging();
                break;
            default:
                printf("Invalid Choise !!!\n");
                break;
        }
    }while(Continue());
}