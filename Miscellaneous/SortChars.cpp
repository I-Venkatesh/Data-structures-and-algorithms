class Solution {
public:
    string frequencySort(string s) {
        int arr[502];
        memset(arr,0,sizeof(arr));
        for(auto i:s)
        {
            arr[i]++;
        }
        vector<pair<int,char>> ans;
        for(int i=0;i<500;i++)
        {
            if(arr[i]>0)
            {
                ans.push_back({arr[i],char(i)});
            }
        }
        sort(ans.rbegin(),ans.rend());
        string res="";
        for(auto i:ans)
        {
            for(int j=0;j<i.first;j++)
            {
                res+=i.second;
            }
        }
        return res;
    }
};