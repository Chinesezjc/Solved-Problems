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
int n,m,t,dp[20][105][105],x,y;
char Map[105][105];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>t;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>Map[i][j];
        }
    }
    cin>>x>>y;
    dp[0][x][y]=1;
    for(int i=1;i<=t;++i)
    {
        for(int j=1;j<=n;++j)
        {
            for(int k=1;k<=m;++k)
            {
                if(Map[j][k]=='.')
                {
                    dp[i][j][k]=dp[i-1][j-1][k]+dp[i-1][j][k-1]+dp[i-1][j+1][k]+dp[i-1][j][k+1];
                }
                // cout<<dp[i][j][k]<<' ';
            }
            // cout<<endl;
        }
        // cout<<endl;
    }
    cin>>x>>y;
    cout<<dp[t][x][y]<<endl;
    return 0;
}