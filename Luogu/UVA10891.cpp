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
int n,sum[105],a[105],dp[105][105],t;
int dfs(int l,int r)
{
    if(~dp[l][r])
    {
        return dp[l][r];
    }
    dp[l][r]=0;
    for(int i=l;i<r;++i)
    {
        dp[l][r]=max(dp[l][r],-dfs(i+1,r));
    }
    for(int i=r;i>l;--i)
    {
        dp[l][r]=max(dp[l][r],-dfs(l,i-1));
    }
    return dp[l][r]+=sum[r]-sum[l-1];
}
signed main()
{
    ios::sync_with_stdio(false);
    while(cin>>n&&n)
    {
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
            for(int j=i+1;j<=n;++j)
            {
                dp[i][j]=-1;
            }
            dp[i][i]=a[i];
        }
        cout<<dfs(1,n)*2-sum[n]<<endl;
    }
    return 0;
}