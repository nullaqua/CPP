#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/U128816

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n,Q;
ll edge[1000005];
ll pre[1000005];
set<ll> pos[1000005];
ll val[4000005];

struct SegmentTree
{
    void setUp(ll p)
    {
        val[p]=max(val[p<<1],val[p<<1|1]);
    }

    void build(ll p,ll l,ll r)
    {
        if (l==r)
        {
            val[p]=pre[l];
            return;
        }
        ll mid=l+r>>1;
        build(p<<1,l,mid);
        build(p<<1|1,mid+1,r);
        setUp(p);
    }

    void add(ll p,ll l,ll r,ll q,ll k)
    {
        if (l==r)
        {
            val[p]=k;
            return;
        }
        ll mid=l+r>>1;
        if (q<=mid)
        {
            add(p<<1,l,mid,q,k);
        }
        else
        {
            add(p<<1|1,mid+1,r,q,k);
        }
        setUp(p);
    }

    ll search(ll p,ll l,ll r,ll ql,ll qr)
    {
        if (ql<=l&&r<=qr)
        {
            return val[p];
        }
        ll mid=l+r>>1;
        if (qr<=mid)
        {
            return search(p<<1,l,mid,ql,qr);
        }
        else if (mid<ql)
        {
            return search(p<<1|1,mid+1,r,ql,qr);
        }
        else
        {
            return max(search(p<<1,l,mid,ql,qr),search(p<<1|1,mid+1,r,ql,qr));
        }
    }
}tree;

int main()
{
    cin>>n>>Q;
    for (int i=1;i<=n;i++)
    {
        cin>>edge[i];
        pos[edge[i]].insert(i);
    }
    for (ll i=1;i<=n;i++)
    {
        pre[i]=pos[edge[i]].lower_bound(i)==pos[edge[i]].begin()?0:*--pos[edge[i]].lower_bound(i);
    }
    tree.build(1,1,n);
    while (Q--)
    {
        ll op,x,y;
        cin>>op>>x>>y;
        if (op==1)
        {
            ll l=pos[edge[x]].lower_bound(x)==pos[edge[x]].begin()?0:*--pos[edge[x]].lower_bound(x);
            ll r=pos[edge[x]].upper_bound(x)==pos[edge[x]].end()?n+1:*pos[edge[x]].upper_bound(x);
            if (r!=n+1)
            {
                tree.add(1,1,n,r,l);
            }
            pos[edge[x]].erase(x);
            pos[y].insert(x);
            edge[x]=y;
            l=pos[edge[x]].lower_bound(x)==pos[edge[x]].begin()?0:*--pos[edge[x]].lower_bound(x);
            r=pos[edge[x]].upper_bound(x)==pos[edge[x]].end()?n+1:*pos[edge[x]].upper_bound(x);
            tree.add(1,1,n,x,l);
            if (r!=n+1)
            {
                tree.add(1,1,n,r,x);
            }
        }
        else if (tree.search(1,1,n,x,y)>=x)
        {
            cout<<"yes\n";
        }
        else
        {
            cout<<"no\n";
        }
    }
    return 0;
}