#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P2540

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=25;

int cnt[N];
int dp[N][N][N][N];

int dfs(int n1,int n2,int n3,int n4)
{
    if (dp[n1][n2][n3][n4]!=-1)
    {
        return dp[n1][n2][n3][n4];
    }
    int ans=n1+n2+n3+n4;
    if (n1)
    {
        ans=min(ans,dfs(n1-1,n2,n3,n4)+1);
    }
    if (n2)
    {
        ans=min(ans,dfs(n1,n2-1,n3,n4)+1);
        ans=min(ans,dfs(n1+2,n2-1,n3,n4));
    }
    if (n3)
    {
        ans=min(ans,dfs(n1,n2,n3-1,n4)+1);
        if (n1)
        {
            ans=min(ans,dfs(n1-1,n2,n3-1,n4)+1);
        }
        if (n2)
        {
            ans=min(ans,dfs(n1,n2-1,n3-1,n4)+1);
        }
        ans=min(ans,dfs(n1+1,n2+1,n3-1,n4));
    }
    if (n4)
    {
        ans=min(ans,dfs(n1,n2,n3,n4-1)+1);
        if (n1>=2)
        {
            ans=min(ans,dfs(n1-2,n2,n3,n4-1)+1);
        }
        if (n2)
        {
            ans=min(ans,dfs(n1,n2-1,n3,n4-1)+1);
        }
        if (n2>=2)
        {
            ans=min(ans,dfs(n1,n2-2,n3,n4-1)+1);
        }
        ans=min(ans,dfs(n1+1,n2,n3+1,n4-1));
        ans=min(ans,dfs(n1,n2+2,n3,n4-1));
    }
    return dp[n1][n2][n3][n4]=ans;
}

int getAns()
{
    int n1=0,n2=0,n3=0,n4=0,ans=1e9;
    for (int i=1;i<=16;i++)
    {
        if (cnt[i]==1)
        {
            n1++;
        }
        else if (cnt[i]==2)
        {
            n2++;
        }
        else if (cnt[i]==3)
        {
            n3++;
        }
        else if (cnt[i]==4)
        {
            n4++;
        }
    }
    ans=dfs(n1,n2,n3,n4);
    int len=0;
    for (int i=3;i<=14;i++)
    {
        for (int k=1;k<=3;k++)
        {
            if (k==1)
            {
                len=5;
            }
            else if (k==2)
            {
                len=3;
            }
            else
            {
                len=2;
            }
            for (int j=i+len-1;j<=14;j++)
            {
                bool flag=true;
                for (int kk=i;kk<=j&&flag;kk++)
                {
                    if (cnt[kk]<k)
                    {
                        flag=false;
                    }
                }
                if (!flag)
                {
                    continue;
                }
                for (int p=i;p<=j;p++)
                {
                    cnt[p]-=k;
                }
                ans=min(ans,getAns()+1);
                for (int p=i;p<=j;p++)
                {
                    cnt[p]+=k;
                }
            }
        }
    }
    return ans;
}

int main()
{
    int T,n;
    cin>>T>>n;
    memset(dp,-1,sizeof dp);
    while (T--)
    {
        memset(cnt,0,sizeof cnt);
        for (int i=1;i<=n;i++)
        {
            int a,b;
            cin>>a>>b;
            if (a==0)
            {
                if (b==1)
                {
                    cnt[15]++;
                }
                else
                {
                    cnt[16]++;
                }
            }
            else if (a==1)
            {
                cnt[14]++;
            }
            else
            {
                cnt[a]++;
            }
        }
        int ans=getAns();
        if (cnt[15]&&cnt[16])
        {
            cnt[15]--;
            cnt[16]--;
            ans=min(ans,getAns()+1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}