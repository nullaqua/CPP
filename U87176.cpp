#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll T;
    cin>>T;
    while (T--)
    {
        ll a,b,c;

        cin>>a>>b>>c;
        if (c==0)
        {
            cout<<1<<'\n';
        }
        else
        {
            cout<<a/gcd(a,c)<<'\n';
        }
    }
    return 0;
}