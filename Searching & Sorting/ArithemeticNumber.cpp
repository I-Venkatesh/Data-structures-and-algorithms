#include <bits/stdc++.h>
using namespace std;
int ans(int A, int B, int C)
{
    if (A == B)
    {
        return 1;
    }
    if (C != 0)
    {
        int rem = (B - A) % C;
        if (rem == 0 && ((B - A) < 0 && C < 0 || (B - A) > 0 && C > 0))
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    cout<<ans(A,B,C);
    return 0;
}