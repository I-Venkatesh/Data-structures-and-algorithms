#include <bits/stdc++.h>
using namespace std;
void allSubsequece(string input,string output)
{
    if(input.length()==0)
    {
        cout<<output<<"\n";
        return;
    }
    string temp="";
    for(int i=1;i<input.size();i++)
    {
        temp+=input[i];
    }
    string output2=output;
    allSubsequece(temp,output2);
    allSubsequece(temp,output2+input[0]);
}
int main() {
	//code
	int test;
	test=1;
	while(test--)
	{
	    string s;
	    cin>>s;
        string output="";
	    allSubsequece(s,output);
	}
	return 0;
}