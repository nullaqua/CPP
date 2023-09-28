#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P1070

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define N int(1005)

ll n,m,p;
ll a[N];
ll v[N][N];
ll dp[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m>>p;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin>>v[i][j];

    for (int i=1;i<=n;i++) cin>>a[i];

    memset(dp+1,0x80,sizeof dp-sizeof dp[0]);

    for (int i=0;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            ll sum=dp[i]-a[j];
            for (int k=1;k<=p&&k+i<=m;k++)
            {
                sum+=v[(j+k-2)%n+1][k+i];
                dp[k+i]=max(dp[k+i],sum);
            }
        }
    }
    cout<<dp[m];
    return 0;
}