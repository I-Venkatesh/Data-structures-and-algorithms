#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    test = 1;
    while (test--)
    {
        int n;
        cin >> n;
        vector<long long int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        long long int prod = 1, c = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                c++;
                continue;
            }
            prod *= nums[i];
        }
        vector<long long int> ans;
        if (c > 0)
        {
            if (c == 1)
            {
                for (int i = 0; i < n; i++)
                {
                    if (nums[i] != 0)
                    {
                        ans.push_back(0);
                    }
                    else
                    {
                        ans.push_back(prod);
                    }
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    ans.push_back(0);
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                ans.push_back(prod / nums[i]);
            }
        }
        for(auto i:ans)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}