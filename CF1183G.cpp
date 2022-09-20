#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/CF1183G

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,a[200005],b[200005],c[200005];
priority_queue<int> Q;

int main()
{
    ll T;
    cin>>T;
    while (T--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            int x,y;
            cin>>x>>y;
            if (y)
            {
                a[x]++;
            }
            else
            {
                b[x]++;
            }
            c[i]=i;
        }
        while (!Q.empty())
        {
            Q.pop();
        }
        sort(c+1,c+n+1,[&](int x,int y)->bool
        {
            return a[x]+b[x]>a[y]+b[y];
        });
        int ss=1,ans=0,num=0;
        for (int i=n;i>=1;i--)
        {
            while (a[c[ss]]+b[c[ss]]>=i)
            {
                Q.push(a[c[ss]]);
                ss++;
            }
            if (Q.empty())
            {
                continue;
            }
            int v=Q.top();
            Q.pop();
            ans+=i;
            num+=min(v,i);
        }
        cout<<ans<<' '<<num<<endl;
        if (T)
        {
            for (int i=1;i<=n;i++)
            {
                a[i]=b[i]=0;
            }
        }
    }
    return 0;
}