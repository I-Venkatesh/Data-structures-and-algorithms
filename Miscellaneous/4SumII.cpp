class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int> mp1,mp2;
        int count=0;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                mp1[nums1[i]+nums2[j]]++;
            }
        }
        for(int i=0;i<nums3.size();i++)
        {
            for(int j=0;j<nums4.size();j++)
            {
                mp2[nums3[i]+nums4[j]]++;
            }
        }
        for(auto i:mp1)
        {
            count+=mp2[-1*(i.first)]*i.second;
        }
        return count;
        
    }
};