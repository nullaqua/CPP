#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P1395

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct EDGE
{
    int v,next;
}edge[100005];
int ed;
int head[50004];
void add_edge(int u,int v)
{
    edge[++ed].v=v;
    edge[ed].next=head[u];
    head[u]=ed;
}

ll n;
ll siz[50004];
ll sum[50004];
ll ans[50004];

void dfs(int u,int fa)
{
    siz[u]++;
    for (int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].v;
        if (v==fa)
        {
            continue;
        }
        dfs(v,u);
        siz[u]+=siz[v];
        sum[u]+=sum[v]+siz[v];
    }
}

ll ans0=1;
ll ans1=1e18;

void dfs0(int u,int fa)
{
    if (ans[u]<ans1||(ans[u]==ans1&&u<ans0))
    {
        ans0=u;
        ans1=ans[u];
    }
    for (int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].v;
        if (v==fa)
        {
            continue;
        }
        ans[v]=ans[u]+n-siz[v]-siz[v];
        dfs0(v,u);
    }
}

int main()
{
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        add_edge(x,y);
        add_edge(y,x);
    }

    dfs(1,0);
    ans[1]=sum[1];
    dfs0(1,0);
    cout<<ans0<<' '<<ans1;
    return 0;
}