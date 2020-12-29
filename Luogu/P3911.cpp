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
int n,g[50005],a,f[50005],h[50005],t[50005],sum,ans,cnt,SUM;
bool isnp[50005];
int power(int A,int B)
{
    int tmp=1;
    while(B)
    {
        if(B&1)
        {
            tmp*=A;
        }
        A*=A;
        B>>=1;
    }
    return tmp;
}
void work(int now,int v)
{
    if(now>cnt)
    {
        SUM+=v;
        return;
    }
    // for(int i=0,j=1;i<=t[now];++i,j*=-h[now])
    // {
    //     work(now+1,v*j);
    // }
    work(now+1,-v*h[now]);
    work(now+1,v);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a;
        ++g[a];
    }
    for(int i=2;i<=50000;++i)
    {
        if(f[i])
        {
            continue;
        }
        for(int j=i;j<=50000;j+=i)
        {
            f[j]=i;
        }
    }
    for(int i=1;i<=50000;++i)
    {
        for(int j=i;j<=50000;j+=i)
        {
            sum+=g[j]*j;
        }
        if(!sum)continue;
        int tmp=i;
        cnt=0;
        while(tmp>1)
        {
            h[++cnt]=f[tmp];
            t[cnt]=0;
            while(tmp%h[cnt]==0)
            {
                ++t[cnt];
                tmp/=h[cnt];
            }
        }
        SUM=0;
        work(1,1);
        ans+=sum*sum/i*SUM;
        // cout<<i<<' '<<SUM<<' '<<sum<<' '<<ans<<endl;
        sum=0;
    }
    cout<<ans<<endl;
    return 0;
}