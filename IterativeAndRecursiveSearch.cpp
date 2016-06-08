#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
void push(struct node **head_ref,int new_data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	
	new_node->next= *head_ref;
	*head_ref= new_node;
}
void delKey(struct node **head_ref,int key)
{
	if(*head_ref==NULL)
	return;
	struct node* temp=*head_ref;
	if(temp!=NULL && temp->data==key)
	{
		*head_ref=temp->next;
		return;
	}
	
	struct node* prev;
	while(temp!=NULL && temp->data!=key)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		cout<<"no such element to delete\n";
		return;
	}
	
	prev->next=temp->next;
	delete temp;
}
void printList(struct node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}
 
bool search(struct node* head,int key)
{
	while(head!=NULL && head->data!=key)
	head=head->next;
	if(head==NULL)
	return false;
	else 
	return true;
}
bool recSearch(struct node *head,int key)
{
	if(head==NULL)
	return false;
	
	if(head->data==key)
	return true;
	else
	return recSearch(head->next,key);
	
}
void swapWithoutSwappingData(struct node** head_ref,int x,int y)
{
	if(x==y)
	return;
	
	struct node *prevx=NULL,*currx= *head_ref;
	struct node *prevy=NULL,*curry= *head_ref;
	
	while(currx!=NULL && currx->data!=x)
	{
		prevx=currx;
		currx=currx->next;
	}
	
	while(curry!=NULL && curry->data!=y)
	{
		prevy=curry;
		curry=curry->next;
	}
	
	if(currx==NULL||curry==NULL)
	return;
	
	if(prevx==NULL)
	*head_ref=curry;
	else
	prevx->next=curry;
	
	if(prevy==NULL)
	*head_ref=currx;
	else
	prevy->next=currx;
	
	struct node* temp=curry->next;
	curry->next=currx->next;
	currx->next=temp;
}
int main()
{
	struct node* head=NULL;
	push(&head,1);
	push(&head,0);
	printList(head);
	cout<<endl;
	cout<<search(head,2)<<endl;
	cout<<search(head,1)<<endl;
	cout<<search(head,0)<<endl;
	printList(head);
	cout<<endl;
	delKey(&head,0);
	cout<<search(head,0)<<endl;
	cout<<recSearch(head,1)<<endl;
	push(&head,5);
	push(&head,2);
	push(&head,9);
	printList(head);
	cout<<endl;
	swapWithoutSwappingData(&head,1,2);
	printList(head);
	cout<<endl;
}
