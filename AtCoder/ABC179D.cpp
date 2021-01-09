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
int n,k,l[15],r[15],dp[200005],sum[200005];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    dp[1]=1;
    sum[1]=1;
    for(int i=1;i<=k;++i)
    {
        cin>>l[i]>>r[i];
    }
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=k;++j)
        {
            dp[i]=(dp[i]+sum[max(i-l[j],0ll)]-sum[max(i-r[j]-1,0ll)]+MOD)%MOD;
        }
        sum[i]=(sum[i-1]+dp[i])%MOD;
    }
    cout<<dp[n]<<endl;
    return 0;
}