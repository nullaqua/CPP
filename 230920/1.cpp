#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/1

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define N int(5e5+5)

int n,len;
ll a[N];
ll pr[N];
double mx[N];
int pos[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>len;
    rep (i,1,n) cin>>a[i],pr[i]=pr[i-1]+a[i];
    mx[n]=a[n];
    pos[n]=1;
    per (i,n-1,1)
    {
        if (a[i]>mx[i+1]) mx[i]=a[i],pos[i]=1;
        else mx[i]=(mx[i+1]*pos[i+1]+a[i])/double(pos[i+1]+1),pos[i]=pos[i+1]+1;
        cerr<<mx[i]<<' '<<pos[i]<<endl;
    }
    double ans=-1e9;
    rep (i,0,n-len)
    {
        double tmp=(pr[i+len-1]-pr[i]+mx[i+len]*pos[i+len])/double(len+pos[i+len]-1);
        ans=max(ans,tmp);
    }
    cout<<fixed<<setprecision(3)<<ans;
    tuple<int,int,int>x;
    return 0;
}