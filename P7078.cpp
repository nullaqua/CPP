#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P7078

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n,m,q,u,v,t;
ll a[100005],ans[10000005];
queue<ll> que[3];

bool cmp(ll x,ll y)
{
    return x>y;
}

ll getMax()
{
    ll mx=-0x3f3f3f3f3f3f3f3f;
    for (queue<ll> &i:que)
    {
        if (!i.empty())
        {
            mx=max(mx,i.front());
        }
    }

    for (queue<ll> &i:que)
    {
        if (!i.empty()&&i.front()==mx)
        {
            i.pop();
            break;
        }
    }
    return mx;
}

int main()
{
    cin>>n>>m>>q>>u>>v>>t;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        que[0].push(a[i]);
    }
    ll delta=0;
    for (int i=1;i<=m;i++)
    {
        ll tmp=getMax()+delta;
        if (!(i%t))
        {
            cout<<tmp<<' ';
        }
        ll x=tmp*u/v,y=tmp-x;
        delta+=q;
        x-=delta;
        y-=delta;
        que[1].push(x);
        que[2].push(y);
    }
    cout<<'\n';
    ll len=0;
    for (queue<ll> &i:que)
    {
        while (!i.empty())
        {
            ans[++len]=i.front()+delta;
            i.pop();
        }
    }
    sort(ans+1,ans+len+1,cmp);
    for (ll i=t;i<=n+m;i+=t)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}