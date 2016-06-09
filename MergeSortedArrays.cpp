#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
void MoveNode(struct node **destRef,struct node **sourceRef);
void push(struct node **head_ref,int new_data)
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=*head_ref;
	*head_ref=new_node;
}
struct node* IterativeSortedMerge(struct node* a,struct node *b)
{
	struct node dummy;
	
	struct node *tail=&dummy;
	dummy.next=NULL;
	while(1)
	{
		if(a==NULL)
		{
			tail->next=b;
			break;
		}
		else if(b==NULL)
		{
			tail->next=a;
			break;
		}
		if(a->data<=b->data)
		{
			MoveNode(&(tail->next),&a);
		}
		else
		{
			MoveNode(&(tail->next),&b);
		}
		tail=tail->next;
	 }
	 return dummy.next; 
}
void MoveNode(struct node **destRef,struct node **sourceRef)
{
	struct node* new_node=*sourceRef;
	
	*sourceRef=new_node->next;
	
	new_node->next=*destRef;
	*destRef=new_node;
}
void printList(struct node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<"\n";
	return;
}
struct node* RecursiveSortedMerge(struct node* a, struct node* b) 
{
  struct node* result = NULL;
 
  if (a == NULL) 
     return(b);
  else if (b==NULL) 
     return(a);
     
  if (a->data <= b->data) 
  {
     result = a;
     result->next = RecursiveSortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = RecursiveSortedMerge(a, b->next);
  }
  return(result);
}
int main()
{
	struct node *a=NULL,*b=NULL;
	struct node* result2;
	push(&a,9);
	push(&a,2);
	push(&b,11);
	push(&b,1);
	printList(a);
	printList(b);
	struct node* c=NULL;
	push(&c,4);
	push(&c,3);
	
	printList(c);
	struct node *result=IterativeSortedMerge(a,b);
	printList(result);
	printList(a);
	printList(b);
	result2=RecursiveSortedMerge(result,c);
	printList(result2);
	
}
