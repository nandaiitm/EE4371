#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
    char ch[1000];
    char c[1000];
    char *cptr;
    int i = 0;
    double arr[20];
    FILE *fptr;
    if((fptr = fopen("traffic_input.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }
    fgets(ch,100,fptr);
    puts(ch);
}

// #include <cstdlib>
// // #include <bits/stdc++.h>

// class stacknode{
//     int data;
//     stacknode* next;
// };
// int pop(stacknode **root)
// {
//     if(!*root)
//     {
//         return -1;
//     }
//     else
//     {
//         stacknode *temp;
//         temp=*root;
//         *root=*root->next;
//         int pud=temp->data;
//         free(temp);
//         return pud;
//     }
// }
// stacknode *createnode(int data)
// {
//     stacknode *temp= new stacknode();
//     temp->data=data;
//     temp->next=NULL;
//     return temp;
// }




// #define MAX_SIZE 1000
// class mystack{
//     int top;
//     public:
//         int arr[MAX_SIZE];
//         mystack(){
//             top=-1;
//         }
//         bool push(int x);
//         int pop();
//         bool isempty();
//         int peek();
// };
// bool mystack::push(int x)
// {
//     if(top>=MAX_SIZE-1)
//     {
//         cout << "Stack Overflow";
//         return false;
//     }
//     arr[++top]=x;
//     return true;
// }
// int mystack::pop()
// {
//     if(top<0)
//     {
//         return -1;
//     }
//     return arr[top--];
// }
// int mystack::peep()
// {
//     if(top<0)
//     {
//         return -1;
//     }
//     return arr[top];
// }

// int main()
// {
//     class mystack s;
//     s.push(10);
//     s.push(20);
//     s.pop();
// }



// int countelements(struct listNode **head)
// {
//     int count=0;
//     struct listNode *current;
//     current = *head;
//     while(current!=NULL)
//     {
//         count++;
//         current=current->next;
//     }
//     return count;
// }

// void insertElement(struct listNode **head,int data,int position)
// {
//     int k=1;
//     struct listNode *newnode,*current,*q;
//     current=*head;
//     newnode=(struct listNode*)(malloc(sizeof(struct listNode)));
//     if(newnode==NULL)
//     {
//         cout << "Memory limit Exceeded" << endl;
//         return;
//     }
//     if(position==1)
//     {
//         newnode->data=data;
//         newnode->next=*head;
//         *head=newnode;
//         return;
//     }
//     while(current!=NULL && k<position)
//     {
//         k++;
//         q=current;
//         current=current->next;

//     }
//     if(current==NULL)
//     {
//         cout << "position not found" << endl;
//         return;
//     }
//     newnode->next=current;
//     newnode->data=data;
//     q->next=newnode;
//     return;

    
// }