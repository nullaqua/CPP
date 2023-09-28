#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/3
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef __int128 lll;
typedef unsigned __int128 ulll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define edge(i,x) for (auto i=head[x];i;i=i->nxt)
#define addE(x,y) head[x]=new EDGE(y,head[x])
#define addEV(x,y,z) head[x]=new EDGE(y,z,head[x])
#define addDE(x,y) addE(x,y),addE(y,x)
#define addDEV(x,y,z) addEV(x,y,z),addEV(y,x,z)

#define N int(1e5+5)

int n,m;
int a[N];
int d[N];
bool vis[N];

bool check(int x)
{
    memset(vis,0,sizeof(vis));
    int xx=x;
    per (i,x,1)
    {
        xx=min(i,xx);
        if (!d[i]) continue;
        if (vis[d[i]]) continue;
        vis[d[i]]=true;
        xx-=1+a[d[i]];
    }
    rep (i,1,m) if (!vis[i]) return false;
    if (xx<0) return false;
    return true;
}

int main()
{
    cin>>n>>m;
    rep (i,1,n) cin>>d[i];
    rep (i,1,m) cin>>a[i];
    ll l=1,r=n+1;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    if (r==n+1) cout<<-1;
    else cout<<r;
    return 0;
}