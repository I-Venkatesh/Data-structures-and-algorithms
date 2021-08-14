class Solution {
public:
    void solve(vector<int> &arr,int index,int k,int &ans)
    {
        if(arr.size()==1)
        {
            ans=arr[0];
            return;
        }
        index=(index+k)%arr.size();
        arr.erase(arr.begin()+index);
        solve(arr,index,k,ans);
        return;
    }
    int findTheWinner(int n, int k) {
        vector<int> arr;
        for(int i=1;i<=n;i++)
        {
            arr.push_back(i);
        }
        int ans=-1;
        k--;
        solve(arr,0,k,ans);
        return ans;
    }
};