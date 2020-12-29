//This Code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<time.h>
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int n,k,p[5005],c[5005],dis[5005],dfn[5005],ans=-INF;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>p[i];
    }
    for(int i=1;i<=n;++i)
    {
        cin>>c[i];
    }
    for(int i=1;i<=n;++i)
    {
        fill(dis+1,dis+1+n,0);
        fill(dfn+1,dfn+1+n,0);
        int now=p[i],v=c[now],tim=1;
        dis[now]=v;
        dfn[now]=tim;
        ans=max(ans,v);
        while(v>0&&tim<k)
        {
            ++tim;
            now=p[now];
            v+=c[now];
            ans=max(v,ans);
            if(dis[now])
            {
                if(dis[now]<v)
                {
                    int len=tim-dfn[now],sum=v-dis[now];
                    int cnt=(k-tim)/len;
                    tim+=len*cnt;
                    v+=cnt*sum;
                    ans=max(ans,v);
                    while(tim<k)
                    {
                        ++tim;
                        now=p[now];
                        v+=c[now];
                        ans=max(ans,v);
                    }
                }
            }
            else
            {
                dfn[now]=tim;
                dis[now]=v;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}