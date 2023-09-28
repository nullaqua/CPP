#include <algorithm>
#include <climits>
#include <cstdio>
#include <random>
#include <deque>
#include <ctime>
#include <cmath>
#include <cassert>
#define ll long long
// #define err printf
#define err(...)

const int maxn = 1e4+9;
using namespace std;
typedef deque<int>::iterator iter;

int a[maxn],b[maxn],mini=INT_MAX,n;
deque<int> cf;//差分
iter lpt,rpt;
ll ans;
mt19937 rnd(time(0));

void Read(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
        a[i]*=n; // 为防止出现小数，开始时把每一项乘以n即可
    }
    for(int i=0; i<n-1; i++){
        b[i]=a[i+1]-a[i];
    }
}
void Init(){
    sort(b,b+n-1);
    bool f=0;
    // 构造初始解
    for(int i=0; i<n-1; i++){
        mini = min(mini,b[i]);
        if(f) cf.push_front(b[i]);
        else cf.push_back(b[i]);
        f = !f;
    }
    // 计算最小值有几个，用于退火时判断当前数在拐点左侧还是右侧
    f=0;
    for(int i=0; i<n-1; i++){
        if(cf[i]==mini){
            if(!f){
                lpt = cf.begin()+i;
                rpt = cf.begin()+i;
                f=1;
            } else {
                rpt = cf.begin()+i;
            }
        }
    }
}

ll pf(ll x) { return x*x; }
// 计算方差。由于整体加减不影响方差，我们默认第一项是0
ll calc(){
    ll sum=0,cur=0,pj,fc;
    for(int solo : cf){
        cur += solo;
        sum += cur;
    }
    pj = sum/n;
    fc = pf(pj);//a[0]的贡献
    cur = 0;
    for(int solo : cf){
        cur += solo;
        fc += pf(cur-pj);
    }
    return fc/n;
}
void SA(){
    double T = 2e5;//实测这个初温有很好的出解率
    ll now=ans,newans,de;
    int rndsize = n-1-(rpt-lpt+1),val,len=rpt-lpt+1;
    iter p1;
    while(T>1e-5){
        // 处理拐点区域
        for(int i=0; i<n-1; i++){
            if(cf[i] == mini){
                lpt = cf.begin()+i;
                rpt = lpt+len-1;
                break;
            }
        }
        deque<int> tmp = cf;
        // 随机选一个数插入到别的地方
        p1 = cf.begin()+(rnd()%rndsize);
        if(p1 >= lpt){ //从右侧插入到左侧
            p1 += len;
            val = *p1;
            cf.erase(p1);
            iter now = cf.begin();
            while(*now > val) now++;
            cf.insert(now,val);
        } else { // 从左侧插入到右侧
            val = *p1;
            cf.erase(p1);
            iter now = cf.end();
            while(*(now-1) > val) {
                now--;
            }
            cf.insert(now,val);
        }
        // 更新答案
        newans = calc(); de=newans-now;
        if(de<0 || exp(-de/T)*UINT_MAX>rnd()) {
            ans = min(ans,newans);
            now = newans;

        } else cf = tmp;
        T*=0.97;
    }
}

int main(){
    freopen("P7962_23   .in","r",stdin);
    Read();
    Init();
    ans = calc();
    if(rpt-lpt+1 == n-1){ //如果差分全一样，直接输出防止诡异错误
        printf("%lld",ans);
    } else {
        // 退火时尽可能把时间用满，增加出解率
        clock_t s = clock();
        SA();
        clock_t len = clock()-s, limit = CLOCKS_PER_SEC*0.975;
        while(clock()+len < limit) SA();
        printf("%lld",ans);
    }
    return 0;
}