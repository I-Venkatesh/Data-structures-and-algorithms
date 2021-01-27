using namespace std;
#include<bits/stdc++.h>
bool knows(int i, int j, vector<vector<int>> &M)
{
    return (M[i][j]);
}
int celebrity(vector<vector<int>> &M, int n)
{
    // code here
    int a = 0, b = n - 1;
    while (a < b)
    {
        if (knows(a, b, M))
        {
            a++;
        }
        else
        {
            b--;
        }
    }
    for (int i = 0; i < M.size(); i++)
    {
        if (a != i && !knows(i, a, M) || knows(a, i, M))
        {
            return -1;
        }
    }
    return a;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> M;
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        M.push_back(temp);
    }
    cout<<celebrity(M,n)<<"\n";
}