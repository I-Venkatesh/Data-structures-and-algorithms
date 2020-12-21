using namespace std;
#include <bits/stdc++.h>
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    //code here.
    //code here.
    int i = 0, j = 0, k = 0;
    int mini = INT_MIN;
    vector<int> ans;
    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] == B[j] && A[i] == C[k] && A[i] != mini)
        {
            mini = A[i];
            ans.push_back(A[i]);
            i++;
            j++;
            k++;
        }
        else
        {
            if (min(min(A[i], B[j]), C[k]) == A[i])
            {
                i++;
            }
            else if (min(min(A[i], B[j]), C[k]) == B[j])
            {
                j++;
            }
            else
            {
                k++;
            }
        }
    }
    return ans;
}
int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int arr1[n1];
    int arr2[n2];
    int arr3[n3];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    for (int i = 0; i < n3; i++)
    {
        cin >> arr3[i];
    }
    vector<int> ans = commonElements(arr1, arr2, arr3, n1, n2, n3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}