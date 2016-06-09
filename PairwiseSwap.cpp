#include<bits/stdc++.h>
using namespace std;
void swapData(int *a,int *b);
struct node
{
	int data;
	struct node* next;
};
void printlist(struct node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
void push(struct node **head_ref,int new_data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=*head_ref;
	*head_ref=new_node;
}
void pairSwap(struct node *head)
{
	struct node *temp=head;
	while(temp!=NULL && temp->next!=NULL)
	{
		swapData(&(temp->data),&(temp->next->data));
		
		temp=temp->next->next;
	}
}
void swapData(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	struct node* head=NULL;
	push(&head,5);
	push(&head,2);
	push(&head,1);
	push(&head,4);
	push(&head,3);
	printlist(head);
	
	pairSwap(head);
	printlist(head);
	
}
