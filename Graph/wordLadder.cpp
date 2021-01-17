using namespace std;
#include <bits/stdc++.h>

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    int loop = 0;
    unordered_set<string> dict;
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    bool ok = false;
    for (int i = 0; i < wordList.size(); i++)
    {
        if (wordList[i] == endWord)
        {
            ok = true;
        }
        dict.insert(wordList[i]);
    }
    if (!ok)
    {
        return 0;
    }
    while (!q.empty())
    {
        pair<string, int> p;
        p = q.front();
        string x = p.first;
        if (x == endWord)
        {
            return p.second;
        }
        q.pop();
        string str = x;
        for (int i = 0; i < str.length(); i++)
        {
            for (char c = 'a'; c <= 'z'; c++)
            {
                char t = str[i];
                str[i] = c;
                if (dict.count(str))
                {
                    q.push({str, p.second + 1});
                    dict.erase(str);
                }
                str[i] = t;
            }
        }
    }
    return 0;
}
int main()
{
    vector<string> s={"hot","dot","dog","lot","log","cog"};
    cout<<ladderLength("hit","cog",s);
}
