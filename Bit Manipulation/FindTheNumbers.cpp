using namespace std;
#include <bits/stdc++.h>
int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x = x ^ nums[i];
    }
    int a = 0, b = 0;
    int ith = 0;
    int temp = x;
    int c = 0;
    while (temp)
    {
        if (temp & 1)
        {
            ith = c;
            break;
        }
        temp = temp >> 1;
        c++;
    }
    for (int i = 0; i < n; i++)
    {
        if ((nums[i] >> ith) & 1)
        {
            a = a ^ nums[i];
        }
        else
        {
            b = b ^ nums[i];
        }
    }
    cout<<a<<" "<<b<<"\n";
}