class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int prev=0,sum=0;
        for(int i=0;i<target.size();i++)
        {
            if(prev<target[i])
            {
                sum+=target[i]-prev;
            }
            prev=target[i];
        }
        return sum;
    }
};