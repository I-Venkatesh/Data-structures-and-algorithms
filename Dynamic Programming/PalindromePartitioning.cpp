class Solution {
public:
    bool checkPal(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void recur(vector<vector<string>> &ans,vector<string> &curr,int i,string s)
    {
        if(i>=s.length())
        {
            ans.push_back(curr);
            return;
        }
        for(int start=i;start<s.length();start++)
        {
            if(checkPal(s,i,start))
            {
                curr.push_back(s.substr(i,start-i+1));
                recur(ans,curr,start+1,s);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> curr;
        recur(ans,curr,0,s);
        return ans;
    }
};