#include<cstdio>
#define INF 0x3fffffff
using namespace std;
int n,c,dis[2001],has[2001],x[2001],y[2001],min,minn,ans;
void way(int from,int to)
{
    int a=x[from]-x[to],b=y[from]-y[to];
    int sum=a*a+b*b;
    if(sum<c||dis[to]<=sum)
    {
        return;
    }
    dis[to]=sum;
}
int main()
{
    scanf("%d%d%d%d",&n,&c,&x[1],&y[1]);
    has[1]=true;
    for(int i=2;i<=n;++i)
    {
        dis[i]=INF;
        scanf("%d%d",&x[i],&y[i]);
        way(1,i);
    }
    for(int cnt=1;cnt<n;++cnt)
    {
        min=INF;
        minn=-1;
        for(int i=2;i<=n;++i)
        {
            if(!has[i]&&dis[i]<min)
            {
                min=dis[i];
                minn=i;
            }
        }
        if(minn==-1)
        {
            puts("-1");
            return 0;
        }
        has[minn]=true;
        ans+=min;
        for(int i=2;i<=n;++i)
        {
            if(!has[i])
            {
                way(minn,i);
            }
        }
    }
    printf("%d",ans);
    return 0;
}
