#include <bits/stdc++.h>
using namespace std;
int maxSubstring(string S)
{
    // Your code goes here
    int z = 0, maxi = 0;
    for (int i = 0; i < S.length(); i++)
    {
        if (z >= 0)
        {
            if (S[i] == '0')
            {
                z++;
            }
            else
            {
                if (z > 0)
                {
                    z--;
                }
            }
        }
        //cout<<z<<"\n";
        maxi = max(maxi, z);
    }
    if (maxi == 0)
    {
        return -1;
    }
    return maxi;
}
int main()
{
    string s;
    cin>>s;
    cout<<maxSubstring(s)<<"\n";
    return 0;
}