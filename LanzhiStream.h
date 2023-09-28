#include <bits/stdc++.h>
using namespace std;

class LanzhiStream
{
#define READ_BUFFER_SIZE 100000LL
#define PRINT_BUFFER_SIZE 100000LL
private:
    char readBuffer[READ_BUFFER_SIZE]{},*r1=readBuffer+READ_BUFFER_SIZE,*rend=readBuffer+READ_BUFFER_SIZE;
    char printBuffer[PRINT_BUFFER_SIZE]{},*p1=printBuffer;
    const char *pend=printBuffer+PRINT_BUFFER_SIZE;
    bool isNormal=true;
    int accuracy=50;
    bool force=false;
    int putmode=1;

    static void onStop()
    {
        (*io).Push();
    }

    LanzhiStream()
    {
        atexit(onStop);
    }

    template<class Int>
    void read_signed_int(Int &x)
    {
        char ch;
        Int k=-1;
        x=0;
        nextChar(ch);
        while (ch<'0'||ch>'9')
        {
            if (ch=='-')
            {
                k=1;
            }
            else
            {
                k=-1;
            }
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
            if (ch=='-')
            {
                k=1;
            }
            else
            {
                k=-1;
            }
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
            putChar('-');
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
        if ((x>0&&accuracy>0)||(accuracy>0&&force))
        {
            putChar('.');
        }
        int cnt=0;
        while (cnt<accuracy-1&&(x>0||force))
        {
            x*=10;
            putChar(char(x+'0'));
            x-=floorl(x);
        }
        x*=10;
        if (putmode==1)
        {
            x+=0.5;
        }
        putChar(char(x+'0'));
    }

public:
    LanzhiStream &operator=(LanzhiStream const &)=delete;

    LanzhiStream(LanzhiStream const &)=delete;

    LanzhiStream(LanzhiStream &&)=delete;

    LanzhiStream &operator=(LanzhiStream &&)=delete;

    constexpr static LanzhiStream *io=new LanzhiStream();

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
            x+=ch;
            nextChar(ch);
        }
        return *this;
    }

    inline LanzhiStream &getLine(string &x)
    {
        x.clear();
        char ch;
        nextChar(ch);
        while (!(ch=='\n'||ch=='\r'||!isNormal))
        {
            x+=ch;
            nextChar(ch);
        }
        return *this;
    }

    inline string getLine()
    {
        string x;
        char ch;
        nextChar(ch);
        while (!(ch=='\n'||ch=='\r'||!isNormal))
        {
            x+=ch;
            nextChar(ch);
        }
        return x;
    }

    inline void Push()
    {
        fwrite(printBuffer,1,p1-printBuffer,stdout);
        p1=printBuffer;
        fflush(stdout);
    }

    inline void Accuracy(int s)
    {
        if (accuracy>100)
        {
            accuracy=100;
        }
        else
        {
            accuracy=s;
        }
    }

    inline void Force(bool s)
    {
        force=s;
    }

    inline void PutMode(int s)
    {
        putmode=s;
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

    inline LanzhiStream &operator<<(const string& x)
    {
        for (char s:x)
        {
            putChar(s);
        }
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

    inline LanzhiStream &operator<=(const string& x)
    {
        for (char s:x)
        {
            putChar(s);
        }
        putChar(' ');
        return *this;
    }

    struct StreamOperator{const void operator ()(LanzhiStream &s)const;};
    static struct :StreamOperator
    {
        const void operator ()(LanzhiStream &s)const
        {
            s.putChar('\n');
            s.Push();
        }
    }enter;
    static struct :StreamOperator
    {
        const void operator ()(LanzhiStream &s)const
        {
            s.Push();
        }
    }flush;

    inline LanzhiStream &operator<<(const StreamOperator &e)
    {
        e(*this);
        return *this;
    }
#undef READ_BUFFER_SIZE
#undef PRINT_BUFFER_SIZE
};

constexpr const LanzhiStream &io=LanzhiStream::getStream();
constexpr const auto &flush =  LanzhiStream::flush;

void test()
{
    io<<flush;
}