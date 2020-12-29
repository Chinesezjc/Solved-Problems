#include<cstdio>
#define INF 0x3fffffffffffffff
using namespace std;
long long rnd;
const int Base=131;
const int P=13131;
inline int getrand()
{
    rnd=(rnd*Base)%P;
    if(!rnd)
        rnd=Base;
    return rnd;
}
long long n,has[6001],x[6001],y[6001],t[6001],min,minn;
long long ans,dis[6001];
void way(long long from,long long to)
{
    long long a=x[from]-x[to],b=y[from]-y[to],c=t[from]-t[to];
    long long sum=a*a+b*b+(c<0?-c:c); 
    if(dis[to]<=sum)
    {
        return;
    }
    dis[to]=sum;
}
int main()
{
    scanf("%lld%lld",&n,&rnd);
    x[1]=getrand();
    y[1]=getrand();
    t[1]=getrand();
    has[1]=true;
    for(long long i=2;i<=n;++i)
    {
        dis[i]=INF;
        x[i]=getrand();
        y[i]=getrand();
        t[i]=getrand();
        way(1,i);
    }
    for(long long cnt=1;cnt<n;++cnt)
    {
        min=INF;
        minn=-1;
        for(long long i=2;i<=n;++i)
        {
            if(!has[i]&&dis[i]<min)
            {
                min=dis[i];
                minn=i;
            }
        }
        has[minn]=true;
        ans^=min;
        for(long long i=2;i<=n;++i)
        {
            if(!has[i])
            {
                way(minn,i);
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
