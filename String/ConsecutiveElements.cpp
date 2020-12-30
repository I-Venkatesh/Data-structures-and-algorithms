#include <iostream>
using namespace std;

int main() {
    int test;
    cin>>test;
    while(test--)
    {
        string s;
        cin>>s;
        int i=0;
        while(i<s.length())
        {
            while(s[i]==s[i+1]&&i<s.length()-1)
            {
                i++;
            }
            cout<<s[i];
            i++;
        }
        cout<<"\n";
    }
	return 0;
}