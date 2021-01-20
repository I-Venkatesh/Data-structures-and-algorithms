using namespace std;
#include <bits/stdc++.h>
int catalan[1009];
int catl(int n)
    {
        catalan[0] = catalan[1] = 1; 

        for (int i = 2; i <= n; i++)  
        { 
            catalan[i] = 0; 
            for (int j = 0; j < i; j++) 
                catalan[i] += catalan[j] * catalan[i - j - 1]; 
        } 
        return catalan[n];
    }
    int calc(int n){
        return catl(n);
    }
int main()
{
    int n=9;
    cout<<calc(n);
}