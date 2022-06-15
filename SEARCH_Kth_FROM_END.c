#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
	int info;//DATA
	struct node *next;//self-reference, it can cotain address of next node
}node;

node *head=NULL;//initially head is null, i.e no node in the linked list
void insert_end(int item)
{
	node *nw;//nw is the new node
	nw=(node*)malloc(sizeof(node));//allocate memory for nw dynamically
	nw->info=item;//data
	nw->next=NULL;//initially next is null
	node *ptr;
	
	if(head==NULL)//when there is no node in the linked list
		head=nw;//nw node become the head
	else//when there are some nodes already exist
	{
		for(ptr=head;ptr->next!=NULL;ptr=ptr->next);//ptr will move from first node to last node
		ptr->next=nw;
	}
}

void delete_end()
{
		node *p1,*p2;//p2 points to the last node
	//p1 is the node points to previous of p2
	if(head==NULL)//means there is no node
	{
		printf("LINKED LIST IS EMPTY\n");
		return;
	}
	else
	{
		for(p2=head;p2->next;p1=p2,p2=p2->next);//this loop will continue untill p2 points to last node 
		if(p2==head)//if there is only one node in linked list
			head=p2->next;
		else//when more than one node is present in the linked list
			p1->next=p2->next;
			
		printf("\ndeleted node info is : %d\n",p2->info);
		free(p2);//deallocate p2 node
	}
	
}
void SearchKthFromtheEnd(int k)
{
  node *temp = head;
  int n = 0,i;
// Count number of nodes in the linked list
  while (temp)
    {
      temp = temp->next;
      n++;
    }
// if number of nodes is more than or equal to K
  if (n >= k)
    {// return (n-k+1)th node from the beginning
      temp = head;
      for (i = 0; i < n - k; i++) temp = temp->next;
    }

   printf("\n%dth element is -: %d\n",k,temp->info);
}
int search(int item)
{
	int pos;
	node *ptr;
	for(ptr=head,pos=1;ptr;ptr=ptr->next,pos++)
		if(ptr->info==item)
			return pos;//if the item is found it return the pos of item
	return -1;//if the item is not found
}
void display()
{
	node *ptr;//
	if(head==NULL)//means there is no node
	{
		printf("\nLINKED LIST IS EMPTY\n");
		return;
	}
	else//when there are some nodes already exist
	{
		for(ptr=head;ptr!=NULL;ptr=ptr->next)
			printf("%d\t",ptr->info);
	}
}
void main()
{
	int op,item;
	int pos;
	while(1)
	{
			printf("\n1.Insert at End");
			printf("\n2.Search Kth Element from end");
			printf("\n3.Delete from End");
			printf("\n4.Search Position");
			printf("\n5.DISPLAY All");
			printf("\n6.EXIT");
			printf("\nENTER OPTION : ");
			scanf("%d",&op);
			
			switch(op)
		{
			case 1:printf("\nenter the item to insert-: ");
					 scanf("%d",&item);
					 insert_end(item);
					 break;
					 
			case 2: printf("\nenter the K to search-: ");
					 scanf("%d",&item);
					 SearchKthFromtheEnd(item);
					 break;
					 
			case 3:	delete_end();
					 break;
					 
			case 4:	printf("\nenter item to search -: ");
					 scanf("%d",&item);
					 pos=search(item);
					 if(pos==-1)
						printf("\n%d is not found",item);
					 else
						printf("\n%d is found at position -: %d",item,pos);
					 break;
					 
			case 5:	display(); 
					break;
					
			case 6:	exit(0);
			
			default:	printf("\nINVALID OPTION...\n");
		}
	};
}
					 
					 
