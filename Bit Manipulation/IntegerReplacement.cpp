class Solution {
public:
    long long int calc(long long int n)
    {
        if(n==1)
        {
            return 0;
        }
        long long int mini=INT_MAX,plus=INT_MAX,div=INT_MAX;
        if(n&1)
        {
            mini=min(1+calc(n-1),mini);
        }
        if(n&1)
        {
            plus=min(1+calc(n+1),plus);
        }
        if(!(n&1))
        {
            div=min(1+calc(n/2),div);
        }
        return min(mini,min(div,plus));
        
    }
    int integerReplacement(int n) {
        return calc(n);
    }
};