using namespace std;
#include<bits/stdc++.h>
int main()
{
    int num;
    cin>>num;
    queue<int> q;
    for(int i=0;i<num;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    stack<int> st;
    for(int i=0;i<num/2;i++)
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    for(int i=0;i<num/2;i++)
    {
        q.push(q.front());
        q.pop();
    }
    for(int i=0;i<num/2;i++)
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}
