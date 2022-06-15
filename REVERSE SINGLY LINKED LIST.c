#include<stdio.h>
#include<stdlib.h>
 
typedef struct node
{
        int data;
        struct node *next;
}node;
 
node* insert_at_end(int n)
{
    node *head,*P;
    int i;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    printf("->");
    scanf("%d",&(head->data));
    P=head;
 
    //create subsequent nodes
    for(i=1;i<n;i++)
    {
        P->next=(node*)malloc(sizeof(node));
        //new node is inserted as the next node after P
	        P=P->next;
	        printf("->");
	        scanf("%d",&(P->data));
	        P->next=NULL;
    }
    return(head);
}
 

 
node *reverse_LL(node *head) 
{
	node *Prev,*current,*temp;
	 
	Prev=NULL;
	current=head;
	temp=current->next;
	 
	
		while(current!=NULL)
		{
			current->next=Prev;
			Prev=current;
			current=temp;
			 
			if(temp!=NULL)
				temp=temp->next;
		}
 
	return(Prev);
}
    
int main(void)
{
	
	node *head,*P;
    int n;
    printf("How many no. of nodes? -:" );	scanf("%d",&n);
    printf("Enter all nodes-: \n");
 
    head=insert_at_end(n);     
    
	printf("\nOriginal Linked List: ");		display_LL(head);
 
    P=reverse_LL(head);
    
	printf("\nReversed Linked List:");		display_LL(P);
 
    return 0;
}
 
