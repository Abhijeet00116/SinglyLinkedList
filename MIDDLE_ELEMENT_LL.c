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
void search_mid()     //Function found the middle element in the linked list
{
    node *first_ptr = head;
    node *second_ptr = head;
 
    if (head!=NULL)
    {
        /*the only logic is to traverse the linked list with two pointers
	        one at normal speed and other twice the speed of first
	        when the fast pointer reaches to the end, slow pointer will be in 
	        the middle of the linted list*/
        while (second_ptr != NULL && second_ptr->next != NULL)
        {
            second_ptr = second_ptr->next->next;
            first_ptr = first_ptr->next;
        }
        printf("The middle element in the linked list is:- %d", first_ptr->info);
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
			printf("\n1.Insert at end");
			printf("\n2.Delete from end");
			printf("\n3.Search Middle Element");
			printf("\n4.Search");
			printf("\n5.DISPLAY");
			printf("\n6.exit");
			printf("\nENTER OPTION : ");
			scanf("%d",&op);
			
			switch(op)
		{
			case 1:printf("\nenter the item to insert: ");
					 scanf("%d",&item);
					 insert_end(item);
					 break;
					 
			case 2: delete_end();
					 break;
					 
			case 3:	search_mid();
					 break;
					 
			case 4:	printf("\nenter item to search : ");
					 scanf("%d",&item);
					 pos=search(item);
					 if(pos==-1)
						printf("\n%d is not found",item);
					 else
						printf("\n%d is found at position %d",item,pos);
					 break;
					 
			case 5:	display(); 
					break;
					
			case 6:	exit(0);
			
			default:	printf("\nINVALID OPTION...\n");
		}
	};
}
					 
					 
