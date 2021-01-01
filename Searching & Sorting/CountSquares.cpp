#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    N--;
    while (floor(sqrt(N)) != ceil(sqrt(N)))
    {
        N--;
    }
    cout<<sqrt(N);
    return 0;
}