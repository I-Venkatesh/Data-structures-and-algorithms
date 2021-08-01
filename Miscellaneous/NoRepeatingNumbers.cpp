vector<int> singleNumber(vector<int> nums) 
    {
        int xored=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            xored^=nums[i];
        }
        int x=0;
        for(int i=0;i<32;i++)
        {
            if(xored&(1<<i))
            {
                x=i;
                break;
            }
        }
        int num1=0,num2=0;
        for(int i=0;i<nums.size();i++)
        {
            if((1<<x)&nums[i])
            {
                num1^=nums[i];
            }
            else{
                num2^=nums[i];
            }
        }
        vector<int> ans;
        
        if(num1<num2)
        {
            ans.push_back(num1);
            ans.push_back(num2);
        }
        else{
            ans.push_back(num2);
            ans.push_back(num1);
        }
        return ans;
    }

