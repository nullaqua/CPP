#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/U127202

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

char a[10000005],b[10000005];
ll c[10000005];
int pre[10000005];
int ss[10000005];

void getString()
{
    int op;
    cin>>op;
    if (op==0)
    {
        cin>>(a+1)>>(b+1);
    }
    else
    {
        int c1,x,y,n;
        cin>>c1>>x>>y>>n;
        c[1]=c1;
        for (int i=2;i<=n;++i)
        {
            c[i]=(c[i-1]*x+y)%1000000007;
        }
        for (int i=1;i<=n;++i)
        {
            a[i]='a'+c[i]%26;
        }

        cin>>c1>>x>>y>>n;
        c[1]=c1;
        for (int i=2;i<=n;++i)
        {
            c[i]=(c[i-1]*x+y)%1000000007;
        }
        for (int i=1;i<=n;++i)
        {
            b[i]='a'+c[i]%26;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getString();

    int lena=strlen(a+1),lenb=strlen(b+1);
    for (int i=1;i<=lena;i++)
    {
        if (a[i]==b[pre[i-1]+1])
        {
            pre[i]=pre[i-1]+1;
        }
        else
        {
            pre[i]=pre[i-1];
        }
    }

    ss[lena+1]=lenb+1;
    for (int i=lena;i;i--)
    {
        if (a[i]==b[ss[i+1]-1])
        {
            ss[i]=ss[i+1]-1;
        }
        else
        {
            ss[i]=ss[i+1];
        }
    }

    int ans=1e9;
    for (int i=0;i<=lena;i++)
    {
        ans=min(ans,lenb-pre[i]-lenb-1+ss[i+1]);
    }

    if (ans<0)
    {
        ans=0;
    }
    cout<<ans;
    return 0;
}