#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/CF888F
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef __int128 lll;
typedef unsigned __int128 ulll;
typedef pair<int,int> pii;
typedef pair <ll,ll> pll;

#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define edge(i,x) for (auto i=head[x];i;i=i->nxt)
#define addE(x,y) head[x]=new EDGE(y,head[x])
#define addEV(x,y,z) head[x]=new EDGE(y,z,head[x])
#define addDE(x,y) addE(x,y),addE(y,x)
#define addDEV(x,y,z) addEV(x,y,z),addEV(y,x,z)

#define N 500

bool b[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    
    return 0;
}