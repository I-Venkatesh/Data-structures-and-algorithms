class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=1000000005,ans=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int curr=0;
            for(int i=0;i<piles.size();i++)
            {
                curr+=(piles[i]/mid)+(piles[i]%mid!=0?1:0);
            }
            if(curr<=h)
            {
                
                ans=min(ans,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
        
    }
};