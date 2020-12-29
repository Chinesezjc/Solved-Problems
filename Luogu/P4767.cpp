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
int n,m,x[3005],sum[3005],dp[3005][305],from[3005][305];
int work(int l,int r)
{
    return sum[r]-sum[(l+r+1)>>1]*2+sum[l]-x[(l+r+1)>>1]*(r-((l+r+1)>>1)*2+l);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>x[i];
    }
    sort(x+1,x+1+n);
    for(int i=1;i<=n;++i)
    {
        sum[i]=sum[i-1]+x[i];
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=min(m,i);++j)
        {
            for(int k=max(from[i-1][j],from[i][j-1]);k<i;++k)
            {
                if(dp[i][j]>=dp[k][j-1]+work(k,i))
                {
                    dp[i][j]=dp[k][j-1]+work(k,i);
                    from[i][j]=k;
                }
            }
            // cout<<from[i][j]<<' ';
        }
        // cout<<endl;
    }
    cout<<dp[n][m]<<endl;
    return 0;
}