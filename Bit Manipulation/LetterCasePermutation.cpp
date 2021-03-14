class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        set<string> ans;
        ans.insert(S);
        for(int i=0;i<pow(2,S.length());i++)
        {
            int x=i,c=0;
            string temp;
            while(x>0)
            {
                if((x&1)==1)
                {
                    if(S[c]>='a'&&S[c]<='z')
                    {
                        temp+='A'+(S[c]-'a');
                    }
                    else if(S[c]>='A'&&S[c]<='Z')
                    {
                        temp+='a'+(S[c]-'A');
                    }
                    else
                    {
                        temp+=S[c];
                    }
                }
                else
                {
                    temp+=S[c];
                }
                c++;
                x=x>>1;
            }
            while(c<S.length())
            {
                temp+=S[c];
                c++;
            }
            if(temp.length()==S.length())
            {
                ans.insert(temp);
            }
        }
        vector<string> arr;
        for(auto i:ans)
        {
            arr.push_back(i);
        }
        return arr;
    }
};