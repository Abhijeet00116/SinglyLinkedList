/* SINGLY LINKED LIST
	INSERTION 
		-> AT BEGINING
		-> AT END
		-> BY SORTING
		-> AT POSTION
	DELETION
		-> FROM END
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

void insert_beg(int item)
{
	node *nw;//nw is the new node
	nw=(node*)malloc(sizeof(node));//allocate memory for nw dynamically
	nw->info=item;//data
	nw->next=NULL;//initially next is null

	if(head==NULL)//when there is no node in the linked list
		head=nw;//nw node become the head
	else//when there are some nodes already exist
	{
		nw->next=head;
		head=nw;//now the nw node become the head
	}
}
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
void insert_sort(int item)
{
	node *nw,*p1,*p2;
	nw=(node*)malloc(sizeof(node));
	nw->info=item;
	nw->next=NULL;
	
	if(head==NULL)//if there is no node in the linked list
		head=nw;//then the nw node becomes the head
	else//if some nodes already exist
	{
		for(p2=head;p2!=NULL && nw->info>p2->info;p1=p2,p2=p2->next);//initially p2 points to head & 
		//move forward untill p2 becomes NULL & p1 points to previous node of p2
		if(p2==head)
		{
			nw->next=p2;
			head=nw;
		}
		else
		{
			p1->next=nw;
			nw->next=p2;
		}
	}
}
void insert_pos(int item, int pos)
{
	node *nw;//nw is the new node
	node *p;
	int i;
	nw=(node*)malloc(sizeof(node));//allocate memory for nw dynamically
	nw->info=item;//data
	nw->next=NULL;//initially next is null
	
	if(pos==1)//when we are inserting at begin
	{
		nw->next=head;
		head=nw;//the new node become head
		return;
	}
	
	for(p=head,i=1;i<pos-1 && p!=NULL;i++,p=p->next);//here p will move to the previos node of pos
		
	if(p==NULL)//when pos no is more than no of nodes
		printf("there are less than %d positions\n",pos);
	else
	{
		nw->next=p->next;
		p->next=nw;
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
		printf("\n1.Insert at beginning");
		printf("\n2.Insert at end");
		printf("\n3.Insert Sort");
		printf("\n4.insert at pos");
		printf("\n5.Delete from end");
		printf("\n7.Search");
		printf("\n8.DISPLAY");
		printf("\n9.exit");
		printf("\nENTER OPTION : ");
		scanf("%d",&op);

		switch(op)
		{
			case 1:printf("\nenter the item to insert: ");
					 scanf("%d",&item);
					 insert_beg(item);
					 break;
					 
			case 2:printf("\nenter the item to insert: ");
					 scanf("%d",&item);
					 insert_end(item);
					 break;
					 
			case 3:	printf("\nenter the item to insert: ");
					 scanf("%d",&item);
					 insert_sort(item);
					 break;
					 
			case 4:	 printf("\nenter the item to insert: ");
					 scanf("%d",&item);
					 printf("\nenter the position to insert:  ");
					 scanf("%d",&pos);
					 insert_pos(item,pos);
					 break;
					 
			case 5: delete_end();
					 break;
					 
			case 6:	printf("\nenter item to search : ");
					 scanf("%d",&item);
					 pos=search(item);
					 if(pos==-1)
						printf("\n%d is not found",item);
					 else
						printf("\n%d is found at position %d",item,pos);
					 break;
					 
			case 7:	display(); 
					break;
					
			case 8:	exit(0);
			
			default:	printf("\nINVALID OPTION...");
		}
	};
}
