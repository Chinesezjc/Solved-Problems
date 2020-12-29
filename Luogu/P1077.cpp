//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
const int MOD=1000007;
int n,m,a[101],dp[101],sum[101];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sum[0]=dp[0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			sum[j]=sum[j-1]+dp[j];
		}
		for(int j=m;j>a[i];--j)
		{
			dp[j]=(sum[j]-sum[j-a[i]-1])%MOD;
		}
		for(int j=a[i];j>0;--j)
		{
			dp[j]=sum[j]%MOD;
		}
	}
	cout<<dp[m];
	return 0;
}

