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
int fact(int now)
{
    return now<=0?1:fact(now-1)*now;
}
int C(int n,int m)
{
    return fact(m)/fact(n)/fact(m-n);
}
int n,m,dp[20][20];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>m>>n;
    dp[0][0]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=m;++j)
        {
            dp[i][j]=dp[i-1][j-1]+dp[i][j-1]*i;
        }
    }
    cout<<dp[n][m]*fact(n)<<endl;
    return 0;
}