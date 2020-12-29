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
#define MOD 998244353
using namespace std;
int dp[3005][3005],a,b,c,d;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>a>>b>>c>>d;
    dp[a][b]=1;
    for(int i=a;i<=c;++i)
    {
        for(int j=b;j<=d;++j)
        {
            // if(i==a&&j==b)
            // {
            //     continue;
            // }
            dp[i][j]+=(dp[i-1][j]*j%MOD+dp[i][j-1]*i%MOD-dp[i-1][j-1]*(i-1)%MOD*(j-1)%MOD+MOD)%MOD;
        }
    }
    cout<<dp[c][d]<<endl;
    return 0;
}