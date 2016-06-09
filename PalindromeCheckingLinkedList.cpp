#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
bool compareLists(struct node* head1, struct node *head2);
void append(struct node** head_ref,int new_data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=NULL;
	if(*head_ref==NULL)
	{
		*head_ref=new_node;
		return;
	}
	struct node* temp=*head_ref;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new_node;
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
void RecursiveReverse(struct node** head_ref)
{
	struct node* first;
	struct node* rest;
	
	if(*head_ref==NULL)
	return;
	
	first=*head_ref;
	rest=first->next;
	
	if(rest==NULL)
	return;
	
	RecursiveReverse(&rest);
	first->next->next=first;
	
	first->next=NULL;
	*head_ref=rest;	
}
bool isPalin(struct node* head)
{
	struct node *slow_ptr=head,*fast_ptr=head,*prev_slow=head,*second_half,*midnode=NULL;
	bool res=true;
	
	if(head!=NULL && head->next!=NULL)
	{
		while(fast_ptr!=NULL && fast_ptr->next!=NULL)
		{
			fast_ptr=fast_ptr->next->next;
			
			prev_slow=slow_ptr;
			slow_ptr=slow_ptr->next;
		}
	
	
	if(fast_ptr!=NULL)
	{
		midnode=slow_ptr;
		slow_ptr=slow_ptr->next;
	}
	
	second_half=slow_ptr;
	prev_slow->next=NULL;
	RecursiveReverse(&second_half);
	printlist(second_half);
	res=compareLists(head,second_half);
	
	RecursiveReverse(&second_half);
	
	if(midnode!=NULL)
	{
		prev_slow->next=midnode;
		midnode->next=second_half;
	}
	else
	prev_slow->next=second_half;
	
	
	}
	return res;
	
}
bool compareLists(struct node* head1, struct node *head2)
{
    struct node* temp1 = head1;
    struct node* temp2 = head2;
 
    while (temp1 && temp2)
    {
    	cout<<temp1->data<<"\t"<<temp2->data<<endl;
        if (temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else return 0;
    }
 
    
    if (temp1 == NULL && temp2 == NULL)
        return 1;
 
    return 0;
}
int main()
{
	struct node* head=NULL;
	append(&head,1);
	append(&head,2);
	append(&head,3);
	append(&head,2);
	append(&head,1);
	printlist(head);
	RecursiveReverse(&head);
	printlist(head);
	RecursiveReverse(&head);
	printlist(head);
	
	cout<<isPalin(head)<<endl;
	
}
