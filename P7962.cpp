#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P7962
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef __int128 lll;
typedef unsigned __int128 ulll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define edge(i,x) for (auto i=head[x];i;i=i->nxt)
#define addE(x,y) head[x]=new EDGE(y,head[x])
#define addEV(x,y,z) head[x]=new EDGE(y,z,head[x])
#define addDE(x,y) addE(x,y),addE(y,x)
#define addDEV(x,y,z) addEV(x,y,z),addEV(y,x,z)

#define N int(10005)

int n;
int a[N];

deque<int> q;
int mid;

void init()
{
    rep (i,1,n)
    {
        if (i&1) q.push_back(a[i]);
        else q.push_front(a[i]),mid++;
    }
}

int ans=1e9;

void update()
{
    int sum=0;
    int tmp=0;
    int tmp2=0;
    rep (i,0,n-1) (tmp+=q[i]),sum+=tmp,tmp2+=tmp*tmp*(n+1);
    ans=min(ans,tmp2-sum*sum);
}

void mv(int i)
{
    if (i<mid)
    {
        int x=q[i];
        q.erase(q.begin()+i);
        mid--;
        q.insert(lower_bound(q.begin()+mid,q.end(),x),x);
    }
    else
    {
        int x=q[i];
        q.erase(q.begin()+i);
        q.insert(upper_bound(q.begin(),q.begin()+mid,x,greater<>()),x);
        mid++;
    }
}

void SA()
{
    double T=2e5;
    double delta=0.97;
    while (T>1e-5)
    {
        int x=rand()%(n-1);
        if (x<mid) mv(x);
        else mv(x+1);
        update();
        T*=delta;
    }
}

struct test
{
    test operator ++()
    {
        cout<<"++i\n";
        return *this;
    }

    test operator ++(int)
    {
        cout<<"i++\n";
        return *this;
    }

    test operator *()
    {
        cout<<"*\n";
        return *this;
    }

    test operator *(int)
    {
        cout<<"*int\n";
        return *this;
    }
};

int main()
{
    test x;
    x++;
    ++x;
    *x;
    x*1;
}