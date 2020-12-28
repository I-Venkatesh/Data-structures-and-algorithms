#include <bits/stdc++.h>
using namespace std;
int wordBreak(string A, vector<string> &B) {
    //code here
    for(int i=0;i<B.size();i++)
    {
        string s=B[i];
        int c=0;
        map<string,int> mp;
        mp[A]=1;
        for(int i=0;i<A.size();i++)
        {
            string temp="";
            for(int j=i;j<A.size();j++)
            {
                temp+=A[j];
                // cout<<temp<<"\n";
                mp[temp]++;
            }
        }
        int size=A.size();
        for(int i=0;i<B.size();i++)
        {
            if(mp[B[i]]>0)
            {
                c+=B[i].size()*mp[B[i]];
            }
            if(c>=size)
            {
                return 1;
            }
        }
        if(c>=size)
        {
            return 1;
        }
    }
    return 0;
}
int main() {
   int t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   while(t--)
   {
        int num;
        cin>>num;
        vector<string> B;
        for(int i=0;i<num;i++)
        {
            string s;
            cin>>s;
            B.push_back(s);
        }
        string A;
        cin>>A;
        cout<<wordBreak(A,B);
   }
   return 0;
}