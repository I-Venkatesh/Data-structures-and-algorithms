using namespace std;
#include <bits/stdc++.h>
int dp[1009][1009];
int calcPal(string s, int i, int j)
{
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        i--;
        j++;
    }
    return (j - i - 1);
}
string lps(string s)
{
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int len = max(calcPal(s, i, i), calcPal(s, i, i + 1));
        if (len > end - start)
        {
            start = i - ((len - 1) / 2);
            end = start + len;
        }
    }
    return s.substr(start, end - start);
}

int main()
{
    string s;
    cin >> s;
    cout << lps(s) << "\n";
}