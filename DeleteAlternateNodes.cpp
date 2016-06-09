#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
void push(struct node** head_ref,int new_data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=*head_ref;
	*head_ref=new_node;
}
void printlist(struct node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
void delAlternate(struct node** head_ref)
{
	struct node* temp=*head_ref;
	if(*head_ref==NULL || temp->next==NULL )
	return;
	
	struct node* next_ptr;
	while(temp!=NULL && temp->next!=NULL)
	{
		next_ptr=temp->next->next;
		temp->next=next_ptr;
		if(next_ptr!=NULL)
		temp=next_ptr;
	}
}
int main()
{
	struct node* head=NULL;
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	push(&head,0);
	printlist(head);
	
	delAlternate(&head);
	printlist(head);
	delAlternate(&head);
	printlist(head);
	delAlternate(&head);
	printlist(head);
	delAlternate(&head);
	printlist(head);
}
