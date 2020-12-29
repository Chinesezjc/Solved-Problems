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
int n,a[5005],g[5005],ans,sum;
int work(int now)
{
    int tmp=0;
    while(a[now]+g[now])
    {
        --now;
        tmp+=max(0ll,g[now]-g[now+1]);
    }
    return tmp;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            ans+=sum;
            sum=0;
            continue;
        }
        g[i]=min(a[i],g[i-1]);
        a[i]-=g[i];
        int size=a[i],used=work(i);
        for(int j=i-1;a[j]+g[j];--j)
        {
            if(size<a[j])
            {
                ++used;
            }
            else
            {
                size=a[j];
            }
        }
        sum=min(used,sum+1);
        if(used==sum)
        {
            g[i]+=a[i];
            for(int j=i-1;a[j]+g[j];--j)
            {
                int tmp=g[j];
                g[j]=max(g[j],min(g[j+1],a[j]+g[j]));
                a[j]-=g[j]-tmp;
            }
            a[i]=0;
        }
    }
    cout<<ans+sum<<endl;
    return 0;
}