#include <bits/stdc++.h>
using namespace std;
class Node 
{ 
	public:
	int data; 
	Node *next; 
	Node *prev; 
}; 

void reverse(Node **head_ref) 
{ 
	Node* ptr1=*head_ref;
    Node* ptr2=ptr1->next;
     
    ptr1->next=NULL;
    ptr1->prev=ptr2;
    while(ptr2!=NULL)
    {
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    *head_ref=ptr1;
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
	push(&head, 2); 
	push(&head, 4); 
	push(&head, 8); 
	push(&head, 10); 
	
	cout << "Original Linked list" << endl; 
	printList(head); 
	reverse(&head); 
	
	cout << "\nReversed Linked list" << endl; 
	printList(head);		 
	
	return 0;
} 
