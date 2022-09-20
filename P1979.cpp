#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P1979

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};

ll n,m,Q,ex,ey,sx,sy,tx,ty;
bool a[35][35];
ll b[35][35][4][4];
ll c[35][35];
ll d[35][35][4];

void bfs(ll sxx,ll syy)
{
    memset(c,0x3f,sizeof c);
    queue<ll> q;
    c[sxx][syy]=0;
    q.push(sxx);
    q.push(syy);
    while (!q.empty())
    {
        ll x=q.front();
        q.pop();
        ll y=q.front();
        q.pop();
        for (int k=0;k<4;k++)
        {
            ll xx=x+dx[k],yy=y+dy[k];
            if (xx<1||xx>n||yy<1||yy>m||a[xx][yy]||c[xx][yy]!=0x3f3f3f3f3f3f3f3f)
            {
                continue;
            }
            c[xx][yy]=c[x][y]+1;
            q.push(xx);
            q.push(yy);
        }
    }
}

void spfa()
{
    memset(d,0x3f,sizeof d);
    queue<ll> q;
    a[sx][sy]=true;
    bfs(ex,ey);
    a[sx][sy]=false;
    for (int k=0;k<4;k++)
    {
        ll xx=sx+dx[k];
        ll yy=sy+dy[k];
        if (c[xx][yy]==0x3f3f3f3f3f3f3f3f)
        {
            continue;
        }
        d[sx][sy][k]=c[xx][yy];
        q.push(sx);
        q.push(sy);
        q.push(k);
    }
    while (!q.empty())
    {
        ll x=q.front();
        q.pop();
        ll y=q.front();
        q.pop();
        ll k1=q.front();
        q.pop();
        ll xx=x+dx[k1],yy=y+dy[k1];
        if (xx>=1&&xx<=n&&yy>=1&&yy<=m&&!a[xx][yy]&&d[xx][yy][k1^1]>d[x][y][k1]+1)
        {
            d[xx][yy][k1^1]=d[x][y][k1]+1;
            q.push(xx);
            q.push(yy);
            q.push(k1^1);
        }
        for (int k2=0;k2<4;k2++)
        {
            xx=x+dx[k2];
            yy=y+dy[k2];
            if (xx<1||xx>n||yy<1||yy>m||a[xx][yy])
            {
                continue;
            }
            if (d[x][y][k2]>d[x][y][k1]+b[x][y][k1][k2])
            {
                d[x][y][k2]=d[x][y][k1]+b[x][y][k1][k2];
                q.push(x);
                q.push(y);
                q.push(k2);
            }
        }
    }
}

int main()
{
    cin>>n>>m>>Q;
    for (int i=1;i<=n;i++)
    {
        for (int j=1,x;j<=m;j++)
        {
            cin>>x;
            a[i][j]=x^1;
        }
    }
    memset(b,0x3f,sizeof b);
    for (int x=1;x<=n;x++)
    {
        for (int y=1;y<=m;y++)
        {
            if (a[x][y])
            {
                continue;
            }
            for (int k1=0;k1<4;k1++)
            {
                ll xx=x+dx[k1],yy=y+dy[k1];
                if (xx<1||xx>n||yy<1||yy>m||a[xx][yy])
                {
                    continue;
                }
                a[x][y]=true;
                bfs(xx,yy);
                a[x][y]=false;
                for (int k2=0;k2<4;k2++)
                {
                    ll xxx=x+dx[k2],yyy=y+dy[k2];
                    if (xxx<1||xxx>n||yyy<1||yyy>m&&a[xxx][yyy])
                    {
                        continue;
                    }
                    b[x][y][k1][k2]=c[xxx][yyy];
                }
            }
        }
    }
    while (Q--)
    {
        cin>>ex>>ey>>sx>>sy>>tx>>ty;
        if (sx==tx&&sy==ty)
        {
            cout<<0<<'\n';
            continue;
        }
        spfa();
        ll ans=0x3f3f3f3f3f3f3f3f;
        for (int k=0;k<4;k++)
        {
            ans=min(ans,d[tx][ty][k]);
        }
        cout<<(ans==0x3f3f3f3f3f3f3f3f?-1:ans)<<'\n';
    }
    return 0;
}