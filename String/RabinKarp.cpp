#include <bits/stdc++.h>
using namespace std;
void search(char pat[],char txt[], int q)
{
    int m=strlen(pat);
    int n=strlen(txt);
    int i,j;
    int p=0,t=0,h=1;
    for(int i=0;i<m-1;i++)
    {
        h=(h*256)%q;
    }
    for(int i=0;i<m;i++)
    {
        p=(256*p+pat[i])%q;
        t=(256*t+txt[i])%q;
    }
    for(int i=0;i<=n-m;i++)
    {
        if(p==t)
        {
            for(j=0;j<m;j++)
            {
                if(txt[i+j]!=pat[j])
                {
                    break;
                }
            }
            if(j==m)
            {
                cout<<"Pattern found at "<<i<<"\n";
            }
        }
        if(i<m-n)
        {
            t=(256*(t-txt[i]*h))+txt[i+m]%q;
            if(t<0)
            {
                t=t+q;
            }
        }
    }
}
int main()  
{  
    char txt[] = "abcd of abcd";  
    char pat[] = "abcd"; 
        
      // A prime number  
    int q = 101;  
      
      // Function Call 
      search(pat, txt, q);  
    return 0;  
}  