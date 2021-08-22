using namespace std;
#include <bits/stdc++.h>
int main()
{
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        string s;
        cin >> s;
        int freq[30];
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }
        string ans = "";
        for (int k = 0; k < 1000; k++)
        {
            ans="";
            for (int j = 0; j < s.length(); j++)
            {
                char t = s[j];
                for (int i = 0; i < 30; i++)
                {
                    int x = t - 'a';
                    if (x != i && freq[i] > 0)
                    {
                        // cout << x << " " << i << "";
                        ans += char('a' + i);
                        // cout << ans << " ";
                        freq[i]--;
                    }
                }
            }
            bool ok=true;
            for(int f=0;f<s.length();f++)
            {
                if(ans[f]==s[f])
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
            {
                break;
            }
        }
         bool ok2=true;
            for(int f=0;f<s.length();f++)
            {
                if(ans[f]==s[f])
                {
                    ok2=false;
                    break;
                }
            }
        if (ok2)
        {
            cout << "Case #" << t << ": " << ans << "\n";
        }
        else
        {
            cout << "Case #" << t << ": "
                 << "IMPOSSIBLE"
                 << "\n";
        }
    }
}