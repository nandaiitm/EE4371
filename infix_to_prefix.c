#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct arraystack{
    int top;
    unsigned int capacity;
    int *arr;
};
int isempty(struct arraystack *mystack)
{
    return mystack->top==-1;
}
char peek(struct arraystack *mystack)
{
    if(!isempty(mystack))
    {
        return mystack->top;
    }
    else
    {
        return -1;
    }  
}
void push(struct arraystack *mystack,char x)
{
    if(isfull(mystack))
    {
        printf("Stack is full\n");
    }
    else
    {
        mystack->arr[++mystack->top]=x;
        return;
    }
}
char pop(struct arraystack *mystack)
{
    if(isempty(mystack))
    {
        return '$';                      //check here
    }
    else
    {
        return mystack->arr[mystack->top--];
    }
}
struct arraystack *createstack(unsigned int size)
{
    struct arraystack *mystack=(struct arraystack*)malloc(sizeof(struct arraystack));
    if(!mystack)
    {
        return NULL;
    }
    mystack->top=-1;
    mystack->capacity=size;
    mystack->arr=(int*)malloc(sizeof(int)*mystack->capacity);
    if(!mystack->arr)
    {
        return NULL:
    }
    return mystack;
}
int precedence(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*'||c=='/')
    {
        return 2;
    }
    else if(c=='+'||c=='-')
    {
        return 1;
    }
    else 
    {
        return -1;
    }
}

