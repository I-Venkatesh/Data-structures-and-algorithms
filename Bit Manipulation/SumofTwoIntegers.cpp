class Solution {
public:
    int getSum(int a, int b) {
        long long int carry=0,ans=0;
        for(int i=0;i<32;i++)
        {
            int x=a&(1<<i);
            int y=b&(1<<i);
            if(x!=0&&y!=0&&carry==1)
            {
                ans|=1<<i;
            }
            else if(x!=0&&y!=0&&carry==0)
            {
                carry=1;
            }
            else if((x!=0||y!=0)&&carry==1)
            {
                carry=1;
            }
            else if((x!=0||y!=0)&&carry==0)
            {
                ans|=1<<i;
            }
            else if((x==0&&y==0)&&carry==1)
            {
                ans|=1<<i;
                carry=0;
            }
        }
        return ans;
    }
};
