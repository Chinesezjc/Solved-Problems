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
int M,S,T,dp[300005][15],ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>M>>S>>T;
    if(M/10*60>=S)
    {
        cout<<"Yes"<<endl<<(S+59)/60<<endl;
        return 0;
    }
    if(M/10>T)
    {
        cout<<"No"<<endl<<T*60<<endl;
        return 0;
    }
    memset(dp,0xf0,sizeof(dp));
    dp[M/10][M%10]=M/10*60;
    for(int i=M/10+1;i<=T;++i)
    {
        for(int j=4;j<15;++j)
        {
            dp[i][j]=max(dp[i][j],dp[i-1][j-4]);
        }
        for(int j=0;j<15;++j)
        {
            dp[i][j]=max(dp[i][j],dp[i-1][j]+17);
        }
        for(int j=0;j<5;++j)
        {
            dp[i][j]=max(dp[i][j],dp[i-1][j+10]+60);
        }
        for(int j=0;j<15;++j)
        {
            if(dp[i][j]>=S)
            {
                cout<<"Yes"<<endl<<i<<endl;
                return 0;
            }
        }
    }
    ans=0;
    for(int i=0;i<15;++i)
    {
        ans=max(ans,dp[T][i]);
    }
    cout<<"No"<<endl<<ans<<endl;
    return 0;
}