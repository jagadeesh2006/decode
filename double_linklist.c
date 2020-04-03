#include<stdio.h>
#include <stdlib.h>

//creating node datatype

struct node
{
    int data;
    struct node* next;
    struct node* pre;
};
typedef struct node node;

//insert node at begining

node* front(node* head,node* new_node)
{
	head->pre=new_node;
	new_node->next=head;
	head=new_node;
	return(head);
}

//insert node at end

node* end(node* tail,node* new_node)
{
	tail->next=new_node;
	new_node->pre=tail;
	tail=new_node;
}

//insert node at position

node *between(node *head,int pos,node* new_node)
{
    node *temp;
    temp=head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    new_node->next=temp->next;
    new_node->pre=temp;
    temp->next=new_node;
    new_node->next->pre=new_node;
}

//delete node at begining

node *dfront(node *head)
{
    node *temp=head;
    head=head->next;
    head->pre=NULL;
    free(temp);
    return head;
}

//delete node at end

node *dend(node *tail)
{
    node *temp=tail;
    tail=temp->pre;  
    tail->next=NULL;
    free(temp);
}

//delete node at position

node *dpos(node *head,int pos)
{
    node *temp;
    temp=head;
    for(int i=1;i<pos;i++)
    {
        temp=temp->next;
    }
    temp->pre->next=temp->next;
    free(temp);
    
}

//display the list

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
	int n,value,choice,insertion_choice,pos,k;
	node* new_node,*head=NULL,*tail=NULL;
	printf("The list is empty\nEnter the number of data to be inserted : ");
	scanf("%d",&n);
	
	//creating double linked list

	for(int i=0;i<n;i++)
	{
		printf("enter the data: ");
		new_node=(node*)malloc(sizeof(node));
		scanf("%d",&new_node->data);
		if(head==NULL)
		{
			head=new_node;
			tail=new_node;
		}
		else
		{
			tail->next=new_node;
			new_node->pre=tail;
			tail=new_node;
		}
	}
	printf("\n-------------------------------\n");
	display(head);
	printf("\n-------------------------------\n");
   do{
	printf("\nEnter the operation going to perform:\n1.insertion\n2.deletion\n");
	printf("-------------------------------\n");
	scanf("%d",&choice);
	
	//insertion

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
                 end(tail,new_node);
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
	
	//delection

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
                dend(tail);
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
		
		
