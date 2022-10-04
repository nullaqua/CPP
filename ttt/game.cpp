#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ll n;
    cin>>n;
    if (n==3)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        cout<<x+y+z;
        return 0;
    }

    ll first=0;
    ll la=0;
    ll ans=0;
    for (int i=0,x;i<n;i++)
    {
        cin>>x;
        if (i==0)
        {
            first=x;
        }
        else if (i==n-1)
        {
            ans=max(ans,x+first);
        }
        ans=max(ans,x+la);
        la=x;
    }
    cout<<ans;
    return 0;
}