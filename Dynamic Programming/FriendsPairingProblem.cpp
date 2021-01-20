using namespace std;
#include <bits/stdc++.h>
int countFriendsPairings(int n)
{
    long long int a = 1;
    long long int b = 2;
    long long int c = 0;
    if (n <= 2)
    {
        return n;
    }
    for (int i = 3; i <= n; i++)
    {
        c = (b + a * (i - 1)) % 1000000007;
        a = b;
        b = c;
    }
    return c;
}
int main()
{
    cout<<countFriendsPairings(10)<<"\n";
}