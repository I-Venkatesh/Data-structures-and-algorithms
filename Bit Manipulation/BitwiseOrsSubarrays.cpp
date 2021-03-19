class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans,curr;
        curr.insert(0);
        for(auto i:arr)
        {
            unordered_set<int> curr2;
            for(auto j:curr)
            {
                curr2.insert(i|j);
            }
            curr2.insert(i);
            curr=curr2;
            for(auto j:curr)
            {
                ans.insert(j);
            }
        }
        return ans.size();
        
    }
};