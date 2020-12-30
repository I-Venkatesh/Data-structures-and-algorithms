#include <iostream>
using namespace std;

int main() {
    int test;
    cin>>test;
    while(test--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int i=0,j=0;
        bool ok=true;
        while(i<s1.length()&&j<s2.length()&&i>=0&&j>=0){
            if(s1[i]==s2[j]||s1[i]=='?')
            {
                i++;
                j++;
            }
            else if(s1[i]=='*')
            {
                if(i==s1.length()-1)
                {
                    break;
                }
                else
                {
                    i=s1.length()-1,j=s2.length()-1;
                    while(s1[i]==s2[j]&&i>=0&&j>=0)
                    {
                        i--;
                        j--;
                    }
                    if(s1[i]=='*')
                    {
                        break;
                    }
                    else{
                        ok=false;
                        break;
                    }
                }
            }
            else{
                ok=false;
                break;
            }
        }
        if(ok)
        {
            cout<<"Yes"<<"\n";
        }
        else{
            cout<<"No"<<"\n";
        }
        
    }
	return 0;
}