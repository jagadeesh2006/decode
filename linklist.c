#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};
typedef struct node node;



node* front(node *head,node *new_node)
{
    new_node->next=head;
    head=new_node;
    return head;
}



node* end(node *head,node* new_node)
{
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    
}



node *between(node *head,int pos,node* new_node)
{
    node *temp;
    temp=head;
    for(int i=1;i<pos;i++)
    {
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}


node *dfront(node *head)
{
    node *temp=head;
    head=head->next;
    free(temp);
    return head;
}

node *dend(node *head)
{
    node *temp=head;
    node *pre;  
    while(temp->next!=NULL)
    {
        pre=temp;
        temp=temp->next;
    }
    pre->next=NULL;
    free(temp);
}



node *dpos(node *head,int pos)
{
    node *temp;
    node *next_node;
    temp=head;
    for(int i=1;i<pos;i++)
    {
        temp=temp->next;
    }
    next_node=temp->next;
    temp->next=next_node->next;
    free(next_node);
    
}




node* display(node *head)
{
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}




int main()
{
    int choice,insertion_choice,value,k,n,pos;
    node *head=NULL,*new_node,*temp;
    printf("The list is empty\n");
    printf("-------------------------------\n");
    printf("Enter the number of elements to be insert:  ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        new_node=(node*)malloc(sizeof(node));
        printf("Enter the element to be insert:  ");
        scanf("%d",&new_node->data);
        if(head==NULL)
        {
            head=new_node;
            temp=new_node;
        }
        else
        {
            temp->next=new_node;
            temp=new_node;
        }
        
    }
    printf("-------------------------------\n");
    display(head);
    printf("\n-------------------------------\n");
    printf("\n");
    do{
        printf("Select the operation:\n1.Insertion\n2.Deletion\n");
        printf("-------------------------------\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Select where to insert:\n1.insert at begining\n2.insert at end\n3.insert at position\n");
            printf("-------------------------------\n");
            scanf("%d",&insertion_choice);
            new_node=(node*)malloc(sizeof(node));
            printf("Enter the data to be insert: ");
            scanf("%d",&new_node->data);
            if(insertion_choice==1)
            {
            head=front(head,new_node);
            }
            else if(insertion_choice==2)
            {
            end(head,new_node);
            }
            else if(insertion_choice==3)
            {
            printf("Enter the position you want to insert: ");
            scanf("%d",&pos);
            between(head,pos,new_node);
            }
            printf("-------------------------------\n");
            display(head);
            printf("\n-------------------------------\n");
        }
        else if(choice==2)
        {
            printf("Select where to delete:\n1.delete at begining\n2.delete at end\n3.delete at position\n");
            printf("-------------------------------\n");
            int deletion_choice;
            scanf("%d",&deletion_choice);
            if(deletion_choice==1)
            {
                head=dfront(head);
            }
            else if(deletion_choice==2)
            {
                dend(head);
            }
            else if(deletion_choice==3)
            {
                printf("Enter the position you want to delete: ");
                scanf("%d",&pos);
                dpos(head,pos);
            }
            printf("-------------------------------\n");
            display(head);
            printf("\n-------------------------------\n");
            
        }
        printf("\nIf you want to continue insert again enter 1 Else 0: ");
        scanf("%d",&k);
    }while(k);
}
