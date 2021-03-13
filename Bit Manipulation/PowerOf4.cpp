class Solution {
public:
    bool isPowerOfFour(int n) {
        int pos=0,one=0,on;
        while(n>0)
        {
            if(n&1)
            {
                one++;
                on=pos;
            }
            pos++;
            n=n>>1;
        }
        if(one==1&&((on&1)==0)&&(n!=2))
        {
            return true;
        }
        return false;
    }
};