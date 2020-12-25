#include <bits/stdc++.h>
using namespace std;
bool pal(string s)
{
    int size = s.size();
    if (size % 2 == 0)
    {
        size = (size / 2) - 1;
    }
    else
    {
        size = size / 2;
    }
    for (int i = 0; i <= size; i++)
    {
        if (s[i] != s[s.size() - i - 1])
        {
            return 0;
        }
    }
    return 1;
}
int PalinArray(int a[], int n)
{ //add code here.
    for (int i = 0; i < n; i++)
    {
        string num = "";
        int x = a[i];
        while (x > 0)
        {
            int rem = x % 10;
            if(rem==0)
            {
                num+='0';
            }
            else if (rem == 1)
            {
                num += '1';
            }
            else if (rem == 2)
            {
                num += '2';
            }
            else if (rem == 3)
            {
                num += '3';
            }
            else if (rem == 4)
            {
                num += '4';
            }
            else if (rem == 5)
            {
                num += '5';
            }
            else if (rem == 6)
            {
                num += '6';
            }
            else if (rem == 7)
            {
                num += '7';
            }
            else if (rem == 8)
            {
                num += '8';
            }
            else if (rem == 9)
            {
                num += '9';
            }
            x /= 10;
        }
        if (!pal(num))
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    //code
    int test;
    test = 1;
    while (test--)
    {
        int num;
        cin >> num;
        int arr[num];
        for (int i = 0; i < num; i++)
        {
            cin >> arr[i];
        }
        if(PalinArray(arr, num))
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
        // cout<<pal("20");
    }
    return 0;
}