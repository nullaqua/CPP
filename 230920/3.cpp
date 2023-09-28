#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/3

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;

#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define N int(1005)

int n;
int a[N];
int b[N];
vector<pii> ans;

int getnxt(int i)
{
    rep (j,i,n) if (a[j]==b[i]) return j;
    return -1;
}

bool work(int x,int y,int k)
{
    per (i,y,x)
    {
        if (a[i]<=k) return true;
        ans.emplace_back(i,i+1);
        swap(a[i],a[i+1]);
    }
    return false;
}

void run()
{
    cin>>n;
    rep (i,1,n) cin>>a[i];
    rep (i,1,n) cin>>b[i];
    ans.clear();

    rep (i,1,n)
    {
        if (a[i]==b[i]) continue;
        int nxt=getnxt(i);
        if (work(i,nxt-1,b[i])) {cout<<"-1\n";return;}
    }
    cout<<"0\n";
    cout<<ans.size()<<'\n';
    for (auto [x,y]:ans) cout<<x<<' '<<y<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while (T--) run();
    return 0;
}