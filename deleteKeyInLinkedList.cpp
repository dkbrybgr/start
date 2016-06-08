#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
void delKey(struct node **head_ref,int key)
{
	if(*head_ref==NULL)
	return;
	
	struct node* temp = *head_ref;
	if(temp->data==key)
	{
		*head_ref=temp->next;
		delete temp;
		return;
	}
	
	struct node *prev;
	while(temp!=NULL && temp->data!=key)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		cout<<"key not found"<<endl;
		return;
	}
	
	prev->next=temp->next;
	delete temp;
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
  	cout<<endl;
  	delKey(&head,1);
  	printList(head);
  	cout<<endl;
  	delKey(&head,5);
  	printList(head);
  	cout<<endl;
  	delKey(&head,6);
  	printList(head);
  	cout<<endl;
}
