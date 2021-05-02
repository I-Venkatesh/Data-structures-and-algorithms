using namespace std;
#include<bits/stdc++.h>
int dpPrime[1000005];

int prime(int num)
{
    int div=2,c=0;
    vector<int> ans;
    int x=num;
    while(div<=num)
    {
        bool ok=true;
        if(dpPrime[num]!=-1)
        {
            return dpPrime[x]=dpPrime[num]+c;
        }
        while(num%div==0)
        {
            if(ok)
            {
                c++;
                ok=false;
            }
            num/=div;
        }
        div++;
    }
    return dpPrime[x]=c+1;
}
int main(){
    int test;
    cin>>test;
    memset(dpPrime,-1,sizeof(dpPrime));
    int dp[100005];
    for(int i=2;i<100001;i++)
    {
        dp[i]=prime(i);
    }
    while (test--)
    {
        int a,b,k;
        cin>>a>>b>>k;
        int ans=0;
        for(int i=a;i<=b;i++)
        {
            if(dp[i]==k)
            {
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    
}