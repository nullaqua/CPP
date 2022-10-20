#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P3986

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ll n,ans=0;
    ll tx,ty,fx,fy,sx,sy;
    cin>>n;
    ll p0=1,p1=1,x=0,y=1;
    while (p0+p1<=n)
    {
        tx=1ll*x*n,ty=1ll*y*n;
        fx=tx%p1;
        if (fx<=0)
        {
            fx+=p1;
        }
        fy=ty-(fx-tx)/p1*p0;
        sy=ty%p0;
        if (sy<=0)
        {
            sy+=p0;
        }
        sx=tx-(sy-ty)/p0*p1;
        if (fy<=0||sx<=0)
        {
            break;
        }
        ans+=(sx-fx)/p1+1;
        ans%=ll(1e9+7);
        p1=p0+p1;
        p0=p1-p0;
        x=y-x;
        y=y-x;
    }
    cout<<ans;
    return 0;
}