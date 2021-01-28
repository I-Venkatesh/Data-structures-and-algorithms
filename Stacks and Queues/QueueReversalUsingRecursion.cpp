using namespace std;
#include<bits/stdc++.h>
void reve(queue<int> &q)
{
    if(q.empty())
    {
        return;
    }
    int temp=q.front();
    q.pop();
    reve(q);
    q.push(temp);
}
queue<int> rev(queue<int> q)
{
    reve(q);
    return q;
}
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
    rev(q);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<"\n";
}