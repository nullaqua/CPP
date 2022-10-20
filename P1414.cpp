#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P1414

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int n,a[1000010]={};
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for (int j=1;j*j<=x;j++)
        {
            if (x%j)
            {
                continue;
            }
            a[j]++;
            if (x!=j*j)
            {
                a[x/j]++;
            }
        }
    }
    int ans=1e6+5;
    for (int i=1;i<=n;i++)
    {
        while (a[ans]<i)
        {
            ans--;
        }
        cout<<ans<<'\n';
    }
    return 0;
}