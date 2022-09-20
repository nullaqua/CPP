#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/CF1132D

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n,k;

struct Node
{
    ll a,b,c;

    Node(ll a=0,ll b=0,ll c=0) : a(a),b(b),c(c)
    {
    }
}a[200005];

vector<Node> vec[200005];

bool check(ll x)
{
    for (ll i=1;i<=k;i++)
    {
        vec[i].clear();
    }
    for (ll i=1;i<=n;i++)
    {
        if (a[i].c<k)
        {
            vec[a[i].c].push_back(a[i]);
        }
    }
    ll cnt=0;
    for (ll t=1;t<=k;t++)
    {
        for (ll i=0;i<vec[t].size();i++)
        {
            vec[t][i].a+=x;
            vec[t][i].c=vec[t][i].a/vec[t][i].b+1;
            cnt++;
            if (vec[t][i].c<k)
            {
                vec[vec[t][i].c].push_back(vec[t][i]);
            }
        }
        if (cnt>t)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin>>n>>k;
    for (ll i=1;i<=n;i++)
    {
        cin>>a[i].a;
    }
    for (ll i=1;i<=n;i++)
    {
        cin>>a[i].b;
        a[i].c=a[i].a/a[i].b+1;
    }
    bool flag=true;
    for (int i=1;i<=n;i++)
    {
        if (a[i].c<k)
        {
            flag=false;
            break;
        }
    }
    if (flag)
    {
        cout<<0<<'\n';
        return 0;
    }
    const ll maxR=1e13;
    ll l=1,r=maxR;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        bool cc=check(mid);
        //cout<<l<<' '<<r<<' '<<check(mid)<<endl;
        if (cc)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<(r==maxR?-1:l)<<'\n';
    return 0;
}