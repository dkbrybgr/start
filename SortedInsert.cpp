#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
void append(struct node **head_ref,int new_data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=NULL;
	
	
	if(*head_ref==NULL)
	{
		*head_ref=new_node;
		return;
	}
	struct node* last=*head_ref;
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=new_node;
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
void SortedInsert(struct node**head_ref,int new_data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data =new_data;
	struct node *prev=NULL,*temp=*head_ref;
	if(temp==NULL||temp->data>new_data)
	{
		new_node->next=temp;
		*head_ref=new_node;
		return;
	 }
	 
	 while(temp!=NULL && temp->data<=new_data)
	 {
	 	prev=temp;
	 	temp=temp->next;
	  }
	  new_node->next=prev->next;
	  prev->next=new_node;
	  return; 
}
int main()
{
	struct node* head=NULL;
	SortedInsert(&head,2);
	printlist(head);
	SortedInsert(&head,1);
	printlist(head);
	append(&head,4);
	printlist(head);
	SortedInsert(&head,6);
	printlist(head);
	SortedInsert(&head,3);
	printlist(head);
	SortedInsert(&head,1);
	printlist(head);
}


