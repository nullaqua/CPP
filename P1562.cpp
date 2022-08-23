#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P1562

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n,ans;
ll mp[20];

ll lb(ll x)
{
    return x&-x;
}

void dfs(ll i,ll j,ll l,ll r)
{
    if (j>n)
    {
        ans++;
        return;
    }
    ll ss=i|l|r|mp[j];
    ss=~ss;
    ss&=(1<<n)-1;
    while (ss)
    {
        dfs(i+lb(ss),j+1,(l+lb(ss))<<1,(r+lb(ss))>>1);
        ss-=lb(ss);
    }
}

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<n;j++)
        {
            char s;
            cin>>s;
            mp[i]=(s=='.')+(mp[i]<<1);
        }
    }
    dfs(0,1,0,0);
    cout<<ans;
    return 0;
}  