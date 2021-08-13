class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            ans[i]=0;
            while(!st.empty()&&st.top()<heights[i])
            {
                ans[i]++;
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]++;
            }
            st.push(heights[i]);
        }
        return ans;
    }
};