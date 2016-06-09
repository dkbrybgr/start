#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
void detectLoop(struct node *head)
{
	struct node *slow=head,*fast=head;
	while(slow && fast && fast->next)
	{
		if(slow==fast)
		{
			cout<<"Loop found\n";
			return;
		}
		slow=slow->next;
		fast=fast->next->next;
	}
	cout<<"No loop\n"<<endl;
	return;
}
void push(struct node **head_ref,int new_data)
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next= *head_ref;
	*head_ref= new_node;
}
void insertAfter(struct node *prev_node,int new_data)
{
	if(prev_node==NULL)
	return;
	
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=prev_node->next;
	prev_node->next=new_node;
}
void append(struct node **head_ref,int new_data)
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=NULL;
	if(*head_ref==NULL)
	{
		*head_ref=new_node;
		return;
	}
	struct node *last=*head_ref;
	while(last->next!=NULL)
	last=last->next;
	
	last->next=new_node;
}
void printList(struct node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
  cout<<endl;
}
void reverseList(struct node** head_ref)
{
	struct node *prev=NULL,*current= *head_ref,*next;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	*head_ref=prev;
}
void reverseListRecursive(struct node** head_ref)
{
	struct node *first,*rest;
	
	if(*head_ref==NULL)
	return;
	
	first= *head_ref;
	rest=first->next;
	
	if(rest==NULL)
	return;
	
	reverseListRecursive(&rest);
	first->next->next=first;
	
	first->next=NULL;
	*head_ref=rest;
}
int main()
{
	struct node* head=NULL;
	append(&head, 6);
  	push(&head, 7);
  	push(&head, 1);
  	append(&head, 4);
  	insertAfter(head->next, 8);
  	printf("\n Created Linked list is: ");
  	printList(head);
  	reverseList(&head);
  	printList(head);
  	reverseListRecursive(&head);
  	printList(head);
}
