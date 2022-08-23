#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P4185

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template<typename T1>
bool isSameType(const T1 a,const T1 b)
{
    return true;
}

template<typename T1,typename T2>
bool isSameType(const T1 a,const T2 b)
{
    return false;
}

struct
{
    ll u,v,w;

    template<typename type>
    bool operator<(type &tmp) const
    {
        if (isSameType(*this,tmp))
        {
            return w>tmp.w;
        }
        return false;
    }
}edge[100005];

struct
{
    ll k,v,id;

    template<typename type>
    bool operator<(const type &tmp) const
    {
        if (isSameType(*this,tmp))
        {
            return k>tmp.k;
        }
        return false;
    }
}query[100005];

ll fa[100005],size[100005],ans[100005];

ll father(ll x)
{
    if (x==fa[x]||fa[x]==0)
    {
        return x;
    }
    return fa[x]=father(fa[x]);
}

int main()
{
    ll n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++)
    {
        size[i]=1;
    }
    for (int i=1;i<n;i++)
    {
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    for (int i=1;i<=q;i++)
    {
        cin>>query[i].k>>query[i].v;
        query[i].id=i;
    }
    sort(edge+1,edge+n+1);
    sort(query+1,query+q+1);
    ll j=1;
    for (int i=1;i<=q;i++)
    {
        while (edge[j].w>=query[i].k&&j<n)
        {
            ll x=father(edge[j].u);
            ll y=father(edge[j].v);
            fa[x]=y;
            size[y]+=size[x];
            size[x]=0;
            j++;
        }
        (ans[query[i].id]=size[father(query[i].v)])--;
    }
    for (int i=1;i<=q;i++)
    {
        cout<<ans[i]<<'\n';
    }
    return 0;
}