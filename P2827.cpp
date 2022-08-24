#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P2827

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n,m,q,u,v,t;
ll a[100005];
queue<ll> que[3];

int main()
{
    cin>>n>>m>>q>>u>>v>>t;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=n;i>0;i--)
    {
        que[0].push(a[i]);
    }
    ll ss=0;
    for (int i=1;i<=m;i++)
    {
        ll ans=LONG_LONG_MIN;
        for (queue<ll> &i:que)
        {
            if (!i.empty())
            {
                ans=max(ans,i.front());
            }
        }

        for (queue<ll> &i:que)
        {
            if (!i.empty()&&i.front()==ans)
            {
                i.pop();
                break;
            }
        }
        ans+=ss;

        if (!(i%t))
        {
            cout<<ans<<' ';
        }
        ll x=ans*u/v,y=ans-x;
        ss+=q;
        x-=ss;
        y-=ss;
        que[1].push(x);
        que[2].push(y);
    }
    cout<<'\n';
    ll len=0;
    ll ans[10000005];
    for (queue<ll> &i:que)
    {
        while (i.size())
        {
            len++;
            ans[len]=i.front()+ss;
            i.pop();
        }
    }
    sort(ans+1,ans+len+1);
    /*for (ll i=t;i<=n+m;i+=t)
    {
        cout<<ans[i]<<' ';
    }*/
    for (ll i=n+m+1-t;i>0;i-=t)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}