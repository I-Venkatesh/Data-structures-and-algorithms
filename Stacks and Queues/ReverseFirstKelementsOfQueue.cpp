using namespace std;
#include<bits/stdc++.h>
queue<int> modifyQueue(queue<int> &q, int k)
{
    stack<int> st,st2;
    queue<int> q2;
    while(k>0)
    {
        k--;
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q2.push(st.top());
        st.pop();
    }
    while(!q.empty())
    {
        q2.push(q.front());
        q.pop();
    }
    return q2;
}
int main()
{
    int num,k;
    cin>>num>>k;
    queue<int> q;
    for(int i=0;i<num;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    queue<int> s=modifyQueue(q,k);
    while(!s.empty())
    {
        cout<<s.front()<<" ";
        s.pop();
    }
    cout<<"\n";
}
