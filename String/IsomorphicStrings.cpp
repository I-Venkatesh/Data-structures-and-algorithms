#include <bits/stdc++.h>
using namespace std;
bool areIsomorphic(string str1, string str2)
{
    int freq1[30],freq2[30];
    memset(freq1,0,sizeof(freq1));
    memset(freq2,0,sizeof(freq2));
    if(str1.length()!=str2.length())
    {
        return false;
    }
    else
    {
        for(int i=0;i<str1.length();i++)
        {
            if(freq1[str1[i]-'a']!=freq2[str2[i]-'a'])
            {
                return false;
            }
            else{
                freq1[str1[i]-'a']++;
                freq2[str2[i]-'a']++;
            }
        }
    }
    return true;
}
int main() {
   string s1,s2;
   cin>>s1>>s2;
    if(areIsomorphic(s1,s2))
    {
        cout<<"Yes"<<"\n";
    }
    else{
        cout<<"No"<<"\n";
    }
}