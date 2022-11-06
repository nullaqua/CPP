#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P7914

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll mod=1e9+7;

struct Node
{
    ll A,AB,AS,SA;
    bool S;
    Node():A(0),AB(0),AS(0),SA(0),S(false)
    {
    }
}dp[505][505];

int n,m;
bool a1[505];
bool a2[505];
bool a3[505];

int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        char s;
        cin>>s;
        switch (s)
        {
            case '(':
            {
                a2[i]=true;
                break;
            }
            case ')':
            {
                a3[i]=true;
                break;
            }
            case '*':
            {
                a1[i]=true;
                break;
            }
            case '?':
            {
                a1[i]=a2[i]=a3[i]=true;
                break;
            }
            default:
            {
            }
        }
        //cout<<a1[i]<<a2[i]<<a3[i]<<'\n';
    }

    for (int len=0;len<n;len++)
    {
        for (int l=1;l+len<=n;l++)
        {
            int r=len+l;
            if (len<m)
            {
                dp[l][r].S=len>0?dp[l][r-1].S&&a1[r]:a1[l];
            }

            if (len<1)
            {
                continue;
            }
            if (len==1)
            {
                dp[l][r].A+=a2[l]&&a3[r];
            }
            else if (a2[l]&&a3[r])
            {
                dp[l][r].A+=dp[l+1][r-1].S+dp[l+1][r-1].A+dp[l+1][r-1].AS+dp[l+1][r-1].SA+dp[l+1][r-1].AB;
            }
            dp[l][r].A%=mod;
            for (int k=l;k<r;k++)
            {
                dp[l][r].AB+=dp[l][k].A*(dp[k+1][r].AB+dp[k+1][r].A);
                dp[l][r].AB+=dp[l][k].A*dp[k+1][r].SA;
                dp[l][r].AB%=mod;
                dp[l][r].SA+=dp[l][k].S*(dp[k+1][r].AB+dp[k+1][r].A);
                dp[l][r].SA%=mod;
                dp[l][r].AS+=(dp[l][k].AB+dp[l][k].A)*dp[k+1][r].S;
                dp[l][r].AS%=mod;
            }
            //cout<<l<<' '<<r<<' '<<dp[l][r].A<<' '<<dp[l][r].AB<<' '<<dp[l][r].AS<<' '<<dp[l][r].SA<<' '<<dp[l][r].S<<'\n';
        }
    }
    cout<<dp[1][n].A+dp[1][n].AB;
    return 0;
}
/*
 10 2
 ???(*??(?)

 (**(*)*())
 (**(**)())
 (()(*)*())
 (()(*?)())

 ???(*??(?)
 ???(*??(?)
*/