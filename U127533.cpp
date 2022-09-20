#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/U127533

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll a[1000005];
ll b[1000005];
ll c[1000005];
ll c[1000005];

ll fastPow(ll x,ll y,ll P)
{
    ll res=1;
    while (y)
    {
        if (y&1)
        {
            (res*=x)%=P;
        }
        (x*=x)%=P;
        y>>=1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n,m,p,k;
    cin>>n>>m>>p>>k;
    bool flag=false;
    for (ll i=1;i<=k;i++)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        a[x]++;
        b[y]++;
        if (w==-1)
        {
            c[x]++;
            c[y]++;
        }
    }

    if ((n+m)&1)
    {
        flag=true;
    }

    for (ll i=1;i<=n;i++)
    {
        if (a[i]==m&&(c[i]^1))
        {
            flag=true;
        }
    }

    for (ll i=1;i<=m;i++)
    {
        if (b[i]==n&&(c[i]^1))
        {
            flag=true;
        }
    }

    if (flag)
    {
        cout<<0;
    }
    else
    {
        cout<<fastPow(2,((n-1)*(m-1)-k)>0?((n-1)*(m-1)-k):0,p)<<'\n';
    }
    return 0;
}