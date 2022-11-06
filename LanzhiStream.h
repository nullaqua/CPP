#include <bits/stdc++.h>

#define READ_BUFFER_SIZE 100000LL
#define PRINT_BUFFER_SIZE 100000LL

class
{
}enter,push;

class
{
private:
    char readBuffer[READ_BUFFER_SIZE],*r1=readBuffer+READ_BUFFER_SIZE,*rend=readBuffer+READ_BUFFER_SIZE;
    char printBuffer[PRINT_BUFFER_SIZE],*pend=printBuffer;
    bool isNormal=true;

public:
    inline bool hasNext()
    {
        if (r1==rend)
        {
            r1=readBuffer;
            rend=readBuffer+fread(readBuffer,1,READ_BUFFER_SIZE,stdin);
        }
        return r1!=rend;
    }

    inline char getChar(char &s)
    {
        return s=hasNext()?*r1:(char)-1;
    }

    inline char nextChar(char &s)
    {
        return s=hasNext()?*r1++:(char)-1;
    }

    inline char getChar()
    {
        return hasNext()?*r1:(char)-1;
    }

    inline char nextChar()
    {
        return hasNext()?*r1++:(char)-1;
    }

    inline explicit operator bool() const
    {
        return isNormal;
    }

    template<typename LanzhiStream>
    inline LanzhiStream &operator>>(char &ch)
    {
        nextChar(ch);
        while (ch==' '||ch=='\n'||ch=='\a'||ch=='\b'||ch=='\r'||ch=='\t'||ch=='\f'||ch=='\0')
        {
            nextChar(ch);
        }
        isNormal=(ch!=(char)-1);
        return *this;
    }

    template<typename LanzhiStream>
    inline LanzhiStream &operator>>(char *x)
    {
        char ch;
        nextChar(ch);
        while (ch==' '||ch=='\n'||ch=='\a'||ch=='\b'||ch=='\r'||ch=='\t'||ch=='\f'||ch=='\0')
        {
            nextChar(ch);
        }
        isNormal=(ch!=(char)-1);
        while (!(ch==' '||ch=='\n'||ch=='\a'||ch=='\b'||ch=='\r'||ch=='\t'||ch=='\f'||ch=='\0'))
        {
            *x++=ch;
            nextChar(ch);
        }
        *x++='\0';
        return *this;
    }

    template<typename LanzhiStream>
    inline LanzhiStream &operator>>(int &x)
    {
        char ch;
        int k=-1;
        x=0;
        nextChar(ch);
        while (ch==' '||ch=='\n'||ch=='\a'||ch=='\b'||ch=='\r'||ch=='\t'||ch=='\f'||ch=='\0')
        {
            nextChar(ch);
        }
        isNormal=(ch!=(char)-1);
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
        return *this;
    }

    template<typename LanzhiStream>
    inline LanzhiStream &operator>>(long long &x)
    {
        char ch;
        int k=-1;
        x=0;
        nextChar(ch);
        while (ch==' '||ch=='\n'||ch=='\a'||ch=='\b'||ch=='\r'||ch=='\t'||ch=='\f'||ch=='\0')
        {
            nextChar(ch);
        }
        isNormal=(ch!=(char)-1);
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
        return *this;
    }

    template<typename LanzhiStream>
    inline LanzhiStream &operator>>(unsigned long long &x)
    {
        char ch;
        x=0;
        nextChar(ch);
        while (ch==' '||ch=='\n'||ch=='\a'||ch=='\b'||ch=='\r'||ch=='\t'||ch=='\f'||ch=='\0')
        {
            nextChar(ch);
        }
        isNormal=(ch!=(char)-1);
        if (ch=='-')
        {
            nextChar(ch);
        }
        while (!(ch<'0'||ch>'9'))
        {
            x=(x<<3)+(x<<1)-ch+'0';
            nextChar(ch);
        }
        return *this;
    }

    template<typename LanzhiStream>
    inline LanzhiStream &operator>>(double &x)
    {
        char ch;
        double k=-1;
        x=0;
        nextChar(ch);
        while (ch==' '||ch=='\n'||ch=='\a'||ch=='\b'||ch=='\r'||ch=='\t'||ch=='\f'||ch=='\0')
        {
            nextChar(ch);
        }
        isNormal=(ch!=(char)-1);
        if (ch=='-')
        {
            k=1;
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
        return *this;
    }

    template<typename LanzhiStream>
    inline LanzhiStream &operator>>(float &x)
    {
        char ch;
        float k=-1;
        x=0;
        nextChar(ch);
        while (ch==' '||ch=='\n'||ch=='\a'||ch=='\b'||ch=='\r'||ch=='\t'||ch=='\f'||ch=='\0')
        {
            nextChar(ch);
        }
        isNormal=(ch!=(char)-1);
        if (ch=='-')
        {
            k=1;
            nextChar(ch);
        }
        while (!(ch<'0'||ch>'9'))
        {
            x=x*10-(float)ch+(float)'0';
            nextChar(ch);
        }
        if (ch=='.')
        {
            nextChar(ch);
            float s=10;
            while (!(ch<'0'||ch>'9'))
            {
                x-=float(ch-'0')/s;
                s*=10;
                nextChar(ch);
            }
        }
        x*=k;
        return *this;
    }

    inline void pushed()
    {
        fwrite(printBuffer,1,pend-printBuffer,stdout);
        pend=printBuffer;
        fflush(stdout);
    }

    inline int Accuracy(int s=-1)
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

    inline bool Force(int s=-1)
    {
        static bool force=false;
        if (s<0)
        {
            return force;
        }
        force=(s!=0);
        return force;
    }

    inline int PutMode(int s=-1)
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

    template<typename LanzhiStream>
    inline LanzhiStream &operator<<(char ch)
    {
        if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
        {
            pushed();
        }
        *pend++=ch;
        return *this;
    }

    template<typename LanzhiStream>
    inline LanzhiStream &operator<<(char *str)
    {
        while (*str!='\0')
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++=*str++;
        }
        if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
        {
            pushed();
        }
        *pend++=' ';
        return *this;
    }

    template<typename LanzhiStream>
    inline LanzhiStream &operator<<(int x)
    {
        char buff[25]={},*p=buff;
        if (x==0)
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++='0';
        }
        if (x<0)
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++='-';
            x*=-1;
        }
        while (x)
        {
            *(++p)=x%10;
            x/=10;
        }
        while (p!=buff)
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++=char(*(p--)+'0');
        }
        if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
        {
            pushed();
        }
        *pend++=' ';
        return *this;
    }

    template<typename LanzhiStream>
    inline LanzhiStream &operator<<(long long x)
    {
        char buff[50]={},*p=buff;
        if (x==0)
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++='0';
        }
        if (x<0)
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++='-';
            x*=-1;
        }
        while (x)
        {
            *(++p)=x%10;
            x/=10;
        }
        while (p!=buff)
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++=char(*(p--)+'0');
        }
        if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
        {
            pushed();
        }
        *pend++=' ';
        return *this;
    }

    template<typename LanzhiStream>
    inline LanzhiStream &operator<<(unsigned long long x)
    {
        char buff[50]={},*p=buff;
        if (x==0)
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++='0';
        }
        while (x)
        {
            *(++p)=x%10;
            x/=10;
        }
        while (p!=buff)
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++=char(*(p--)+'0');
        }
        if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
        {
            pushed();
        }
        *pend++=' ';
        return *this;
    }

    template<typename LanzhiStream>
    inline LanzhiStream &operator<<(double x)
    {
        long long co=x;
        x-=co;
        char buff[105]={},*p=buff;
        if (co==0)
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++='0';
        }
        if (co<0)
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++='-';
            co*=-1;
            x*=-1;
        }
        while (co)
        {
            *(++p)=co%10;
            co/=10;
        }
        while (p!=buff)
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++=char(*(p--)+'0');
        }
        if ((x>0&&Accuracy()>0)||(Accuracy()>0&&Force()))
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++='.';
        }
        while (p-buff<=Accuracy()&&(x>0||Force()))
        {
            x*=10;
            co=x;
            *p++=char(x+'0');
            x-=co;
        }
        p--;
        char *i=buff;
        bool flag=false;
        if ((*p>='5')&&PutMode()==1)
        {
            flag=true;
        }
        else if (PutMode()==2)
        {
            p--;
        }
        while (p!=buff)
        {
            p--;
            if (flag&&*p=='9')
            {
                *p='0';
            }
            else if (flag)
            {
                *p=char(*p+1);
                break;
            }
            else if (*p>'0')
            {
                break;
            }
        }
        while ((i<=p)||((i-buff<Accuracy())&&Force()))
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++=*i++;
        }
        if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
        {
            pushed();
        }
        *pend++=' ';
        return *this;
    }

    template<typename LanzhiStream>
    inline LanzhiStream &operator<<(float x)
    {
        if (x<0)
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++='-';
            x*=-1;
        }
        int co=x;
        x-=co;
        char buff[105]={},*p=buff;
        if (co==0)
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++='0';
        }
        while (co)
        {
            *(++p)=co%10;
            co/=10;
        }
        while (p!=buff)
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++=char(*(p--)+'0');
        }
        if ((x>0&&Accuracy()>0)||(Accuracy()>0&&Force()))
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++='.';
        }
        while (p-buff<=Accuracy()&&(x>0||Force()))
        {
            x*=10;
            co=x;
            *p++=char(x+'0');
            x-=co;
        }
        p--;
        char *i=buff;
        bool flag=false;
        if ((*p>='5')&&PutMode()==1)
        {
            flag=true;
        }
        else if (PutMode()==2)
        {
            p--;
        }
        while (p!=buff)
        {
            p--;
            if (flag&&*p=='9')
            {
                *p='0';
            }
            else if (flag)
            {
                *p=char(*p+1);
                break;
            }
            else if (*p>'0')
            {
                break;
            }
        }
        while ((i<=p)||((i-buff<Accuracy())&&Force()))
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++=*i++;
        }
        if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
        {
            pushed();
        }
        *pend++=' ';
        return *this;
    }

    template<typename LanzhiStream,typename type>
    inline LanzhiStream &operator<<(type e)
    {
        if (e==enter)
        {
            if (pend-printBuffer>PRINT_BUFFER_SIZE-2)
            {
                pushed();
            }
            *pend++='\n';
        }
        else if (e==push)
        {
            pushed();
        }
        return *this;
    }
};