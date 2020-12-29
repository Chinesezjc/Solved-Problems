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
int n,m,k,cnt,dp[2][100005],a,b,sum;
map<int,int> t;
vector<int> g[100005];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    t[1]=++cnt;
    for(int i=1;i<=k;++i)
    {
        cin>>a>>b;
        if(a==b)
        {
            continue;
        }
        if(!t[a])
        {
            t[a]=++cnt;
        }
        if(!t[b])
        {
            t[b]=++cnt;
        }
        g[t[a]].push_back(t[b]);
    }
    dp[0][1]=1;
    for(int i=1;i<=m;++i)
    {
        sum=0;
        for(int j=1;j<=cnt;++j)
        {
            sum+=dp[!(i&1)][j];
        }
        sum+=dp[!(i&1)][cnt+1]*(n-cnt);
        sum%=MOD;
        for(int j=1;j<=cnt;++j)
        {
            dp[i&1][j]=(sum+MOD-dp[!(i&1)][j])%MOD;
            for(int k=0;k<(int)g[j].size();++k)
            {
                dp[i&1][j]=(dp[i&1][j]+MOD-dp[!(i&1)][g[j][k]])%MOD;
            }
        }
        dp[i&1][cnt+1]=(sum+MOD-dp[!(i&1)][cnt+1])%MOD;
    }
    cout<<dp[m&1][1]<<endl;
    return 0;
}