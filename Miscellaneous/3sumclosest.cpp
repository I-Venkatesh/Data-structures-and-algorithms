class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0,x=100000;
        for(int i=0;i<nums.size();i++)
        {
                int a=i+1;
                int b=nums.size()-1;
                while(a<b)
                {
                    int sum=nums[i]+nums[a]+nums[b];
                    if(abs(target-sum)<x)
                    {
                        x=abs(target-sum);
                        ans=sum;
                    }
                    if(sum>target)
                    {
                        b--;
                    }
                    else{
                        a++;
                    }
                    
                }
        }
        return ans;
    }
};