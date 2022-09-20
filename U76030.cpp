#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/U76030

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n,m;
ll cnt,sum;
ll edge[1000005];
ll b[1000005];
ll c[1000005];
ll c[1000005];

int main()
{
    cin>>n;
    for (ll i=1;i<=n;i++)
    {
        cin>>edge[i];
        if (!c[edge[i]])
        {
            m++;
            c[edge[i]]++;
        }
    }
    for (ll i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    ll l=1,r=0,ans=1e18;
    while (r<=n)
    {
        while (r<l||cnt<m&&r<n)
        {
            r++;
            if (!c[edge[r]])
            {
                cnt++;
            }
            c[edge[r]]++;
            sum+=b[r];
        }
        if (cnt==m)
        {
            ans=min(ans,sum);
        }
        c[edge[l]]--;
        if (!c[edge[l]])
        {
            cnt--;
        }
        sum-=b[l];
        l++;
    }
    cout<<ans;
    return 0;
}