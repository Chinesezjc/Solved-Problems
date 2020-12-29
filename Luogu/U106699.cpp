//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,w[1001],dp[1001],sum[1001],ans=INF;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>w[i];
	}
	dp[1]=0;
	for(int i=2;i<=n;++i)
	{
		dp[i]=INF;
	}
	for(int i=1;i<n;++i)
	{
		for(int j=n-i+1;j;--j)
		{
			dp[j]=min(dp[j],dp[j+i-1]+w[j]);
		}
		for(int j=n;j-i;--j)
		{
			dp[j]=dp[j-i]+w[j];
		}
		for(int j=i;j;--j)
		{
			dp[j]=INF;
		}
		ans=min(ans,dp[n]);
	}
	cout<<ans;
	return 0;
}

