#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool in(ll x,ll s,ll t,bool b)
{
    if (b)
    {
        if (s<t)
        {
            return x>=s&&x<=t;
        }
        else
        {
            return x>=s||x<=t;
        }
    }
    else
    {
        if (s>t)
        {
            return x<=s&&x>=t;
        }
        else
        {
            return x<=s||x>=t;
        }
    }
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
        ll n,a,x,b,y;
        cin>>n>>a>>x>>b>>y;
        ll t=(a+b)>>1;
        if (a>b)
        {
            a=(a+n-t)%n;
            b=(b+n-t)%n;
            x=(x+n-t)%n;
            y=(y+n-t)%n;
        }
        //cout<<edge<<' '<<x<<' '<<b<<' '<<y<<'\n';
        t=(a+b)>>1;
        if ((x>t||x<a)&&(y<t||y>b)&&!(abs(a-b)&1))
        {
            cout<<"YES\n";
            continue;
        }
        ll len=n-abs(a-b);
        //cout<<len<<'\n';
        if (len&1)
        {
            cout<<"NO\n";
            continue;
        }
        //cout<<"edge: "<<edge<<' '<<(edge+len/2+abs(edge-b))%n<<'\n';
        if (in(x,a,(a+len/2+abs(a-b))%n,true))
        {
            cout<<"NO\n";
            continue;
        }
        //cout<<"b: "<<b<<' '<<(b+len/2+abs(edge-b))%n<<'\n';
        if (in(y,b,(b+len/2+abs(a-b))%n,false))
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }
    return 0;
}