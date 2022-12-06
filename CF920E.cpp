#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/CF920E

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool vis[200005];
vector<int>adj[200005];
int n,m;
int cnt[200005];
int ed;
set<int> st;

void dfs(int u,int color)
{
    vis[u]=true;
    cnt[color]++;
    set<int>st1=st;
    for (auto i=st1.begin();i!=st1.end();)
    {
        int v=*i;
        if (vis[v]||*lower_bound(adj[u].begin(),adj[u].end(),v)==v)
        {
            ++i;
            continue;
        }
        st1.erase(i++);
        st.erase(st.find(v));
        dfs(v,color);
    }
}

int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i=1;i<=n;i++)
    {
        st.insert(i);
        sort(adj[i].begin(),adj[i].end());
        adj[i].erase(unique(adj[i].begin(),adj[i].end()),adj[i].end());
    }

    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            dfs(i,++ed);
        }
    }

    sort(cnt+1,cnt+1+ed);
    cout<<ed<<'\n';
    for (int i=1;i<=ed;i++)
    {
        cout<<cnt[i]<<' ';
    }
    return 0;
}