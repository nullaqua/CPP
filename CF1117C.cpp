#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/CF1117C

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll ud[100005];
ll lr[100005];
ll sx,sy;
ll ex,ey;
ll n;

inline bool check(ll step)
{
    ll xx=(step/n)*lr[n]+lr[step%n]+sx;
    ll yy=(step/n)*ud[n]+ud[step%n]+sy;
    return abs(xx-ex)+abs(yy-ey)<=step;
}

int main()
{
    cin>>sx>>sy>>ex>>ey;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        ud[i]=ud[i-1];
        lr[i]=lr[i-1];
        char s;
        cin>>s;
        switch (s)
        {
            case 'U':
                ud[i]++;
                break;
            case 'D':
                ud[i]--;
                break;
            case 'L':
                lr[i]--;
                break;
            case 'R':
                lr[i]++;
                break;
            default:
                break;
        }
    }
    const ll maxR=1e17;
    ll l=1,r=maxR;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        if (check(mid))
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<((r==maxR)?-1:l);

    return 0;
}