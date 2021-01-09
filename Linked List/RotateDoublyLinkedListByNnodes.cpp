#include <bits/stdc++.h>
using namespace std;
class Node 
{ 
	public:
	int data; 
	Node *next; 
	Node *prev; 
}; 
void printList(Node *node) 
{ 
	while(node != NULL) 
	{ 
		cout << node->data << " "; 
		node = node->next; 
	} 
} 

void rotate(Node* head_ref,int n,int tot) 
{ 
	int rot=tot-n;
    Node* temp=head_ref;
    Node* p=NULL;
    while(rot>0)
    {
        p=temp;
        temp=temp->next;
        rot--;
    }
    Node* cut=p->next ;
    p->next=NULL;
    Node* x=cut;
    while(x->next!=NULL)
    {
        x=x->next;
    }
    x->next=head_ref;
    head_ref=cut;
    printList(head_ref);
}

void push(Node** head_ref, int new_data) 
{ 
	Node* new_node = new Node();
	new_node->data = new_data; 
	new_node->prev = NULL; 
	new_node->next = (*head_ref);	 
	if((*head_ref) != NULL) 
	(*head_ref)->prev = new_node ; 
	(*head_ref) = new_node; 
} 

int main() 
{ 
	Node* head = NULL; 
    push(&head, 9); 
	push(&head, 8); 
	push(&head, 6); 
	push(&head, 5);
	push(&head, 4); 
	push(&head, 2); 
	push(&head, 1); 
	printList(head);
    cout<<"\n";
    rotate(head,5,7);
	return 0;
} 
