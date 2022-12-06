#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/CF913E

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
const int M=(~0)^((1<<8)-1);
const int x=0xf;
const int y=0x33;
const int z=0x55;
const int _x=(~x)^M;
const int _y=(~y)^M;
const int _z=(~z)^M;
string ans[0x105][3];
bool vis[0x105][3];

struct Node
{
    mutable string x;
    int u;
    int k;
    Node(string &x,int u,int k):x(x),u(u),k(k){}

    bool operator<(const Node &o)const
    {
        if (x.length()==0)
        {
            return true;
        }
        if (o.x.length()==0)
        {
            return false;
        }
        return o.x.length()==x.length()?o.x<x:o.x.length()<x.length();
    }
};

bool up(int x,int y,string &s)
{
    if (ans[x][y].size()==0)
    {
        ans[x][y]=s;
        return true;
    }
    if (ans[x][y].size()<s.size())
    {
        return false;
    }
    if (ans[x][y].size()>s.size()||s<ans[x][y])
    {
        ans[x][y]=s;
        return true;
    }
    return false;
}

void dij()
{
    set<pair<int,int>> st;
    priority_queue<Node> q;
    q.emplace(ans[x][0],x,0);
    q.emplace(ans[y][0],y,0);
    q.emplace(ans[z][0],z,0);

    while (q.size())
    {
        int u=q.top().u;
        int k=q.top().k;
        q.pop();
        if (vis[u][k])
        {
            continue;
        }
        vis[u][k]=true;
        st.emplace(make_pair(u,k));
        string s;

        if (k>0)
        {
            s="!("+ans[u][k]+")";
        }
        else
        {
            s="!"+ans[u][k];
        }
        if (up((~u)^M,0,s))
        {
            q.emplace(s,(~u)^M,0);
        }

        for (auto p:st)
        {
            string x1,x2;
            if (k>1)
            {
                x1="("+ans[u][k]+")";
            }
            else
            {
                x1=ans[u][k];
            }
            if (p.second>1)
            {
                x2="("+ans[p.first][p.second]+")";
            }
            else
            {
                x2=ans[p.first][p.second];
            }
            s=min(x1+"&"+x2,x2+"&"+x1);
            if (up(u&p.first,1,s))
            {
                q.emplace(s,u&p.first,1);
            }

            s=min(ans[u][k]+"|"+ans[p.first][p.second],ans[p.first][p.second]+"|"+ans[u][k]);
            if (up(u|p.first,2,s))
            {
                q.emplace(s,u|p.first,2);
            }
        }
    }
}

int main()
{
    ans[x][0]="x";
    ans[y][0]="y";
    ans[z][0]="z";
    dij();
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x=0;
        for (int j=7;j>=0;j--)
        {
            char ch;
            cin>>ch;
            ch-='0';
            x|=ch<<j;
        }
        cout<<min({ans[x][0],ans[x][1],ans[x][2]},[&](string x,string y)->bool{return !(Node(x,0,0)<Node(y,0,0));})<<'\n';
    }
    return 0;
}