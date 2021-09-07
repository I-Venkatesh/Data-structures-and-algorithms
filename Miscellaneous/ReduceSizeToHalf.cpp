class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int arr2[100005];
        memset(arr2,0,sizeof(arr2));
        for(int i:arr)
        {
            arr2[i]++;
        }
        vector<int> ans;
        int tot=arr.size();
        for(int i=0;i<100005;i++)
        {
            if(arr2[i]>0)
            {
                ans.push_back(arr2[i]);
            }
        }
        sort(ans.rbegin(),ans.rend());
        if(tot%2!=0)
        {
            tot=tot/2;
            tot++;
        }
        else{
            tot/=2;
        }
        int sum=0;
        int count=0;
        for(int i=0;i<ans.size();i++)
        {
            if(sum>=tot)
            {
                break;
            }
            sum+=ans[i];
            count++;
        }
        return count;
    }
};