#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P1070

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n,m,p;
ll a[1005];
ll v[1005][1005];
ll dp[1005];

int main()
{
    cin>>n>>m>>p;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>v[i][j];
        }
    }

    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    memset(dp,-0x3f,sizeof dp);
    dp[0]=0;

    for (int i=0;i<=m;i++)
    {
        //cerr<<dp[i]<<' ';
        for (int j=1;j<=n;j++)
        {
            ll sum=dp[i]-a[j];
            for (int k=1;k<=p&&k+i<=m;k++)
            {
                sum+=v[(j+k-2)%n+1][k+i];
                dp[k+i]=max(dp[k+i],sum);
                //cerr<<"dp["<<k+i<<"]="<<sum<<' '<<(j+k-2)%n+1<<' '<<k+i<<endl;
            }
        }
    }
    cout<<dp[m];
    return 0;
}