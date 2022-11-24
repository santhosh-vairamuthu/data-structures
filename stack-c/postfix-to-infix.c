/*  POSTFIX TO INFIX CONVERSION */

/* this will be optimized soon*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char infix[10000],postfix[10000],stack[1000];
int top=-1,len=0;
void push(char s){
    stack[++top]=s;
}
char pop(){
    char i;
    if(top>=0){
        i=stack[top];
        stack[top]='\0';
        top--;
    }
    return i;
}
void popAndPush(char op){
    char ll[100],rr[100],lh,rh;
    int lc=0,rc=0,l=0,r=0;
    if(stack[top]==')'){
        rc=1;
        while(rc!=lc){
            ll[l++]=pop();
            if(stack[top]=='('){
                lc++;
            }else if(stack[top]==')'){
                rc++;
            }
        }
        ll[l++]=pop();
    }else{
        lh=pop();
    }
    rc=lc=0;
    if(stack[top]==')'){
        rc=1;
        while(rc!=lc){
            rr[r++]=pop();
            if(stack[top]=='('){
                lc++;
            }else if(stack[top]==')'){
                rc++;
            }
        }
        rr[r++]=pop();
    }else{
        rh=pop();
    }
    push('(');
    if(l>0){
        l--;
        while(l>=0){
            push(ll[l--]);
        }
    }else{
        push(lh);
    }
    push(op);
    if(r>0){
        r--;
        while(r>=0){
            push(rr[r--]);
        }
    }else{
        push(rh);
    }
    push(')');
}
void convertToInfix(){
    for(int i=0;i<strlen(postfix);i++){
        if((postfix[i]>=65 && postfix[i]<=90)||(postfix[i]>=97 && postfix[i]<=122)){
            push(postfix[i]);
        }
        else{
            char op=postfix[i];
            popAndPush(op);
        }
    }
    while(top>=0){
        if(stack[top]==')'){stack[top]='(';}
        else if(stack[top]=='(')(stack[top]=')');
        infix[len++]=stack[top];
        pop();
    }
}

int main(){
    printf("Enter postfix expression : ");
    scanf("%[^\n]s",postfix);
    convertToInfix();
    printf("The Infix expression : %s\n",infix);

}