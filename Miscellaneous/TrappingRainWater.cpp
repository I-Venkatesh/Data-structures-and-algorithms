class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)
        {
            return 0;
        }
        vector<int> left;
        vector<int> right(height.size());
        left.push_back(0);
        int maxi=height[0];
        for(int i=1;i<height.size();i++)
        {
            left.push_back(maxi);
            maxi=max(maxi,height[i]);
        }
       
        right[height.size()-1]=0;
        maxi=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--)
        {
            right[i]=maxi;
            maxi=max(maxi,height[i]);
        }
        int ans=0;
        for(int i=0;i<height.size();i++)
        {
            if(left[i]>height[i]&&right[i]>height[i])
            {
                ans+=(min(left[i],right[i])-height[i]);
            }
        }
        return ans;
    }
};