class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            int arr[101];
            memset(arr,0,sizeof(arr));
            for(int k=i;k<m;k++)
            {
                for(int j=0;j<n;j++)
                {
                    arr[j]+=matrix[k][j];
                }
                for(int j=0;j<n;j++)
                {
                    int sum=0;
                    for(int k=j;k<n;k++)
                    {
                        if(target==(sum=sum+arr[k]))
                        {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};