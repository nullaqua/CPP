#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/CF937B

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int p,y;

int main()
{
    cin>>p>>y;
    while (y>1)
    {
        if (y<=p)
        {
            cout<<"-1\n";
            break;
        }
        bool flag=true;
        for (int i=2;i*i<=y&&i<=p;i++)
        {
            if (y%i==0)
            {
                flag=false;
                break;
            }
        }
        if (flag)
        {
            cout<<y<<'\n';
            break;
        }
        y--;
    }
    return 0;
}