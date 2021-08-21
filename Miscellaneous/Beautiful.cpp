#include<bits/stdc++.h>
using namespace std;
vector<long long int> finalPerm;
int dig(long long int n)
{
    int c=0;
    long long int t=n;
    while(t>0)
    {
        c++;
        t/=10;
    }
    return c;
}

void permute(string str)
{
    sort(str.begin(), str.end());
    do {
       stringstream geek(str);
        long long int x = 0;
        geek >> x;
        finalPerm.push_back(x);
    } while (next_permutation(str.begin(), str.end()));
}
int main()
{
    int n;
    cin>>n;
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(22);
    ans.push_back(333);
    ans.push_back(4444);
    ans.push_back(55555);
    ans.push_back(666666);
    ans.push_back(7777777);
    ans.push_back(88888888);
    ans.push_back(999999999);
    vector<long long int> perm;
    for(int i=1;i<(1<<5);i++)
    {
        long long int get=i;
        string s="";
        int pos=0;
        while(get>0)
        {
            if(get&1)
            {
                s+=to_string(ans[pos]);
            }
            pos++;
            get=get>>1;
        }
        stringstream geek(s);
        long long int x = 0;
        geek >> x;
        if(dig(x)<=12)
        {
            // perm.push_back(x);
            permute(s);
        }
    }
    sort(finalPerm.begin(), finalPerm.end());
    for(int i=0;i<finalPerm.size();i++)
    {
        if(finalPerm[i]>n)
        {
            cout<<finalPerm[i]<<"\n";
            break;
        }
    }
}