#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/cyclepath

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct EDGE
{
    int v,w,next;
}edge[3005];
int ed;
int head[3005];
void add(int u,int v,int w)
{
    edge[++ed].v=v;
    edge[ed].w=w;
    edge[ed].next=head[u];
    head[u]=ed;
}

int n,m;
ll d[3005][3005];
bool vis[3005][3005];

struct Node
{
    int u,k;
    ll len;
    Node(int u,int k,ll len):u(u),k(k),len(len){}
    bool operator<(const Node &o)const
    {
        return o.len<len;
    }
};

void dij()
{
    priority_queue<Node> q;
    q.emplace(1,1,0LL);
    while (q.size())
    {
        int u=q.top().u;
        int k=q.top().k;
        q.pop();
        if (vis[u][k])
        {
            continue;
        }
        vis[u][k]=true;
        for (int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].v;
            ll w=edge[i].w;
            if (d[v][0]>d[u][k]+w&&k==v)
            {
                d[v][0]=d[u][k]+w;
                q.emplace(v,0,d[v][0]);
            }
            if (d[v][k]>d[u][k]+w)
            {
                d[v][k]=d[u][k]+w;
                q.emplace(v,k,d[v][k]);
            }
            if (d[v][v]>d[u][k]+w)
            {
                d[v][v]=d[u][k]+w;
                q.emplace(v,v,d[v][v]);
            }
        }
    }
}

int main()
{
    int cnt=0;
    int sum=1;
    int c=clock()+1000;
    while (clock()<=c)
    {
        ++cnt;
        if (cnt&1)
        {
            sum*=2;
        }
        else
        {
            sum/=2;
        }
    }
    cerr<<cnt<<' '<<sum;
    return 0;
}