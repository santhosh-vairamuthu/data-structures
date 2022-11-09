/* INFIX TO POSTFIX USING STACK*/

/*this will be optimized soon*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char infix[10000];
char postfix[10000],stack[1000];
int top=-1,len=0;

int iSPrecedence(char s){
    switch(s){
        case '+':
            return 2;
            break;
        case '-':
            return 2;
            break;
        case '*':
            return 4;
            break;
        case '/':
            return 4;
            break;
        case '^':
            return 5;
            break; 
        case '(':
            return 0;
        case ')':
            return 0; 
    }
}
int iCPrecedence(char s){
    switch(s){
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 3;
            break;
        case '/':
            return 3;
            break;
        case '^':
            return 6;
            break;
        case '(':
            return 9;
            break;
        case ')':
            return 0;
            break; 
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