#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/1
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

int n;
int tree[2*N];

#define lb(x) (x&(-x))
int tol;
int search(int x)
{
    int ans=0;
    while (x) ans+=tree[x],x-=lb(x);
    return ans;
}

void add(int x,int y)
{
    while (x<=tol) tree[x]+=y,x+=lb(x);//,cerr<<x<<'\n';
}

int res[N];
int a[N*2];
pii op[N];
map<int,int> mp0;
map<int,int> mp1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    rep (i,1,n)
    {
        int x,y;
        cin>>x>>y;
        op[i]=make_pair(x,y+1);
        a[i*2-1]=x;
        a[i*2]=y+1;
    }
    sort(a+1,a+1+n*2);
    tol=int(unique(a+1,a+1+n*2)-a-1);
    rep (i,1,tol) mp0[a[i]]=i,mp1[i]=a[i];
    mp1[tol+1]=1e9;
    rep (i,1,n)
    {
        add(mp0[op[i].first],1);
        add(mp0[op[i].second],-1);
    }
    rep (i,1,tol)
    {
        res[search(i)]+=mp1[i+1]-mp1[i];
    }
    rep (i,1,n) cout<<res[i]<<' ';
    return 0;
}
/*
T T   T T         T
0 1 2 3 4 5 6 7 8
1 1 1 1
  2 2 2
      3 1 1 1 1 1
*/