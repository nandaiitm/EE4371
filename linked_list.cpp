# include <iostream>
# include <cstdio>
# include <cstdlib>

using namespace std;

struct listNode
    {
        int data;
        struct listNode* next;
    };
// int listLength(struct listNode* head);
void push(struct listNode **head_ref,int value);
void deleteList(struct listNode** head);
int main()
{
    struct listNode* head=NULL;
    push(&head,2);
    push(&head,3);
    push(&head,5);
    push(&head,9);
    deleteList(&head);
    return 0;

}
// int listLength(struct listNode* head)
// {
//     struct listNode* current=head;
//     int count=0;
//     while(current !=NULL)
//     {
//         count++;
//         current=current->next;
//     }
//     return count;
// }
void deleteList(struct listNode** head)
{
    struct listNode *current=*head,*after;
    while(current!=NULL)
    {
        after=current->next;
        free(current);
        current=after;
    }
    *head=NULL;
}
void push(struct listNode **head_ref,int value)
{
    struct listNode *newnode=NULL;
    newnode=(struct listNode*)malloc(sizeof(struct listNode));
    newnode->data=value;
    newnode->next=*head_ref;
    *head_ref=newnode;
}

Node *current=head,*end=NULL;
    int count=1;
    while(count<k)
    {
        current=current->next;
        count++;
    }
    end=current;
    while(end->next!=NULL)
    {
        end=end->next;
    }
    
    end->next=head;
    end=head;
    count=0;
    while(count<k-1)
    {
        end=end->next;
        count++;
        
    }
    end->next=NULL;
    
    head=current;
    return head;


    Node *current=head,*end=head;
    int count=1;
    while(end->next!=NULL)
    {
        end=end->next;
        
    }
    end->next=head;
    end=head;
    while(k>1&&count<k)
    {
        end=end->next;
        count++;
    }
    
    
    head=end->next;
    end->next=NULL;
    return head;