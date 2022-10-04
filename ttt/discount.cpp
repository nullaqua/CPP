#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n,m,k;
ll a[500005];
ll ans[500005];
ll pre[500005];
vector<pair<ll,ll>> pairs;

int main()
{
    freopen("discount.in","r",stdin);
    freopen("discount.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++)
    {
        pre[i]=ans[i]=ans[i-1]+a[i];
    }
    for (int i=1,x,y;i<=m;i++)
    {
        cin>>x>>y;
        if (x<=k&&y<=k)
        {
            pairs.emplace_back(x,y);
        }
    }
    sort(pairs.begin(),pairs.end());
    pairs.erase(unique(pairs.begin(),pairs.end()),pairs.end());
    for (int i=0;i<=k;i++)
    {
        if (i!=0)
        {
            cout<<ans[i]<<' ';
        }
        ans[i+1]=min(ans[i+1],ans[i]+a[i+1]);
        for (pair<ll,ll> p:pairs)
        {
            if (i+p.first<=k)
            {
                ans[i+p.first]=min(ans[i+p.first],ans[i]+pre[i+p.first]-pre[i+p.second]);
            }
        }
    }
    return 0;
}