#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P1514

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,m;
int ma[1500][1500];
bool vis[1500][1500];
int l[1500][1500],r[1500][1500];
int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};

void dfs(int x,int y)
{
    vis[x][y]=true;
    for (int i=0;i<4;i++)
    {
        int xx=x+dy[i],yy=y+dx[i];
        if (xx<1||xx>n||yy<1||yy>m||ma[xx][yy]>=ma[x][y])
        {
            continue;
        }
        if (!vis[xx][yy])
        {
            dfs(xx,yy);
        }
        l[x][y]=min(l[x][y],l[xx][yy]);
        r[x][y]=max(r[x][y],r[xx][yy]);
    }
}

struct Node
{
    int l,r;

    Node(int l=0,int r=0) : l(l),r(r)
    {
    }
}segment[1500];

int cnt;

int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>ma[i][j];
        }
    }
    memset(l,127,sizeof(l));
    for (int i=1;i<=m;i++)
    {
        l[n][i]=r[n][i]=i;
    }
    for (int i=1;i<=m;i++)
    {
        if (!vis[1][i])
        {
            dfs(1,i);
        }
    }
    int flag=0;
    for (int i=1;i<=m;i++)
    {
        if (!vis[n][i])
        {
            flag++;
        }
        if (r[1][i])
        {
            segment[++cnt]=Node(l[1][i]-1,r[1][i]);
        }
    }
    if (flag)
    {
        cout<<0<<'\n'<<flag;
        return 0;
    }
    int ans=0,x=0,y=0;
    for (int i=1;i<=cnt;i++)
    {
        if (segment[i].l>x)
        {
            ans++;
            x=y;
        }
        y=max(y,segment[i].r);
    }
    cout<<1<<'\n'<<ans+(x<m);
    return 0;
}