class Solution {
  public:
    vector<long long> v;
    void bfs(long long x,long long  num){
        queue<long long> q;
        q.push(num);
        while(!q.empty())
        {
            num=q.front();
            q.pop();
            if(num<=x)
            {
                v.push_back(num);
                long long last=num%10;
                if(last==0)
                {
                    q.push((num*10)+(last+1));
                }
                else if(last==9){
                    q.push((num*10)+(last-1));
                }
                else{
                    q.push((num * 10) + (last - 1));
                    q.push((num * 10) + (last + 1));
                }
            }
        }
    }
    long long jumpingNums(long long X) {
       v.push_back(0);
       for(int i=1;i<=9&&i<=X;i++)
       {
           bfs(X,i);
       }
       long long ans=0;
       for(int i=0;i<v.size();i++)
       {
        //   cout<<v[i]<<" ";
           if(v[i]<=X)
           {
               ans=max(ans,v[i]);
           }
       }
       return ans;
    }
      
};
