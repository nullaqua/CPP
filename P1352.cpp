#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P1352

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

class StreamOperator
{
};

StreamOperator *push=new StreamOperator();
StreamOperator *enter=new StreamOperator();

class LanzhiStream :istream,ostream
{
#define READ_BUFFER_SIZE 100000LL
#define PRINT_BUFFER_SIZE 100000LL
private:
    char readBuffer[READ_BUFFER_SIZE]{},*r1=readBuffer+READ_BUFFER_SIZE,*rend=readBuffer+READ_BUFFER_SIZE;
    char printBuffer[PRINT_BUFFER_SIZE]{},*p1=printBuffer;
    const char *pend=printBuffer+PRINT_BUFFER_SIZE;
    bool isNormal=true;

    static void onStop()
    {
        getStream().Push();
    }

    LanzhiStream()
    {
        atexit(onStop);
    }

    LanzhiStream &operator=(LanzhiStream const &stream)
    {
    }

    LanzhiStream(LanzhiStream const &stream)
    {
    }

    LanzhiStream(LanzhiStream &&stream)
    {
    }

    LanzhiStream &operator=(LanzhiStream &&stream)
    {
    }

    template<class Int>
    void read_signed_int(Int &x)
    {
        char ch;
        Int k=-1;
        x=0;
        nextChar(ch);
        while (ch==' '||ch=='\n'||ch=='\a'||ch=='\b'||ch=='\r'||ch=='\t'||ch=='\f'||ch=='\0')
        {
            nextChar(ch);
        }
        if (ch=='-')
        {
            k=1;
            nextChar(ch);
        }
        while (!(ch<'0'||ch>'9'))
        {
            x=(x<<3)+(x<<1)-ch+'0';
            nextChar(ch);
        }
        x*=k;
    }

    template<class Num>
    void read_unsigned_int(Num &x)
    {
        char ch;
        x=0;
        nextChar(ch);
        while (ch<'0'||ch>'9')
        {
            nextChar(ch);
        }
        while (!(ch<'0'||ch>'9'))
        {
            x=(x<<3)+(x<<1)-ch+'0';
            nextChar(ch);
        }
    }

    template<class Num>
    void read_float(Num &x)
    {
        char ch;
        Num k=-1;
        x=0;
        nextChar(ch);
        while (ch<'0'||ch>'9')
        {
            nextChar(ch);
        }
        if (ch=='-')
        {
            nextChar(ch);
        }
        while (!(ch<'0'||ch>'9'))
        {
            x=x*10-ch+'0';
            nextChar(ch);
        }
        if (ch=='.')
        {
            nextChar(ch);
            double s=10;
            while (!(ch<'0'||ch>'9'))
            {
                x-=double(ch-'0')/s;
                s*=10;
                nextChar(ch);
            }
        }
        x*=k;
    }

    template<class Num>
    void print_signed_int(Num x)
    {
        if (x==0)
        {
            putChar('0');
            return;
        }
        char buff[50]={},*p=buff;
        if (x<0)
        {
            *(++p)=char('-');
            while (x)
            {
                *(++p)=char(x%10);
                x/=10;
            }
            while (p!=buff)
            {
                putChar(char('0'-*(p--)));
            }
        }
        else
        {
            while (x)
            {
                *(++p)=char(x%10);
                x/=10;
            }
            while (p!=buff)
            {
                putChar(char('0'+*(p--)));
            }
        }
    }

    template<class Num>
    void print_unsigned_int(Num x)
    {
        if (x==0)
        {
            putChar('0');
            return;
        }
        char buff[50]={},*p=buff;
        while (x)
        {
            *(++p)=char(x%10);
            x/=10;
        }
        while (p!=buff)
        {
            putChar(char(*(p--)+'0'));
        }
    }

    template<class Num>
    void print_float(Num x)
    {
        print_signed_int(__int128(x));
        if (x<0)
        {
            x*=-1;
            x-=floorl(x);
        }
        if ((x>0&&Accuracy()>0)||(Accuracy()>0&&Force()))
        {
            putChar('.');
        }
        int cnt=0;
        while (cnt<Accuracy()-1&&(x>0||Force()))
        {
            x*=10;
            putChar(char(x+'0'));
            x-=floorl(x);
        }
        x*=10;
        if (PutMode()==1)
        {
            x+=0.5;
        }
        putChar(char(x+'0'));
    }

public:
    static LanzhiStream &getStream()
    {
        static LanzhiStream stream=LanzhiStream();
        return stream;
    }

    inline bool hasNext()
    {
        if (r1>=rend)
        {
            r1=readBuffer;
            rend=readBuffer+fread(readBuffer,1,READ_BUFFER_SIZE,stdin);
        }
        return r1<rend;
    }

    inline char getChar(char &s)
    {
        return s=getChar();
    }

    inline char nextChar(char &s)
    {
        return s=nextChar();
    }

    inline char getChar()
    {
        return hasNext()?*r1:(char)-1;
    }

    inline char nextChar()
    {
        if (hasNext())
        {
            return *r1++;
        }
        isNormal=false;
        return -1;
    }

    inline void putChar(char s)
    {
        if (p1>=pend)
        {
            Push();
        }
        *p1++=s;
    }

    inline explicit operator bool() const
    {
        return isNormal;
    }

    inline LanzhiStream &operator>>(short &x)
    {
        read_signed_int(x);
        return *this;
    }

    inline LanzhiStream &operator>>(int &x)
    {
        read_signed_int(x);
        return *this;
    }

    inline LanzhiStream &operator>>(long &x)
    {
        read_signed_int(x);
        return *this;
    }

    inline LanzhiStream &operator>>(long long &x)
    {
        read_signed_int(x);
        return *this;
    }

    inline LanzhiStream &operator>>(__int128 &x)
    {
        read_signed_int(x);
        return *this;
    }

    inline LanzhiStream &operator>>(unsigned short &x)
    {
        read_unsigned_int(x);
        return *this;
    }

    inline LanzhiStream &operator>>(unsigned int &x)
    {
        read_unsigned_int(x);
        return *this;
    }

    inline LanzhiStream &operator>>(unsigned long &x)
    {
        read_unsigned_int(x);
        return *this;
    }

    inline LanzhiStream &operator>>(unsigned long long &x)
    {
        read_unsigned_int(x);
        return *this;
    }

    inline LanzhiStream &operator>>(unsigned __int128 &x)
    {
        read_unsigned_int(x);
        return *this;
    }

    inline LanzhiStream &operator>>(float &x)
    {
        read_float(x);
        return *this;
    }

    inline LanzhiStream &operator>>(double &x)
    {
        read_float(x);
        return *this;
    }

    inline LanzhiStream &operator>>(long double &x)
    {
        read_float(x);
        return *this;
    }

    inline LanzhiStream &operator>>(char &ch)
    {
        nextChar(ch);
        while (ch==' '||ch=='\n'||ch=='\a'||ch=='\b'||ch=='\r'||ch=='\t'||ch=='\f'||ch=='\0')
        {
            nextChar(ch);
        }
        return *this;
    }

    inline LanzhiStream &operator>>(char *x)
    {
        char ch;
        nextChar(ch);
        while (ch==' '||ch=='\n'||ch=='\a'||ch=='\b'||ch=='\r'||ch=='\t'||ch=='\f'||ch=='\0')
        {
            nextChar(ch);
        }
        while (!(ch==' '||ch=='\n'||ch=='\a'||ch=='\b'||ch=='\r'||ch=='\t'||ch=='\f'||ch=='\0'||!isNormal))
        {
            *x++=ch;
            nextChar(ch);
        }
        *x++='\0';
        return *this;
    }

    inline LanzhiStream &operator>>(string &x)
    {
        x.clear();
        char ch;
        nextChar(ch);
        while (!(ch==' '||ch=='\n'||ch=='\a'||ch=='\b'||ch=='\r'||ch=='\t'||ch=='\f'||ch=='\0'||!isNormal))
        {
            x=ch;
            nextChar(ch);
        }
        return *this;
    }

    inline void Push()
    {
        fwrite(printBuffer,1,p1-printBuffer,stdout);
        p1=printBuffer;
        fflush(stdout);
    }

    static inline int Accuracy(int s=-1)
    {
        static int accuracy=50;
        if (s<0)
        {
            return accuracy;
        }
        if (accuracy>100)
        {
            accuracy=100;
        }
        else
        {
            accuracy=s;
        }
        return accuracy;
    }

    static inline bool Force(int s=-1)
    {
        static bool force=false;
        if (s<0)
        {
            return force;
        }
        force=(s!=0);
        return force;
    }

    static inline int PutMode(int s=-1)
    {
        static int putmode=1;
        if (s==1)
        {
            putmode=1;
        }
        else if (s==2)
        {
            putmode=2;
        }
        return putmode;
    }

    inline LanzhiStream &operator<<(char ch)
    {
        putChar(ch);
        return *this;
    }

    inline LanzhiStream &operator<<(const char *str)
    {
        while (*str!='\0')
        {
            putChar(*str++);
        }
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<<(short x)
    {
        print_signed_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<<(int x)
    {
        print_signed_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<<(long x)
    {
        print_signed_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<<(long long x)
    {
        print_signed_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<<(__int128 x)
    {
        print_signed_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<<(unsigned short x)
    {
        print_unsigned_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<<(unsigned int x)
    {
        print_unsigned_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<<(unsigned long x)
    {
        print_unsigned_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<<(unsigned long long x)
    {
        print_unsigned_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<<(unsigned __int128 x)
    {
        print_unsigned_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<<(float x)
    {
        print_float(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<<(double x)
    {
        print_float(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<<(long double x)
    {
        print_float(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<=(const char *str)
    {
        while (*str!='\0')
        {
            putChar(*str++);
        }
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<=(short x)
    {
        print_signed_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<=(int x)
    {
        print_signed_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<=(long x)
    {
        print_signed_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<=(long long x)
    {
        print_signed_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<=(__int128 x)
    {
        print_signed_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<=(unsigned short x)
    {
        print_unsigned_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<=(unsigned int x)
    {
        print_unsigned_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<=(unsigned long x)
    {
        print_unsigned_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<=(unsigned long long x)
    {
        print_unsigned_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<=(unsigned __int128 x)
    {
        print_unsigned_int(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<=(float x)
    {
        print_float(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<=(double x)
    {
        print_float(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<=(long double x)
    {
        print_float(x);
        putChar(' ');
        return *this;
    }

    inline LanzhiStream &operator<<(StreamOperator *e)
    {
        if (e==enter)
        {
            putChar('\n');
        }
        else if (e==push)
        {
            Push();
        }
        return *this;
    }

#undef READ_BUFFER_SIZE
#undef PRINT_BUFFER_SIZE
};

LanzhiStream &io=LanzhiStream::getStream();

int n;
int a[6003];

struct EDGE
{
    int v,next;
}edge[12005];
int ed;
int head[6003];
void add(int u,int v)
{
    edge[++ed].v=v;
    edge[ed].next=head[u];
    head[u]=ed;
}

int dp[6003][2];

void dfs(int u,int fa)
{
    dp[u][1]+=a[u];
    for (int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].v;
        if (v==fa)
        {
            continue;
        }
        dfs(v,u);
        dp[u][1]+=dp[v][0];
        dp[u][0]+=max(dp[v][1],dp[v][0]);
    }
    //io<<u<<dp[u][0]<<dp[u][1]<<'\n';
}

int main()
{
    io>>n;
    for (int i=1;i<=n;i++)
    {
        io>>a[i];//<<a[i];
    }
    for (int i=1;i<n;i++)
    {
        int u,v;
        io>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    io<<max(dp[1][1],dp[1][0]);
    return 0;
}