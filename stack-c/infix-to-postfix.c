/* INFIX TO POSTFIX USING STACK*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char infix[10000],postfix[10000],stack[1000];
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
    postfix[len++]=stack[top];
    pop();
    if(iCPrecedence(o)>iSPrecedence(stack[top])){
        push(o);
        return 0;
    }else{
        pushAndPop(o);
    }
}

void convertToPostfix(){
    for(int i=0;i<strlen(infix);i++)
    {
        if((infix[i]>=65 && infix[i]<=90)||(infix[i]>=97 && infix[i]<=123))
        {
            postfix[len++]=infix[i];
        }
        else if( infix[i]=='(')
        {
            push(infix[i]);
        }
        else if(infix[i]==')')
        {
            int ptr=peek('(');
            while(ptr!=top){
                postfix[len++]=stack[top];
                pop();
            }
            pop();

        }else
        {
            if(top==-1 || stack[top]=='('){
                push(infix[i]);
            }else{
                if(iCPrecedence(infix[i])>iSPrecedence(stack[top])){
                    push(infix[i]);
                }else{
                    pushAndPop(infix[i]);
                }   
            }
        }
    }
    while(top>-1){
        postfix[len++]=stack[top];
        pop();
    }
}

int main(){
    printf("Enter infix expression : ");
    scanf("%[^\n]s",infix);
    convertToPostfix();
    printf("The Postfix expression : %s\n",postfix);

}