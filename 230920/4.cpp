#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/4

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define N int(1e6+5)

int n,ql,qr;
int a[N];
int b[N];

ll check(ll x)
{
    //cerr<<x<<'\n';
    ll cnt=0;
    rep (i,1,n)
    {
        ll tmp=x-a[i];
        if (tmp<0) return cnt;
        if (tmp>=b[n]) cnt+=n;
        else cnt+=n+1-(lower_bound(b+1,b+n+1,tmp)-b);
        if (cnt>=ql) return cnt;
    }
    return cnt;
}

ll get()
{
    ll l=0,r=2e9;
    while (l<r)
    {
        ll mid=(l+r)>>1;
        if (check(mid)>=ql) r=mid;
        else l=mid+1;
    }
    return l;
}

struct Node
{
    int x,y;
    Node(int _x,int _y):x(_x),y(_y){}

    bool operator < (const Node &rhs) const
    {
        return a[x]+b[y]>a[rhs.x]+b[rhs.y];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>ql>>qr;
    rep (i,1,n) cin>>a[i];
    rep (i,1,n) cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    ll ans=get();
    cerr<<ans<<'\n';

    priority_queue<Node> q;
    ll sb=ql-check(ans-1);
    rep (i,1,n)
    {
        if (ans>=a[i]+b[n]) continue;
        ll tmp=lower_bound(b+1,b+n+1,ans-a[i])-b;
        ll tp0=ans>a[i]+b[n]?upper_bound(b+1,b+n+1,ans-a[i])-b:n+1;
        ll xx=min(tp0-tmp,sb);
        sb-=xx;
        if (tmp+xx<=n) q.emplace(i,tmp+xx);
    }
    int xxx=qr-ql+1;
    while (xxx--)
    {
        auto [x,y]=q.top();
        q.pop();
        cout<<a[x]+b[y]<<' ';
        if (y<n) q.emplace(x,y+1);
    }
    return 0;
}