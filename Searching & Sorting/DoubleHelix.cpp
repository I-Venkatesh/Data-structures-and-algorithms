#include <bits/stdc++.h>
using namespace std;
int main()
{
    while (1)
    {
        int n1;
        cin >> n1;
        if (n1 == 0)
        {
            break;
        }
        int arr1[n1];
        for (int i = 0; i < n1; i++)
        {
            cin >> arr1[i];
        }
        sort(arr1,arr1+n1);
        int n2;
        cin >> n2;
        int arr2[n2];
        for (int i = 0; i < n2; i++)
        {
            cin >> arr2[i];
        }
        sort(arr2,arr2+n2);
        int i = 0, j = 0;
        long long int sum = 0, s1 = 0, s2 = 0;
        while (i < n1 && j < n2)
        {
            if (arr1[i] == arr2[j])
            {
                s1 += arr1[i];
                s2 += arr2[j];
                sum += max(s1, s2);
                s1 = 0;
                s2 = 0;
                i++;
                j++;
            }
            else
            {
                if (arr1[i] < arr2[j])
                {
                    s1 += arr1[i];
                    i++;
                }
                else if (arr2[j] < arr1[i])
                {
                    s2 += arr2[j];
                    j++;
                }
            }
        }
        while(i<n1)
        {
            s1+=arr1[i];
            i++;
        }
        while(j<n2)
        {
            s2+=arr2[j];
            j++;
        }
        sum += max(s1, s2);
        cout << sum << "\n";
    }
}
