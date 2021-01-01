#include <bits/stdc++.h>
using namespace std;
vector<int> findTwoElement(int *arr, int n)
{
    // code here
    int xorAll = 1;
    for (int i = 2; i <= n; i++)
    {
        xorAll ^= i;
    }
    for (int i = 0; i < n; i++)
    {
        xorAll ^= arr[i];
    }
    int set_bit_no = xorAll & ~(xorAll - 1);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & set_bit_no)
        {
            x ^= arr[i];
        }
        else
        {
            y ^= arr[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i & set_bit_no)
        {
            x ^= i;
        }
        else
        {
            y ^= i;
        }
    }

    vector<int> res;
    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            ok = true;
        }
    }
    if (ok)
    {
        res.push_back(x);
        res.push_back(y);
    }
    else
    {
        res.push_back(y);
        res.push_back(x);
    }
    return res;
}
int main()
{
    int num;
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans=findTwoElement(arr,num);
    cout<<ans[0]<<" "<<ans[1]<<"\n";

    return 0;
}