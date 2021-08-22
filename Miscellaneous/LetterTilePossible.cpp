class Solution {
public:
    vector<string> all;
    void permute(string tiles)
    {
        do{
            all.push_back(tiles);
        }while(next_permutation(tiles.begin(),tiles.end()));
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        permute(tiles);
        set<string> st;
        for(auto x:all)
        {
            for(int i=0;i<(1<<x.size());i++)
            {
                int j=i;
                string s="";
                int c=0;
                while(j)
                {
                    if(j&1)
                    {
                        s+=x[c];
                    }
                    j>>=1;
                    c++;
                }
                st.insert(s);
            }
        }
        return st.size()-1;
    }
};