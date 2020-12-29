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
int n,k,m,a[3005][3005],dp[3005][3005][4],X,Y,V,ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=k;++i)
    {
        cin>>X>>Y>>V;
        a[X][Y]=V;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(i>1)
            {
                for(int l=0;l<=3;++l)
                {
                    dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][l]);
                }
            }
            if(j>1)
            {
                for(int l=0;l<=3;++l)
                {
                    dp[i][j][l]=max(dp[i][j][l],dp[i][j-1][l]);
                }
            }
            for(int l=3;l>0;--l)
            {
                dp[i][j][l]=max(dp[i][j][l],dp[i][j][l-1]+a[i][j]);
            }
        }
    }
    for(int i=0;i<=3;++i)
    {
        ans=max(dp[n][m][i],ans);
    }
    cout<<ans<<endl;
    return 0;
}