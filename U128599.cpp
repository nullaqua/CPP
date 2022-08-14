#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int a[100005];
int stck[100005];
int ed=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while (T--)
    {
        ed=0;
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            while (ed&&stck[ed]>a[i])
            {
                ed--;
            }
            if (!ed||stck[ed]!=a[i])
            {
                stck[++ed]=a[i];
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}