class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<pair<int,int>> st;
        for(int i=0;i<temperatures.size();i++)
        {
            while(!st.empty()&&st.top().second<temperatures[i])
            {
                ans[st.top().first]=i-st.top().first;
                st.pop();
            }
            st.push({i,temperatures[i]});
        }
        return ans;
    }
};