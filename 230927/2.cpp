#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/2
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

#define N int(3e5+5)
int n;
ll res=0;
ll a[N];

vector<tuple<ll,ll,ll>> ans;

void dfs(int x,ll y)
{
    if (a[x]>=y) return;
    dfs(x+1,y+res-a[x]);
    ans.emplace_back(x+1,x,y+res-a[x]);
    a[x+1]-=y+res-a[x];
    a[x]+=y+res-a[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    rep (i,1,n) cin>>a[i],res+=a[i];
    res=res/n;
    rep (i,1,n)
    {
        if (a[i]==res)continue;
        if (a[i]>=res)ans.emplace_back(i,i+1,a[i]-res),a[i+1]+=a[i]-res,a[i]=res;
        else
        {
            dfs(i+1,res-a[i]);
            ans.emplace_back(i+1,i,res-a[i]);
            a[i+1]-=res-a[i];
            a[i]=res;
        }
    }
    cout<<ans.size()<<'\n';
    for (auto [x,y,z]:ans) cout<<x<<' '<<y<<' '<<z<<'\n';
    return 0;
}