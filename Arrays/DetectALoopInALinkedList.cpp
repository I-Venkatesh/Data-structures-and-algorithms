using namespace std;
#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define INFINITE 1e9 + 5
#define MOD 1000000007
#define MAXN 100001 
#define pll pair<ll,ll>
#define pii pair<int,int>
#define debugArray(arr) cout << #arr<<" : "<<endl;for(int i : arr){cout << i <<", ";} cout <<endl;
#define debugVariable(x) cout <<#x<<"="<<x<<"\n";
#define check(x) cout<<"CHECK="<<#x<<"\n";
priority_queue<int, vector<int>, greater<int>> pq; //increasing priority queue
int X[4]={1,0,-1,0};
int Y[4]={0,1,0,-1};
class Node{
    public:
    int data;
    Node* next;
};
void push(Node** head_ref,int new_data)
{
    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}
int detect(Node* list)
{
    Node* slow=list,*fast=list;
    while(slow&&fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);
    Node* head=NULL;
    push(&head,20);
    push(&head,30);
    push(&head,40);
    push(&head,50);
    head->next->next->next->next=head;
    if(detect(head))
    {
        cout<<"Loop found";
    }
    else
    {
        cout<<"Loop not found";
    }
    
}