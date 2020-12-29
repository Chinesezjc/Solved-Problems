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
int n,k,dp[305][305][256],a[305],len[305][305],to[256],v[256],ans;
int dfs(int l,int r,int now)
{
    // cout<<l<<' '<<r<<' '<<now<<endl;
    if(dp[l][r][now]^(-INF))
    {
        return dp[l][r][now];
    }
    if(len[l][r]==1)
    {
        for(int j=0;j<1<<k;++j)
        {
            // cout<<to[j]<<endl;
            if(to[j]==now)
            {
                for(int i=l-1+k-1;i<r;i+=k-1)
                {
                    dp[l][r][now]=max(dp[l][r][now],dfs(l,i,j>>1)+dfs(i+1,r,j&1)+v[j]);
                }
            }
        }
        return dp[l][r][now];
    }
    for(int i=l-1+len[l][r]-1;i<r;i+=k-1)
    {
        dp[l][r][now]=max(dp[l][r][now],dfs(l,i,now>>1)+dfs(i+1,r,now&1));
    }
    if(dp[l][r][now]==-INF)
    {
        dp[l][r][now]=-INF+1;
    }
    return dp[l][r][now];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<1<<k;++i)
    {
        cin>>to[i]>>v[i];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;++j)
        {
            fill(dp[i][j],dp[i][j]+256,-INF);
            len[i][j]=(j-i)%(k-1)+1;
        }
    }
    for(int i=1;i<=n;++i)
    {
        dp[i][i][a[i]]=0;
    }
    for(int i=0;i<1<<len[1][n];++i)
    {
        ans=max(ans,dfs(1,n,i));
    }
    cout<<ans<<endl;
    return 0;
}