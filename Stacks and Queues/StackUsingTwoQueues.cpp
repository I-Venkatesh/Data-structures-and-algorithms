using namespace std;
#include<bits/stdc++.h>
void QueueStack :: push(int x)
{
    q1.push(x);
}

int QueueStack :: pop()
{
        int ans=-1;
        if(q1.size()>0)
        {
            while(q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            ans=q1.front();
        }
        if(q1.size()>0)
        {
            q1.pop();
        }
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
}
