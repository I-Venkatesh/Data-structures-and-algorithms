class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        int n=s.length();
        if(s[n-1]!='0')
        {
            return 0;
        }
        q.push(0);
        int curr=0;
        while(!q.empty())
        {
            int hold=q.front();
            q.pop();
            if(hold==n-1)
            {
                return true;
            }
            for(int i=max(curr,hold+minJump);i<=min(n-1,hold+maxJump);i++)
            {
                if(s[i]=='0')
                {
                    q.push(i);
                }
            }
            curr=min(n,hold+maxJump+1);
        }
        return false;
    }
};