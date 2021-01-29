using namespace std;
#include<bits/stdc++.h>
int minValue(string s, int k)
{
    int freq[100];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
    }
    priority_queue<int> pq;
    for (int i = 0; i < 100; i++)
    {
        if (freq[i] > 0)
        {
            pq.push(freq[i]);
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (pq.size() > 0)
        {
            int x = pq.top();
            x--;
            pq.pop();
            pq.push(x);
        }
    }
    int sum = 0;
    while (!pq.empty())
    {
        sum += pq.top() * pq.top();
        pq.pop();
    }
    return sum;
}
int main()
{
    int k;
    cin>>k;
    string s;
    cin>>s;
    cout<<minValue(s,k)<<"\n";
}