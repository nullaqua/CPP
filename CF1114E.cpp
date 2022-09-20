#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/CF1114E

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n,a[35],mx,c,p[1000010];

ll has(ll xx)
{
    cout<<"> "<<xx<<endl;
    cout.flush();
    cin>>xx;
    return xx;
}

ll get(ll xx)
{
    cout<<"? "<<xx<<endl;
    cout.flush();
    cin>>xx;
    return xx;
}

ll getRand()
{
    return abs(rand()*rand()*rand()*rand())%n+1;
}


ll gcd(ll xx,ll yy)
{
    return !yy?xx:gcd(yy,xx%yy);
}

int main()
{
    srand(time(0));
    cin>>n;
    int l=0,r=1e9;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (has(mid))
        {
            l=mid+1;
        }
        else
        {
            r=mid-1,mx=mid;
        }
    }
    for (int i=1;i<=n;i++)
    {
        p[i]=i;
    }
    for (int i=1;i<=n;i++)
    {
        swap(p[i],p[getRand()]);
    }
    for (int i=1;i<=min(n,30ll);i++)
    {
        a[i]=get(p[i]);
    }
    sort(a+1,a+min(n,30ll)+1);
    c=a[2]-a[1];
    for (int i=2;i<min(n,30ll);i++)
    {
        c=gcd(c,a[i+1]-a[i]);
    }
    cout<<"! "<<mx-c*(n-1)<<' '<<c<<endl;
    cout.flush();
    return 0;
}