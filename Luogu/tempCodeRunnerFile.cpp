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
int n,p,m,dp[100005],ans[100005],ANS,cnt;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>p>>m;
    for(int i=1;i<=min(n,100000ll);++i)
    {
        dp[i]=INF;
        for(int j=1;j*j<=i;++j)
        {
            if(j==p)
            {
                continue;
            }
            dp[i]=min(dp[i],dp[i-j*j]+1);
        }
        if(ANS<dp[i])
        {
            ANS=dp[i];
            cnt=0;
        }
        if(dp[i]==ANS)
        {
            ans[++cnt]=i;
        }
    }
    cout<<ANS<<endl;
    for(int i=1;i<=min(cnt,m);++i)
    {
        cout<<ans[i]<<' ';
    }
    for(int i=cnt+1;i<=m;++i)
    {
        cout<<-1<<' ';
    }
    return 0;
}