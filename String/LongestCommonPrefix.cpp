using namespace std;
#include <bits/stdc++.h>
int main()
{
    vector<string> strs;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        string s;
        cin >> s;
        strs.push_back(s);
    }
    string ans = "";
    if (strs.size() == 0)
    {
        cout << "";
    }
    else
    {
        for (int i = 0; i < strs[0].size(); i++)
        {
            char x = strs[0][i];
            int c = 0;
            for (int j = 0; j < strs.size(); j++)
            {
                if (strs[j][i] == x)
                {
                    c++;
                }
            }
            if (c == strs.size())
            {
                ans += x;
            }
            else
            {
                cout<<ans<<"\n";
            }
        }
        cout<<ans<<"\n";
    }
}