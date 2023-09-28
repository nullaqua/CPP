#include <bits/stdc++.h>

using namespace std;

struct Out
{
private:
    FILE*file;
    char*buf,*p1,*pend;
    int precision=6;
    bool force=false;
    bool round=true;
    int wight=0;
public:
    explicit Out(FILE*file,int size=1<<20):file(file),buf(new char[size]),p1(buf),pend(buf+size) {}
    explicit Out(const string&file,int size=1<<20):Out(fopen(file.c_str(),"w"),size) {}
    Out(const Out&) = delete;
    Out&operator=(const Out&) = delete;
    Out(Out&&) = delete;
    Out&operator=(Out&&) = delete;
    void setPrecision(int x) {precision=x;}
    void setForce(bool x) {force=x;}
    void setRound(bool x) {round=x;}
    void setLead(int x) {wight=x;}
    ~Out(){flush(),fclose(file),delete[] buf;}
    void flush() {fwrite(buf,1,p1-buf,file),p1=buf;}
    void putc(const char&c)
    {
        *p1++=c;
        if (p1==pend)flush();
    }
#define retp(x) template<class T> typename enable_if<x,Out>::type
#define lmt(x) x<T>::value
    retp(lmt(is_unsigned)&&lmt(is_integral))&operator<<(T x)
    {
        static char s[50];
        int len=0;
        do
        {
            s[len++]=x%10+'0';
            x/=10;
        } while (x||len<wight);
        while (len--)putc(s[len]);
        return *this;
    }
    retp(lmt(is_signed)&&lmt(is_integral))&operator<<(T x)
    {
        make_unsigned_t<T> y=x;
        if (x<0)putc('-'),y=-y;
        *this<<y;
        return *this;
    }
    retp(lmt(is_floating_point))&operator<<(T x)
    {
        if (x!=x)putc('N'),putc('a'),putc('N');
        else if (x==numeric_limits<T>::infinity())putc('I'),putc('n'),putc('f');
        else if (x==-numeric_limits<T>::infinity())putc('-'),putc('I'),putc('n'),putc('f');
        else
        {
            if (x<0)putc('-'),x=-x;
            if (round)x+=0.5*pow(0.1,precision);
            auto t=static_cast<intmax_t>(x);
            *this<<t;
            x-=t;
            x*=pow(10,precision);
            t=static_cast<intmax_t>(x);
            while (t%10==0&&t&&!force)t/=10;
            if (t||force)putc('.'),*this<<t;
        }
        return *this;
    }
#undef retp
#undef lmt
    Out&operator<<(const char*s)
    {
        while (*s)putc(*s++);
        return *this;
    }
    Out&operator<<(const string&s)
    {
        for (auto c:s)putc(c);
        return *this;
    }
    Out&operator<<(const char&c)
    {
        putc(c);
        return *this;
    }
    Out&operator<<(const function<void(Out&)>&f)
    {
        f(*this);
        return *this;
    }
};
const function<void(Out&)> endln=[](Out&o) {o.putc('\n');};
const function<void(Out&)> flush=[](Out&o) {o.flush();};
function<void(Out&)> precision(int n) {return [n](Out&o) {o.setPrecision(n);};}
function<void(Out&)> force(bool b) {return [b](Out&o) {o.setForce(b);};}
function<void(Out&)> round(bool b) {return [b](Out&o) {o.setRound(b);};}
function<void(Out&)> lead(int n) {return [n](Out&o) {o.setLead(n);};}
struct In
{
private:
    FILE*file;
    char*buf,*p1,*pend;
    bool eof;
    bool rd=true;
    void read()
    {
        p1=buf;
        pend=buf+fread(buf,1,pend-buf,file);
        eof=pend==p1;
    }
public:
    explicit In(FILE*file,int size=1<<20):file(file),buf(new char[size]),p1(buf+size),pend(buf+size),eof(false) {}
    explicit In(const string&file,int size=1<<20):In(fopen(file.c_str(),"r"),size) {}
    In(const In&) = delete;
    In&operator=(const In&) = delete;
    In(In&&) = delete;
    In&operator=(In&&) = delete;
    ~In() {delete[] buf,fclose(file);}
    char getc()
    {
        if (p1==pend)read();
        return eof?(char)-1:*p1++;
    }
    char peek()
    {
        if (p1==pend)read();
        return eof?(char)-1:*p1;
    }
    explicit operator bool() const {return rd;}
#define retp(x) template<class T> typename enable_if<x,In>::type
#define lmt(x) x<T>::value
    retp(lmt(is_unsigned)&&lmt(is_integral))&operator>>(T&x)
    {
        rd=false;
        x=0;
        char c;
        while (!isdigit(c=getc())&&c!=-1);
        for (;isdigit(c);c=getc())x=x*10+c-'0',rd=true;
        return *this;
    }
    retp(lmt(is_signed)&&lmt(is_integral))&operator>>(T&x)
    {
        rd=false;
        x=0;
        char c;
        while (!isdigit(c=getc())&&c!='-'&&c!=-1);
        bool neg=false;
        if (c=='-')neg=true,c=getc();
        for (;isdigit(c);c=getc())x=x*10+(neg?'0'-c:c-'0'),rd=true;
        return *this;
    }
    retp(lmt(is_floating_point))&operator>>(T&x)
    {
        rd=false;
        x=0;
        char c;
        while (!isdigit(c=getc())&&c!='-'&&c!=-1);
        bool neg=false;
        if (c=='-')neg=true,c=getc();
        for (;isdigit(c);c=getc())x=x*10+(neg?'0'-c:c-'0'),rd=true;
        if (c=='.')
        {
            c=getc();
            T y=0;
            int cnt=0;
            for (;isdigit(c);c=getc())y=y*10+(neg?'0'-c:c-'0'),cnt++;
            x+=y*pow(0.1,cnt);
        }
        return *this;
    }
#undef retp
#undef lmt
    In&operator>>(char*s)
    {
        rd=false;
        while (isspace(*s=getc())&&*s!=-1);
        while (!isspace(*++s=getc())&&*s!=-1)rd=true;
        *s=0;
        return *this;
    }
    In&operator>>(string&s)
    {
        rd=false;
        s.clear();
        char c;
        while (isspace(c=getc())&&c!=-1);
        for (;!isspace(c)&&c!=-1;c=getc())s+=c,rd=true;
        return *this;
    }
    In&operator>>(char&c)
    {
        while (isspace(c=getc())&&c!=-1);
        rd=c!=-1;
        return *this;
    }
    In&getline(char*s)
    {
        while ((*s=getc())=='\n'&&*s!=-1);
        while ((*++s=getc())!='\n'&&*s!=-1)rd=true;
        return *s=0,*this;
    }
    In&getline(string&s)
    {
        s.clear();
        char c;
        while ((c=getc())=='\n'&&c!=-1);
        for (;c!='\n'&&c!=-1;c=getc())s+=c,rd=true;
        return *this;
    }
};
struct IO:public In,public Out
{
    explicit IO(FILE*in,FILE*out,int in_size=1<<20,int out_size=1<<20):In(in,in_size),Out(out,out_size) {}
    explicit IO(const string&in,const string&out,int in_size=1<<20,int out_size=1<<20):In(in,in_size),Out(out,out_size) {}
    explicit IO(FILE*in,const string&out,int in_size=1<<20,int out_size=1<<20):In(in,in_size),Out(out,out_size) {}
    explicit IO(const string&in,FILE*out,int in_size=1<<20,int out_size=1<<20):In(in,in_size),Out(out,out_size) {}
    IO(const IO&) = delete;
    IO&operator=(const IO&) = delete;
    IO(IO&&) = delete;
    IO&operator=(IO&&) = delete;
};