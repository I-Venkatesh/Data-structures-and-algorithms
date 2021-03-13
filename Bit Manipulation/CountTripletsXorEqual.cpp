class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> x;
        x.push_back(0);
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            x.push_back(arr[i]^x[i]);
        }
        for(int i=0;i<x.size();i++)
        {
            for(int j=i+1;j<x.size();j++)
            {
                if(x[i]==x[j])
                {
                    count+=(j-i-1);
                }
            }
        }
        return count;
    }
};