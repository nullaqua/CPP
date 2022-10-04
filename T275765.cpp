#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int edgeCnt;
ll head[5005],siz[5005],dp1[5005];
ll dp[5005][5005],dp2[5005];
struct Edge
{
    ll v,next;
}edge[10005];

void addEdge(int u,int v)
{
    edge[++edgeCnt].v=v;
    edge[edgeCnt].next=head[u];
    head[u]=edgeCnt;
}

void dfs(ll u,ll fa)
{
    siz[u]=1;
    dp[u][0]=0x3f3f3f3f3f3f3f3f;
    for (ll i=head[u];i;i=edge[i].next)
    {
        ll v=edge[i].v;
        if (v==fa)
        {
            continue;
        }
        dfs(v,u);
        for (int j=1;j<=siz[u]+siz[v];j++)
        {
            dp2[j]=0x3f3f3f3f3f3f3f3f;
        }
        for (ll j=siz[u]+siz[v];j>=1;j--)
        {
            for (ll k=max(1LL,j-siz[u]);k<=min(j,siz[v]);k++)
            {
                dp2[j]=min(dp2[j],dp[u][j-k]+dp[v][k]);
            }
        }
        siz[u]+=siz[v];
        for (int j=1;j<=siz[u];j++)
        {
            dp[u][j]=dp2[j];
        }
    }
    for (int i=2;i<=siz[u];i++)
    {
        dp[u][1]=min(dp[u][1],dp[u][i]+dp1[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=2;i<=n;i++)
    {
        cin>>dp1[i];
    }
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs(1,0);
    cout<<dp[1][1]<<'\n';
    return 0;
}