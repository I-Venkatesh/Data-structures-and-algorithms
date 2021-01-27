using namespace std;
#include<bits/stdc++.h>
stack<int> st;
void insertAtBottom(int x)
{
    if(st.empty())
    {
        st.push(x);
        return;
    }
    int hold=st.top();
    st.pop();
    insertAtBottom(x);
    st.push(hold);
}
void reverseStack()
{
    if(st.empty())
    {
        return;
    }
    int temp=st.top();
    st.pop();
    reverseStack();
    insertAtBottom(temp);
}
int main()
{
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        int x;
        cin>>x;
        st.push(x);
    }
    reverseStack();
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}