#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P1941

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,m,k;
ll dp[1005];
ll vv[1005];

struct Map
{
    int up,dn;
    int lu,ld;
    bool has;

    Map(int up=0,int dn=0,int lu=1e9,int ld=0) : up(up),dn(dn),lu(lu),ld(ld),has(false)
    {
    }
}mp[10005];

int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        mp[i].up=x;
        mp[i].dn=y;
    }
    for (int i=0;i<k;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        mp[x].lu=z;
        mp[x].ld=y;
        mp[x].has=true;
    }

    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        memset(vv,0x3f,sizeof vv);
        for (int j=0;j<=m;j++)
        {
            if (j-mp[i].dn>=0)
            {
                vv[j-mp[i].dn]=min(vv[j-mp[i].dn],dp[j]);
            }
            vv[min(j+mp[i].up,m)]=min(vv[min(j+mp[i].up,m)],min(vv[j],dp[j])+1);
        }
        bool flag=true;
        for (int j=0;j<=m;j++)
        {
            if (j<=mp[i].ld||j>=mp[i].lu||vv[j]>=(ll)1e9)
            {
                dp[j]=1e9;
                continue;
            }
            dp[j]=vv[j];
            flag=false;
        }
        if (flag)
        {
            cout<<"0\n"<<cnt;
            return 0;
        }
        if (mp[i].has)
        {
            cnt++;
        }
    }
    ll ans=1e9;
    for (int i=1;i<=m;i++)
    {
        ans=min(ans,dp[i]);
    }
    cout<<"1\n"<<ans;
    return 0;
}