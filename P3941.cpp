#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P3941

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n,m,k;
ll edge[405][405];
ll sum[405][405];
ll s[405];
ll d[1000005];

int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>edge[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+edge[i][j]+k;
            sum[i][j]%=k;
        }
    }
    ll ans=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
        {
            for (int kk=1;kk<=m;kk++)
            {
                s[kk]=sum[j][kk]-sum[i-1][kk]+k;
                s[kk]%=k;
                ans+=d[s[kk]]++;
            }
            ans+=d[0];
            for (int kk=1;kk<=m;kk++)
            {
                d[s[kk]]=0;
            }
            d[0]=0;
        }
    }
    cout<<ans;
    return 0;
}