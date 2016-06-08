#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
void append(struct node **head_ref,int new_data)
{
	struct node * new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = NULL;
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
void delPos(struct node **head_ref,int position)
{
	if(*head_ref==NULL)
	return;
	
	struct node* temp=*head_ref;
	if(position==0)
	{
		*head_ref=temp->next;
		delete temp;
		return ;
	}
	
	for(int i=0;temp!=NULL && i<position-1;i++)
	temp=temp->next;
	
	if(temp==NULL || temp->next==NULL)
	return;
	
	struct node *nodeafterposition=temp->next->next;
	delete temp->next;
	temp->next=nodeafterposition;
	return;
}
void printlist(struct node *node)
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
	append(&head,5);
	append(&head,4);
	append(&head,3);
	printlist(head);
	cout<<endl;
	append(&head,2);
	append(&head,1);
	printlist(head);
	cout<<endl;
	delPos(&head,7);
	printlist(head);
	cout<<endl;
	delPos(&head,1);
	printlist(head);
	cout<<endl;
	delPos(&head,3);
	printlist(head);
	cout<<endl;
	delPos(&head,0);
	printlist(head);
	cout<<endl;
}
