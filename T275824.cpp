#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/T275824

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll MAX=1LL<<30LL;
const ll INF=(1LL<<31LL)-1;

struct Result
{
    ll sum,maxL,maxR,minL,minR,mx;

    Result(ll sum,ll maxL,ll maxR,ll minL,ll minR,ll mx) : sum(sum),maxL(maxL),maxR(maxR),minL(minL),minR(minR),mx(mx)
    {
    }
};

ll check(ll x)
{
    return min(INF,max(-INF,x));
}

template<int Size>
struct SegmentTree
{
    struct Node
    {
        ll sum;
        ll l,r;
        ll maxL;
        ll maxR;
        ll minL;
        ll minR;
        ll mx;
    };

    Node nodes[Size*4];

    ll &getL(ll p)
    {
        return nodes[p].l;
    }

    ll &getR(ll p)
    {
        return nodes[p].r;
    }

    ll &getSum(ll p)
    {
        return nodes[p].sum;
    }

    ll &getMaxL(ll p)
    {
        return nodes[p].maxL;
    }

    ll &getMaxR(ll p)
    {
        return nodes[p].maxR;
    }

    ll &getMinL(ll p)
    {
        return nodes[p].minL;
    }

    ll &getMinR(ll p)
    {
        return nodes[p].minR;
    }

    ll &getMax(ll p)
    {
        return nodes[p].mx;
    }

    void build(ll l,ll r,ll p,ll a[])
    {
        nodes[p].l=l;
        nodes[p].r=r;
        if (l==r)
        {
            getSum(p)=a[l];
            getMaxL(p)=getMaxR(p)=max(a[l],1LL);
            getMinL(p)=getMinR(p)=min(a[l],1LL);
            getMax(p)=max(a[l],1LL);
            return;
        }
        ll mid=(l+r)>>1;
        build(l,mid,p<<1,a);
        build(mid+1,r,p<<1|1,a);
        setUp(p);
    }

    void setUp(ll p)
    {
        getSum(p)=check(getSum(p<<1)*getSum(p<<1|1));
        getMaxL(p)=check(max(getMaxL(p<<1),max(getMaxL(p<<1|1)*getSum(p<<1),getMinL(p<<1|1)*getSum(p<<1))));
        getMinL(p)=check(min(getMinL(p<<1),min(getMaxL(p<<1|1)*getSum(p<<1),getMinL(p<<1|1)*getSum(p<<1))));
        getMaxR(p)=check(max(getMaxR(p<<1|1),max(getMaxR(p<<1)*getSum(p<<1|1),getMinR(p<<1)*getSum(p<<1|1))));
        getMinR(p)=check(min(getMinR(p<<1|1),min(getMaxR(p<<1)*getSum(p<<1|1),getMinR(p<<1)*getSum(p<<1|1))));
        getMax(p)=check(max(getMax(p<<1),getMax(p<<1|1)));
        getMax(p)=check(max(getMax(p),getMaxR(p<<1)*getMaxL(p<<1|1)));
        getMax(p)=check(max(getMax(p),getMinR(p<<1)*getMinL(p<<1|1)));
    }

    void set(ll id,ll vault,ll p)
    {
        if (nodes[p].l==nodes[p].r&&nodes[p].l==id)
        {
            getSum(p)=vault;
            getMaxL(p)=getMaxR(p)=max(vault,1LL);
            getMinL(p)=getMinR(p)=min(vault,1LL);
            getMax(p)=max(vault,1LL);
            return;
        }

        ll mid=(getL(p)+getR(p))>>1;
        if (id<=mid)
        {
            set(id,vault,p<<1);
        }
        else
        {
            set(id,vault,p<<1|1);
        }
        setUp(p);
    }

    Result searchSum(ll l,ll r,ll p)
    {
        if (l<=getL(p)&&r>=getR(p))
        {
            return {getSum(p),getMaxL(p),getMaxR(p),getMinL(p),getMinR(p),getMax(p)};
        }
        if (r<getL(p)||l>getR(p))
        {
            return {1,1,1,1,1,1};
        }
        Result lResult=searchSum(l,r,p<<1);
        Result rResult=searchSum(l,r,p<<1|1);
        ll mx=max(lResult.mx,rResult.mx);
        mx=max(mx,lResult.maxR*rResult.maxL);
        mx=max(mx,lResult.minR*rResult.minL);
        return {check(lResult.sum*rResult.sum),
                check(max(lResult.maxL,max(rResult.maxL*lResult.sum,rResult.minL*lResult.sum))),
                check(max(rResult.maxR,max(lResult.maxR*rResult.sum,lResult.minR*rResult.sum))),
                check(min(lResult.minL,min(rResult.maxL*lResult.sum,rResult.minL*lResult.sum))),
                check(min(rResult.minR,min(lResult.maxR*rResult.sum,lResult.minR*rResult.sum))),
                check(mx)};
    }
};

SegmentTree<100005> tree;
ll a[100005]={};

int main()
{
    /*
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
     */
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    tree.build(1,n,1,a);
    while (q--)
    {
        ll op,x,y;
        cin>>op>>x>>y;
        if (--op)
        {
            ll ans=tree.searchSum(x,y,1).mx;
            if (ans>MAX)
            {
                cout<<"Too large\n";
            }
            else
            {
                cout<<ans<<'\n';
            }
        }
        else
        {
            tree.set(x,y,1);
        }
    }
    return 0;
}