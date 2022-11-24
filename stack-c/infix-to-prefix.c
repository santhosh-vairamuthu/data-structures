#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char infix[10000],prefix[10000],stack[1000],temp[1000];
int top=-1,len=0;

int iSPrecedence(char s){
    switch(s){
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
        case '%':
            return 4;
        case '^':
            return 5;
        case '(':
        case ')':
            return 0; 
    }
}
int iCPrecedence(char s){
    switch(s){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 3;
        case '^':
            return 6;
        case '(':
            return 9;
        case ')':
            return 0;
    }
}

void push(char s){
    stack[++top]=s;
}
void pop(){
    if(top>=0){
        stack[top]='\0';
        top--;
    }
}
int peek(char t){
    int i=top;
    while(i>=0){
        if(stack[i]==t){
            break;
        }
        i--;
    }
    return i;
}
int pushAndPop(char o){
    prefix[len++]=stack[top];
    pop();
    if((iCPrecedence(o)>iSPrecedence(stack[top]))||(iSPrecedence(stack[top])==iSPrecedence(o))){
        push(o);
        return 0;
    }else{
        pushAndPop(o);
    }
}
void reverse(){
    int l=0;
    for(int i=strlen(infix)-1;i>=0;i--){
        temp[l++]=infix[i];
    }
    //printf("%s\n",temp);
}

void convertToPrefix(){
    reverse();
    for(int i=0;i<strlen(temp);i++)
    {
        if((temp[i]>=65 && temp[i]<=90)||(temp[i]>=97 && temp[i]<=122))
        {
            prefix[len++]=temp[i];
        }
        else if( temp[i]==')')
        {
            push(temp[i]);
        }
        else if(temp[i]=='(')
        {
            int ptr=peek(')');
            while(ptr!=top){
                prefix[len++]=stack[top];
                pop();
            }
            pop();

        }else
        {
            if(top==-1 || stack[top]==')'){
                push(temp[i]);
            }else{
                if((iCPrecedence(temp[i])>iSPrecedence(stack[top]))||(iSPrecedence(stack[top])==iSPrecedence(temp[i]))){
                    push(temp[i]);
                }else{
                    pushAndPop(temp[i]);
                }   
            }
        }
    }
    while(top>-1){
        prefix[len++]=stack[top];
        pop();
    }
    for(int i=0,j=strlen(prefix)-1;i<strlen(prefix)/2;i++,j--){
        char t=prefix[i];
        prefix[i]=prefix[j];
        prefix[j]=t;
    }
}

int main(){
    printf("Enter infix expression : ");
    scanf("%[^\n]s",infix);
    convertToPrefix();
    printf("The Prefix expression : %s\n",prefix);

}