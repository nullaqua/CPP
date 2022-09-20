#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/U127164

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct SearchAnswer
{
    ll maxl,maxr,max;
    bool full;

    SearchAnswer(ll maxl,ll maxr,ll max,bool full) : maxl(maxl),maxr(maxr),max(max),full(full)
    {
    }
};

struct Tree
{
    struct Node
    {
        ll lc,rc;
        ll l,r;
        int tag;
        bool full;
        ll max;
        ll maxl;
        ll maxr;

        Node(ll l=0,ll r=0) : l(l),r(r)
        {
            lc=rc=0;
            full=tag=0;
            max=maxl=maxr=0;
        }
    }node[400005];

    ll ed;


    Tree &init(ll size)
    {
        node[1]=Node(1,size);
        ed=1;
        return *this;
    }

    ll buildNode(ll l,ll r)
    {
        ++ed;
        node[ed]=Node(l,r);
        return ed;
    }

    void addTag(ll p,ll tag)
    {
        if (tag==0)
        {
            return;
        }
        if (tag==1)
        {
            int len=node[p].r-node[p].l+1;
            node[p].full=true;
            node[p].max=len;
            node[p].maxl=len;
            node[p].maxr=len;
            node[p].tag=1;
        }
        else
        {
            node[p].full=false;
            node[p].max=0;
            node[p].maxl=0;
            node[p].maxr=0;
            node[p].tag=-1;
        }
    }

    void setUp(ll p)
    {
        ll lc=node[p].lc;
        ll rc=node[p].rc;
        node[p].full=node[lc].full&&node[rc].full;
        node[p].maxl=node[lc].full?node[lc].max+node[rc].maxl:node[lc].maxl;
        node[p].maxr=node[rc].full?node[rc].max+node[lc].maxr:node[rc].maxr;
        node[p].max=max(node[lc].max,node[rc].max);
        node[p].max=max(node[p].max,node[lc].maxr+node[rc].maxl);
    }

    Tree &moveTag(ll p)
    {
        if (!node[p].lc)
        {
            node[p].lc=buildNode(node[p].l,(node[p].l+node[p].r)>>1);
            //cout<<p<<"	creat left c:	"<<node[p].lc<<' '<<node[p].l<<' '<<((node[p].l+node[p].r)>>1)<<'\n';
        }
        addTag(node[p].lc,node[p].tag);

        if (!node[p].rc)
        {
            node[p].rc=buildNode(((node[p].l+node[p].r)>>1)+1,node[p].r);
            //cout<<p<<"	creat right c:	"<<node[p].rc<<' '<<(node[p].l+node[p].r>>1)+1<<' '<<node[p].r<<'\n';
        }
        addTag(node[p].rc,node[p].tag);

        node[p].tag=0;

        return *this;
    }

    Tree &add(ll l,ll r,ll cnt)
    {
        return add(1,l,r,cnt);
    }

    Tree &add(ll p,ll l,ll r,ll cnt)
    {
        if (node[p].l>r||node[p].r<l)
        {
            return *this;
        }

        if (node[p].l>=l&&node[p].r<=r)
        {
            addTag(p,cnt);
            return *this;
        }

        moveTag(p);

        add(node[p].lc,l,r,cnt);
        add(node[p].rc,l,r,cnt);

        setUp(p);

        return *this;
    }

    SearchAnswer search(ll p,ll l,ll r)
    {
        //cout<<p<<' '<<l<<' '<<r<<endl;
        if (l<=node[p].l&&r>=node[p].r)
        {
            return {node[p].maxl,node[p].maxr,node[p].max,node[p].full};
        }
        if (l>node[p].r||r<node[p].l)
        {
            return {0,0,0,false};
        }
        moveTag(p);

        SearchAnswer lAns=search(node[p].lc,l,r);
        SearchAnswer rAns=search(node[p].rc,l,r);

        ll maxl,maxr,mx;
        bool full;

        full=lAns.full&&rAns.full;
        maxl=lAns.full?lAns.max+rAns.maxl:lAns.maxl;
        maxr=rAns.full?rAns.max+lAns.maxr:rAns.maxr;
        mx=max(lAns.max,rAns.max);
        mx=max(mx,lAns.maxr+rAns.maxl);
        return {maxl,maxr,mx,full};
    }
}tree;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,q;
    cin>>n>>q;
    tree.init(n);
    ll lll=1;
    char lchar=-1;
    for (int i=1;i<=n;i++)
    {
        char ch;
        cin>>ch;
        if (ch!=lchar)
        {
            if (i!=1)
            {
                tree.add(lll,i-1,lchar=='1'?1:-1);
            }
            lchar=ch;
            lll=i;
        }
    }
    tree.add(lll,n,lchar=='1'?1:-1);
    while (q--)
    {
        ll op;
        cin>>op;
        if (--op)
        {
            ll l,r;
            cin>>l>>r;
            cout<<tree.search(1,l,r).max<<'\n';
        }
        else
        {
            ll l,r,x;
            cin>>l>>r>>x;
            tree.add(l,r,x?1:-1);
        }
    }
    return 0;
}