#include <bits/stdc++.h>
#define int long long
//https://www.luogu.com.cn/problem/CF1106E

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n,m,k;

struct RedBag
{
    ll s,t,d,w;

    bool operator<(const RedBag &o) const
    {
        return o.w!=w?w<o.w:d>o.d;
    }
};

RedBag bags[100005];

ll dp[100005][305];

signed main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=k;i++)
    {
        cin>>bags[i].s>>bags[i].t>>bags[i].d>>bags[i].w;
    }
    sort(bags+1,bags+k+1,[](RedBag a,RedBag b)->bool
    {
        return a.s<b.s;
    });
    priority_queue<RedBag> que;
    int ed=1;
    memset(dp,0x3f,sizeof dp);
    dp[1][0]=0;

    ll ans=1e18;
    for (int i=1;i<=n;i++)
    {
        if (ed<=k&&bags[ed].s<=i)
        {
            que.push(bags[ed++]);
        }
        while (!que.empty()&&que.top().t<i)
        {
            que.pop();
        }

        RedBag b{};
        if (!que.empty())
        {
            b=que.top();
        }
        for (int j=0;j<=m;j++)
        {
            cerr<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
            if (que.empty())
            {
                //cout<<i<<' '<<j<<"to"<<i+1<<' '<<j<<"type1"<<'\n';
                if (i+1>n)
                {
                    ans=min(ans,dp[i][j]);
                }
                else
                {
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
                }
                continue;
            }

            //cout<<i<<' '<<j<<"to"<<i+1<<' '<<j+1<<"type2"<<'\n';
            if (i+1>n&&j<m)
            {
                ans=min(ans,dp[i][j]);
            }
            else
            {
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
            }
            //cout<<i<<' '<<j<<"to"<<i+b.d-1<<' '<<j<<"type3"<<'\n';
            if (i+b.d>n)
            {
                ans=min(ans,dp[i][j]+b.w);
            }
            else
            {
                dp[i+b.d][j]=min(dp[i+b.d][j],dp[i][j]+b.w);
            }
        }
    }
    cout<<ans;
    return 0;
}