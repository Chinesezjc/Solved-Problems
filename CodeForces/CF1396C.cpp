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
int ans=INF,n,r1,r2,r3,d,m[1000005],dp[2][1000005];
int kill2(int now)
{
    return m[now]*r1+r3;
}
//0: not back
//1: back
int kill1(int now)
{
    return min(min(m[now]*r1+r1,r2),kill2(now)-r1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>r1>>r2>>r3>>d;
    r1=min(r1,r3);
    for(int i=1;i<=n;++i)
    {
        cin>>m[i];
    }
    dp[0][n]=kill2(n);
    dp[1][n]=kill2(n);
    dp[0][n-1]=min(kill2(n-1)+d+dp[1][n],kill1(n-1)+d+kill1(n)+d+r1+d+r1);
    // cout<<dp[0][n-1]<<endl;
    dp[1][n-1]=min(kill1(n-1)+d+dp[1][n]+d+r1,kill2(n-1)+d+dp[1][n]+d);
    dp[0][n-1]=min(dp[0][n-1],dp[1][n-1]);
    for(int i=n-2;i>0;--i)
    {
        dp[0][i]=min(kill1(i)+d+kill1(i+1)+d+r1+d+r1+d+dp[0][i+2],kill2(i)+d+dp[0][i+1]);
        dp[1][i]=min(kill1(i)+d+dp[1][i+1]+d+r1,kill2(i)+d+dp[1][i+1]+d);
        dp[0][i]=min(dp[0][i],dp[1][i]);
    }
    // for(int i=1;i<=n;++i)
    // {
    //     cout<<dp[0][i]<<' '<<dp[1][i]<<endl;
    // }
    cout<<dp[0][1]<<endl;
    return 0;
}