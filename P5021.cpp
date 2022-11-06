#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P5021

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct EDGE
{
    int v,w,next;
}edge[100005];
int ed;
int head[50004];

void addEdge(int u,int v,int w)
{
    edge[++ed].v=v;
    edge[ed].w=w;
    edge[ed].next=head[u];
    head[u]=ed;
}

int n,m;

bool check(int x)
{
    
}

int main()
{
    cin>>n>>m;
    for (int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(u,v,w);
        addEdge(v,u,w);
    }

    int l=0,r=1e9;

    while (l<r)
    {
        int mid=(l+r)>>1;
        if (check(mid))
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<l-1;
    return 0;
}