#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P5656

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll xx=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return xx;
}

int main()
{
    ll T;
    cin>>T;
    while (T--)
    {
        ll x=0,y=0,a,b,c,g,minX,minY,maxX,maxY,cnt=0,k;
        cin>>a>>b>>c;
        g=__gcd(a,b);
        if (c%g!=0)
        {
            cout<<"-1\n";
            continue;
        }
        a/=g;
        b/=g;
        c/=g;
        exgcd(a,b,x,y);
        x*=c;
        y*=c;
        for (int i=1;i<=2;i++)
        {
            if (x<=0)
            {
                k=-(x/b)+1;
                x+=k*b;
                y-=k*a;
                minX=x;
                maxY=y;
            }
            else if (y<=0)
            {
                k=-(y/a)+1;
                x-=k*b;
                y+=k*a;
                minY=y;
                maxX=x;
            }
        }
        if (x>0&&y>0)
        {
            if (x%b!=0)
            {
                minX=x%b;
                maxY=y+a*(x/b);
            }
            else
            {
                minX=x%b+b;
                maxY=y+a*(x/b-1);
            }
            if (y%a!=0)
            {
                minY=y%a;
                maxX=x+b*(y/a);
            }
            else
            {
                minY=y%a+a;
                maxX=x+b*(y/a-1);
            }
            cnt=(maxX-minX)/b+1;
        }
        if (cnt>0)
        {
            cout<<cnt<<' '<<minX<<' '<<minY<<' '<<maxX<<' '<<maxY<<'\n';
        }
        else
        {
            cout<<minX<<' '<<minY<<'\n';
        }
    }
    return 0;
}