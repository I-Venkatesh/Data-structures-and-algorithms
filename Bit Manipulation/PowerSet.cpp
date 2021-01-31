using namespace std;
#include <bits/stdc++.h>
int main()
{
    string s;
    cin >> s;
    for (int i = 1; i < pow(2, s.length()); i++)
    {
        string temp;
        for (int j = 0; j < s.length(); j++)
        {
            if (i & (1 << j))
            {
                temp += s[j];
            }
        }
        cout<<temp<<"\n";
    }
}