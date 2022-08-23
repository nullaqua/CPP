#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P1083

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int edge[1000005];
int sum[4000005],tag[4000005];

struct SegmentTree
{
    void setUp(int p)
    {
        sum[p]=min(sum[p<<1],sum[p<<1|1]);
    }

    void addTag(int p,int k)
    {
        sum[p]-=k;
        tag[p]+=k;
    }

    void moveTag(int p)
    {
        if (tag[p])
        {
            addTag(p<<1,tag[p]);
            addTag(p<<1|1,tag[p]);
            tag[p]=0;
        }
    }

    void build(int p,int l,int r)
    {
        if (l==r)
        {
            sum[p]=edge[l];
            return;
        }
        int mid=l+r>>1;
        build(p<<1,l,mid);
        build(p<<1|1,mid+1,r);
        setUp(p);
    }

    void add(int p,int l,int r,int ql,int qr,int k)
    {
        if (ql<=l&&r<=qr)
        {
            sum[p]-=k;
            tag[p]+=k;
            return;
        }
        moveTag(p);
        int mid=l+r>>1;
        if (ql<=mid)
        {
            add(p<<1,l,mid,ql,qr,k);
        }
        if (mid<qr)
        {
            add(p<<1|1,mid+1,r,ql,qr,k);
        }
        setUp(p);
    }

    int search(int p,int l,int r,int ql,int qr)
    {
        if (ql<=l&&r<=qr)
        {
            return sum[p];
        }
        moveTag(p);
        int mid=l+r>>1;
        if (qr<=mid)
        {
            return search(p<<1,l,mid,ql,qr);
        }
        else if (ql>mid)
        {
            return search(p<<1|1,mid+1,r,ql,qr);
        }
        else
        {
            return min(search(p<<1,l,mid,ql,qr),search(p<<1|1,mid+1,r,ql,qr));
        }
    }
}tree;

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>edge[i];
    }
    tree.build(1,1,n);
    for (int i=1;i<=m;i++)
    {
        int k,l,r;
        cin>>k>>l>>r;
        if (tree.search(1,1,n,l,r)<k)
        {
            cout<<-1<<endl<<i<<endl;
            return 0;
        }
        else
        {
            tree.add(1,1,n,l,r,k);
        }
    }
    cout<<0;
    return 0;
}