#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN=4000000;

struct Tree
{
    struct Node
    {
        ll lc,rc;
        ll l,r;
        ll tag;
        ll sum;

        Node(ll l=0,ll r=0) : l(l),r(r)
        {
            lc=rc=0;
            sum=tag=0;
        }

    }node[MAXN];

    ll ed;


    Tree &init(ll size)
    {
        node[1]=Node(0,size);
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
        node[p].sum+=tag*(node[p].r-node[p].l+1);
        node[p].tag+=tag;
    }

    void setUp(ll p)
    {
        ll lc=node[p].lc;
        ll rc=node[p].rc;
        node[p].sum=node[lc].sum+node[rc].sum;
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
        //cout<<p<<' '<<node[p].l<<' '<<node[p].r<<'\n';
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

    ll searchSum(ll l,ll r)
    {
        return searchSum(1,l,r);
    }

    ll searchSum(ll p,ll l,ll r)
    {
        if (node[p].l>r||node[p].r<l)
        {
            return 0;
        }

        if (node[p].l>=l&&node[p].r<=r)
        {
            return node[p].sum;
        }

        moveTag(p);

        return searchSum(node[p].lc,l,r)+searchSum(node[p].rc,l,r);
    }

    ll searchId(ll x)
    {
        return searchId(1,x);
    }

    ll searchId(ll p,ll x)
    {
        //cout<<p<<' '<<node[p].l<<' '<<node[p].r<<':'<<x<<'\n';
        if (node[p].l==node[p].r)
        {
            if (node[p].sum)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }

        moveTag(p);

        if (x<=(node[p].l+node[p].r)>>1)
        {
            return searchId(node[p].lc,x);
        }
        else
        {
            ll id=searchId(node[p].rc,x);
            return id==-1?id:id+node[node[p].lc].sum;
        }
    }

    ll searchX(ll id)
    {
        return searchX(1,id);
    }

    ll searchX(ll p,ll id)
    {
        if (id>node[p].sum)
        {
            return -1;
        }
        if (node[p].l==node[p].r)
        {
            return node[p].l;
        }

        moveTag(p);

        ll lc=node[p].lc;
        ll rc=node[p].rc;

        if (node[lc].sum>=id)
        {
            return searchX(lc,id);
        }
        else
        {
            return searchX(rc,id-node[lc].sum);
        }
    }

    Tree &remove(ll x)
    {
        return remove(1,x);
    }

    Tree &remove(ll p,ll x)
    {
        if (node[p].l==x&&node[p].r==x)
        {
            if (node[p].sum)
            {
                node[p].sum--;
            }
            return *this;
        }

        if (node[p].l>x||node[p].r<x)
        {
            return *this;
        }

        moveTag(p);

        remove(node[p].lc,x);
        remove(node[p].rc,x);

        setUp(p);

        return *this;
    }

    Tree &removeAll(ll x)
    {
        return removeAll(1,x);
    }

    Tree &removeAll(ll p,ll x)
    {
        //cout<<p<<' '<<node[p].l<<' '<<node[p].r<<':'<<x<<'\n';
        if (node[p].l==x&&node[p].r==x)
        {
            //cout<<"Get!\n";
            node[p].sum=0;
            return *this;
        }

        if (node[p].l>x||node[p].r<x)
        {
            return *this;
        }

        moveTag(p);

        removeAll(node[p].lc,x);
        removeAll(node[p].rc,x);

        setUp(p);

        return *this;
    }
}tree;

int main()
{
    return 0;
}