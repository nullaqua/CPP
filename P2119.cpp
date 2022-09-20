#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n,m;
ll b[40005];
ll cnt[15005];
ll edge[15005];
ll c[15005];

int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>b[i];
        cnt[b[i]]++;
    }
    for (int i=1;i*9<n;i++)
    {
        ll sum=0;
        for (int j=i*9+2;j<=n;j++)
        {
            sum+=cnt[j-7*i-1]*cnt[j-9*i-1];
            edge[j-i]+=cnt[j]*sum;
            c[j]+=cnt[j-i]*sum;
        }
        sum=0;
        for (int j=n-i*9-1;j>=1;j--)
        {
            sum+=cnt[j+i*8+1]*cnt[j+i*9+1];
            edge[j]+=cnt[j+2*i]*sum;
            b[j+2*i]+=cnt[j]*sum;
        }
    }
    for (int i=1;i<=m;i++)
    {
        cout<<edge[b[i]]<<" "<<b[b[i]]<<" "<<edge[b[i]]<<" "<<c[b[i]]<<'\n';
    }
    return 0;
}