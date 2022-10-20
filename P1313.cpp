#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P1313

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll x[1010][1010];

int main()
{
    long long a,b,k,n,m;
    cin>>a>>b>>k>>n>>m;
    x[1][1]=1;
    for (int i=2;i<=k+1;i++)
    {
        for (int j=1;j<=i;j++)
        {
            x[i][j]=(x[i-1][j-1]*b+x[i-1][j]*a)%10007;
        }
    }
    cout<<x[k+1][m+1];
    return 0;
}