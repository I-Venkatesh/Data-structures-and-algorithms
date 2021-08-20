vector<int> subarraySum(int arr[], int n, int s)
{
    int i = 0, j = 0;
    int sum = 0;
    vector<int> ans;
    while (j < n && i <= j)
    {
        if (sum == s)
        {
            ans.push_back(i + 1);
            ans.push_back(j);
            return ans;
        }
        else
        {
            if (sum > s)
            {
                sum -= arr[i];
                i++;
            }
            else
            {
                sum += arr[j];
                // cout<<sum<<"\n";
                j++;
            }
        }
    }
    while (i < n && sum > n)
    {
        if (sum == s)
        {
            ans.push_back(i + 1);
            ans.push_back(j);
            return ans;
        }
        sum -= arr[i];
        i++;
    }
    for (int x = 0; x < n; x++)
    {
        if (arr[x] == s)
        {
            ans.push_back(x + 1);
            ans.push_back(x + 1);
            return ans;
        }
    }
    ans.push_back(-1);
    return ans;
}