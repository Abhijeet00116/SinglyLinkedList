/* SINGLY LINKED LIST
	DELETION 
		-> FROM BEGINING
		-> FROM END
		-> THE ITEM
		-> AT POSTION
	INSERTION
		-> AT END
*/


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
void delete_beg()
{
	node *p;
	if(head==NULL)//means there is no node
	{
		printf("LINKED LIST IS EMPTY\n");
		return;
	}
	else//when some number of nodes already exist
	{
		p=head;
		head=p->next;
		printf("\ndeleted node info is : %d\n",p->info);
		free(p);
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

void delet_item(int item)//this function will delete the node if the item is found
{
	node *p1,*p2;//p2 points to the node which we want to delete
	//p1 is the node points to previous of p2
	for(p2=head;p2 &&p2->info!=item;p1=p2,p2=p2->next);//this loop search for the item, it will continue untill p2 is null or item is found
	if(p2==NULL)//when p2 become null & still item is not found
	{
		printf("%d is not found",item);

	}
	else if(p2==head)//item is found at head node
		head=p2->next;
	else//when item is found at any other node
		p1->next=p2->next;
	free(p2);//deallocate p2 node
}

void delet_pos(int pos)//this function will delete the node if the pos is found
{
	node *p1,*p2;
	//p2 points to the node which we want to delete
	//p1 is the node points to previous of p2
	int i=1;
	for(p2=head;p2 &&i<pos;p1=p2,p2=p2->next,i++);//loop will continue untill p2 points to the node, which is to be deleted
	if(p2==NULL)//when the pos is not found
		printf("%d position is not found",pos);
	else if(p2==head)//when we want to delete the head node
		head=p2->next;
	else//when any other node is to be deleted
		p1->next=p2->next;
	free(p2);
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
		printf("LINKED LIST IS EMPTY\n");
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
		printf("\n1.Insert at end");
		printf("\n2.Delete at beginning");
		printf("\n3.Delete at end");
		printf("\n4.Delete the item");
		printf("\n5.Delete at position");
		printf("\n6.Search");
		printf("\n7.DISPLAY");
		printf("\n8.exit");
		printf("\nENTER OPTION : ");
		scanf("%d",&op);

		switch(op)
		{
			case 1:printf("\nenter the item to inset: ");
					 scanf("%d",&item);
					 insert_end(item);
					 break;
					 
			case 2:delete_beg();
					 break;
					 
			case 3: delete_end();
					 break;
					 
			case 4: printf("\nenter the item to delete: ");
					 scanf("%d",&item);
					delet_item(item);
					 break;
					 
			case 5: printf("\nenter the position to delete:  ");
					 scanf("%d",&pos);
					delet_pos(pos);
					 break;
					 
			case 6:	 printf("\nenter item to search : ");
					 scanf("%d",&item);
					 pos=search(item);
					 if(pos==-1)
						printf("\n%d is not found",item);
					 else
						printf("\n%d is found at position %d",item,pos);
					 break;
					 
			case 7:display(); 
					break;
					
			case 8:exit(0);
			
			default:printf("\nINVALID OPTION");
		}
	};
}
