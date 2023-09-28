#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define N int(1e6+5)
ll n,a[N];
#define del(x) int(x?((x)>>1)+1:0)
int main()
{
    cin>>n;
    bool flag=true;
    rep (i,1,n) cin>>a[i],flag&=(a[i]<=0);
    if (flag)
    {
        ll mx=*max_element(a+1,a+1+n);
        int op=1e9;
        rep (i,1,n) if (a[i]==mx) op=min(op,del(i-1)+del(n-i));
        cout<<mx<<'\n'<<op;
        return 0;
    }
    ll mx[2]{};
    int op[2]{};
    int last=1;
    for(int id=1;id<=2;id++)
    {
        for (int i=id;i<=n;i+=2) if (a[i]>0)
        {
            mx[id-1]+=a[i];
            op[id-1]+=del(i-last);
            last=i+1;
        }
        op[id-1]+=del(n-last+1);
    }
    if (mx[0]>mx[1]) cout<<mx[0]<<'\n'<<op[0];
    else if (mx[0]<mx[1]) cout<<mx[1]<<'\n'<<op[1];
    else cout<<mx[0]<<'\n'<<min(op[0],op[1]);
    return 0;
}