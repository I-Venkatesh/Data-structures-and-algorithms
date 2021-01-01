#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if (B < A)
    {
        swap(A, B);
    }
    if (C < B)
    {
        swap(B, C);
    }
    if (B < A)
    {
        swap(A, B);
    }
    cout<<B<<"\n";
    return 0;
}