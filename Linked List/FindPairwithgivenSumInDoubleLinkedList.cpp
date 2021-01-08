#include <bits/stdc++.h>
using namespace std;
class Node 
{ 
	public:
	int data; 
	Node *next; 
	Node *prev; 
}; 

void sum(Node *head_ref,int sum) 
{ 
	Node* first=head_ref,*last=head_ref;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    while(first->data<last->data)
    { 
        if(last->data+first->data>sum)
        {
            last=last->prev;
        }
        else if(last->data+first->data<sum)
        {
            first=first->next;
        }
        else{
            cout<<last->data<<" "<<first->data<<"\n";
            last=last->prev;
        }
    }

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
void printList(Node *node) 
{ 
	while(node != NULL) 
	{ 
		cout << node->data << " "; 
		node = node->next; 
	} 
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
	// printList(head);
    sum(head,7); 
			 
	
	return 0;
} 
