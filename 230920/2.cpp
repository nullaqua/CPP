#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/2

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define N int(1e6+5)

int n;
int a[N];
int v[2*N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    rep (i,1,n) cin>>a[i];

    ll tmp=0;
    int cnt=0;
    rep (i,1,n)
    {
        if (i>=a[i])
        {
            tmp+=i-a[i];
        }
        else
        {
            v[a[i]-i]++;
            tmp+=a[i]-i;
            cnt++;
        }
    }
    cerr<<tmp<<' '<<cnt<<'\n';
    ll ans=tmp;
    int ans0=0;
    rep (i,1,n)
    {
        tmp-=cnt;
        tmp+=n-cnt;
        tmp+=abs(a[n-i+1]-1)-abs(a[n-i+1]-(n+1));
        if (a[n-i+1]!=1) v[a[n-i+1]-1+i]++,cnt++;//v[n-a[i]].push_back(i);
        cnt-=v[i];
        if (tmp<ans) ans=tmp,ans0=i;
        cerr<<i<<' '<<tmp<<' '<<cnt<<'\n';
    }
    cout<<ans<<' '<<ans0;
    return 0;
}