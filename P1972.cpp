#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P1972

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template<int Size>
struct Tree
{
    struct Node
    {
        int lc,rc;
        int l,r;
        int tag;
        int sum;

        Node(int l=0,int r=0) : l(l),r(r)
        {
            lc=rc=0;
            sum=tag=0;
        }

    }node[Size];

    int ed=1;


    Tree &init(int size)
    {
        node[1]=Node(0,size);
        ed=1;
        return *this;
    }

    int buildNode(int l,int r)
    {
        ++ed;
        node[ed]=Node(l,r);
        return ed;
    }

    void addTag(int p,int tag)
    {
        node[p].sum+=tag*(node[p].r-node[p].l+1);
        node[p].tag+=tag;
    }

    void setUp(int p)
    {
        int lc=node[p].lc;
        int rc=node[p].rc;
        node[p].sum=node[lc].sum+node[rc].sum;
    }

    Tree &moveTag(int p)
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

    Tree &add(int l,int r,int cnt)
    {
        return add(1,l,r,cnt);
    }

    Tree &add(int p,int l,int r,int cnt)
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

    int searchSum(int l,int r)
    {
        return searchSum(1,l,r);
    }

    int searchSum(int p,int l,int r)
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

    int searchId(int x)
    {
        return searchId(1,x);
    }

    int searchId(int p,int x)
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
            int id=searchId(node[p].rc,x);
            return id==-1?id:id+node[node[p].lc].sum;
        }
    }

    int searchX(int id)
    {
        return searchX(1,id);
    }

    int searchX(int p,int id)
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

        int lc=node[p].lc;
        int rc=node[p].rc;

        if (node[lc].sum>=id)
        {
            return searchX(lc,id);
        }
        else
        {
            return searchX(rc,id-node[lc].sum);
        }
    }

    Tree &remove(int x)
    {
        return remove(1,x);
    }

    Tree &remove(int p,int x)
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

    Tree &removeAll(int x)
    {
        return removeAll(1,x);
    }

    Tree &removeAll(int p,int x)
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
};

int n,m;
int a[1000006];
int v[1000006];
int pre[1000006];

int ans[1000006];

struct Q
{
    int id,l,r;
}qs[1000006];

Tree<4000000> tree;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    tree.init(n);
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=v[a[i]];
        v[a[i]]=i;
        //cout<<pre[i]<<' ';
    }
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        qs[i].id=i;
        cin>>qs[i].l>>qs[i].r;
    }
    sort(qs+1,qs+m+1,[](Q a,Q b)->bool
    {
        return a.r<b.r;
    });
    int r=0;
    for (int i=1;i<=m;i++)
    {
        while (r<qs[i].r)
        {
            if (pre[++r]!=0)
            {
                tree.add(pre[r],pre[r],-1);
            }
            tree.add(r,r,1);
        }
        ans[qs[i].id]=tree.searchSum(qs[i].l,qs[i].r);
    }

    for (int i=1;i<=m;i++)
    {
        cout<<ans[i]<<'\n';
    }
    return 0;
}