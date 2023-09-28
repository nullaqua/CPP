#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/U104822
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef __int128 lll;
typedef unsigned __int128 ulll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define edge(i,x) for (auto i=head[x];i;i=i->nxt)
#define addE(x,y) head[x]=new EDGE(y,head[x])
#define addEV(x,y,z) head[x]=new EDGE(y,z,head[x])
#define addDE(x,y) addE(x,y),addE(y,x)
#define addDEV(x,y,z) addEV(x,y,z),addEV(y,x,z)

#define N int(2005)

int n,m,tp;
int a[N];
int b[N];
int dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m>>tp;
    per (i,n,1) cin>>a[i];
    per (i,m,1) cin>>b[i];

    rep (i,1,n)
    {
        rep (j,1,m)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if (a[i]==b[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    return 0;
}