class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end());
        for(auto i:hand)
        {
            cout<<i<<" ";
        }
        int vis[hand.size()];
        memset(vis,0,sizeof(vis));
        int size=groupSize;
        for(int i=0;i<hand.size();i++)
        {
            if(vis[i]==0)
            {
                int curr=hand[i];
                size=groupSize;
                for(int j=i;j<hand.size();j++)
                {
                    if(curr==hand[j]&&size>0&&vis[j]==0)
                    {
                        vis[j]=1;
                        curr++;
                        size--;
                    }
                }
            }
        }
        if(size!=0)
        {
            return 0;
        }
        for(int i=0;i<hand.size();i++)
        {
            if(vis[i]==0)
            {
                return 0;
            }
        }
        return 1;
    }
};