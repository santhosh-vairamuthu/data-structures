#include<stdio.h>
#define MAX 1000
int len,clk;
int arr[MAX];

int ispresent(int arr[],int e){
	int f=0;
	for(int i=0;i<len;i++){
    	if(arr[i]==e){
        	f=1;
    	}
	}
	return f;

}
void Traversing(int arr[]){
	clk=0;
	for(int i=0;i<len;i++){
    	printf("Element - %d Index - %d\n",arr[i],i);
	}
}
void InsertAtBegining(int arr[]){
	printf("Enter an element : ");
	int element,k;
	scanf("%d",&element);
	for(int i=0;i<len+1;i++){
    	k=arr[i];
    	arr[i]=element;
    	element=k;
	}
   	 
}
void InsertAtEnding(int arr[]){
	printf("Enter an element : ");
	int element,k;
	scanf("%d",&element);
	arr[len]=element;
	
   	 
}

void InsertionAtPosition(int arr[]){
    
	int position,element,k;
	printf("\n\nEnter the postion : ");
	scanf("%d",&position);
	printf("\nEnter the element : ");
	scanf("%d",&element);
	for(int i=position-1;i<len+1;i++){
    	int k=arr[i];
    	arr[i]=element;
    	element=k;
	}
	printf("\n");
	

}

void Insertion(int arr[]){
    
	printf("\nInsert at Begining -1\nInsert at Ending -2 \nInsert at a position- 3\n");
	printf("\n\nEnter your choise : ");
	int choise;
	scanf("%d",&choise);
	if(choise ==1){
    	InsertAtBegining(arr);
	}else if(choise ==2){
    	InsertAtEnding(arr);
	}else if(choise ==3){
    	InsertionAtPosition(arr);
	}else{
    	printf("\nInvalid choise");
	}
	len++;
	clk=1;
    

}

void Deletion(int arr[]){
	printf("Delete by Position - 1\nDelete by Element - 2 \n");
	int ch,delflag=0;
	printf("\nEnter your choise : ");
	scanf("%d",&ch);
	if(ch==1){
		delflag=1;
    	int pos;
    	printf("\nEnter the position : ");
    	scanf("%d",&pos);
    	for(int i=pos-1;i<len;i++){
        	arr[i]=arr[i+1];
    	}
	}else if(ch==2){
    	int element,f=0;
    	printf("\nEnter the element to delete : ");
    	scanf("%d",&element);
    	if(ispresent(arr,element)){
			delflag=1;
        	for(int i=0;i<len;i++){
            	if(arr[i]==element){
            	f=1;
            	}
            	if(f==1){
                	arr[i]=arr[i+1];
            	}
        	}

    	}else{
			printf("\nElement not present in the array !!");
		}
	}else{
    	printf("\nInvalid choise");
    	return;
	}
	printf("\n");
	if(delflag){
	len--;
	clk=1;
	}
	

}

void Searching(int arr[]){
	int element;
	printf("\nEnter the element to find : ");
	scanf("%d",&element);
	if(ispresent(arr,element)){
    	for(int i=0;i<len;i++){
        	if(arr[i]==element)
            	printf("\nElement - %d Index - %d",arr[i],i);
    	}
	}else{
    	printf("\nThe element is not present in the Array !!!\n");
	}
}

void Merge(int arr[]){
	int len2;
	printf("\nEnter the length of array 2 : ");
	scanf("%d",&len2);
	printf("\nEnter elements of array 2 : \n");
	int arr2[len2];
	for(int i=0;i<len2;i++){
    	scanf("%d",&arr2[i]);
	}
	for(int i=len,j=0;j<len2;i++,j++){
    	arr[i]=arr2[j];
	}
	clk=1;
	len+=len2;
	
}

void Sorting(int arr[]){
	for(int i=0;i<len;i++){
    	for(int j=i+1;j<len;j++){
        	if(arr[i]>arr[j]){
            	int t=arr[i];
            	arr[i]=arr[j];
            	arr[j]=t;
        	}
    	}
	}
	int ch;
	clk=0;
	printf("\nAscending - 1\nDescending - 2\n");
	printf("Enter your choise : ");
	scanf("%d",&ch);
	printf("\n");
	if(ch==1){
    	printf("\nAfter sorting in ascending order : \n");
    	for(int i=0;i<len;i++){
        	printf("%d ",arr[i]);
    	}
	}else{
    	printf("\nAfter sorting in descending order : \n");
    	for(int i=len-1;i>=0;i--){
        	printf("%d ",arr[i]);
    	}
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
	printf("Enter Number of elements in th array : ");
	scanf("%d",&len);
	
	printf("Enter the array elements : \n");
	for(int i=0;i<len;i++){
    	scanf("%d",&arr[i]);
	}
    do{
        printf("\n");
        printf("\nArray Traversing - 1\nArray Insertion - 2\nArray Deletion - 3\nArray Searching - 4\nArray Merging - 5\nArray Sorting -6 \n\n");
        int choise;
        printf("Enter your choise for array operation : ");
        scanf("%d",&choise);
		switch(choise){
			case 1:
				Traversing(arr);
				break;
			case 2:
				Insertion(arr);
				break;
			case 3:
				Deletion(arr);
				break;
			case 4:
				Searching(arr);
				break;
			case 5:
				Merge(arr);
				break;
			case 6:
				Sorting(arr);
				break;
			default:
				printf("\nInvalid choise !!!\n");
				break;    
		}
		if(clk){
			clk=0;
			for(int i=0;i<len;i++){
    			printf("%d ",arr[i]);
			}
		}	  
    }while(Continue());
	return 0;
}