using namespace std;
#include<bits/stdc++.h>
int calc(int num,int arr[])
{
    if(num<1)
    {
        return 0;
    }
    if(arr[0]==0)
    {
        return -1;
    }
    int jump=1;
    int steps=arr[0];
    int maxReach=arr[0];
    for(int i=1;i<num;i++)
    {
        if(i==num-1)
        {
            return jump;
        }
        maxReach=max(arr[i]+i,maxReach);
        steps--;
        if(steps==0)
        {
            jump++;
            if(i>=maxReach)
            {
                return -1;
            }
            steps=maxReach-i;
        }
        
    }
    return -1;
}
int main()
{
    int num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    cout<<calc(num,arr)<<"\n";
}