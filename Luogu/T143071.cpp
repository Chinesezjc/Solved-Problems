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
#define MOD 1000000007
using namespace std;
int n,m,q;
int ask(int n,int m)
{
    int dp[1000005],sum[1000005];
    sum[0]=0;
    for(int i=1;i<=n;++i)
    {
        dp[i]=1+sum[i-1]-sum[max(0ll,i-m-1)]+MOD;
        (sum[i]=sum[i-1]+dp[i])%=MOD;
        cout<<dp[i]%MOD<<' ';
    }
    int tmp=(1+sum[n]-sum[max(0ll,n-m)]+MOD)%MOD;
    return tmp;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>q;
    for(int i=1;i<=q;++i)
    {
        cin>>m;
        cout<<ask(n,m)<<endl;
    }
    return 0;
}