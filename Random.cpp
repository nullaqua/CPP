#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    srand(time(0));
    cout<<"10 10\n";
    for (int i=0;i<10;i++)
    {
        cout<<rand()%3+2<<' ';
    }
    cout<<endl;
    for (int i=0;i<10;i++)
    {
        if (rand()%2)
        {
            ll x=rand()%10+1,y=rand()%10+1;
            cout<<"2 "<<min(x,y)<<' '<<max(x,y)<<'\n';
        }
        else
        {
            cout<<"1 "<<rand()%10+1<<' '<<rand()%3+2<<'\n';
        }
    }
    return 0;
}