#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int  stack[MAX];
int top=-1;

int isFull(){
if(top==MAX-1){
    return 1;
}
else{ 
    return 0;
}
}

int isEmpty(){
if(top==-1){
    return 1;
}
else{ 
    return 0;
}
}

void push(int value)
{
if (isFull()==1){
    printf("Stack Overflow");
    return;
}
else{
    top++;
    stack[top]=value;
}
}

int pop()
{int item;
if(isEmpty()){
    printf("Stack Underflow"); 
    return -1;
}
else{
    item=stack[top];
    top--;
    return item;
}
}

void peek(){
if(isEmpty()){
    printf("Underflow");
}
else{
    printf("Top element is %d",stack[top]);
}
}

void display()
{if(isEmpty()){
    printf("Underflow");
}
else{
    for(int i=0;i<top+1;i++)
    printf("%d ",stack[i]);
}
}

int main(){
int choice,value;
    while(1){
        printf("\nMENU\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value to push:");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                value=pop();
                if(value!=-1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);

            default:
                printf("Invalid choice.Try again"); 
        }
        printf("\n");
    }
    return 0;                
}
