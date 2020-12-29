//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,s,c[1000001],x[1000001],sumc[1000001],sumx[1000001],sumxc[1000001],dp[1000001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>s;
	for(int i=1;i<=n;++i)
	{
		cin>>x[i];
		sumx[i]=sumx[i-1]+x[i];
	}
	for(int i=1;i<=n;++i)
	{
		cin>>c[i];
		sumc[i]=sumc[i-1]+c[i];
		sumxc[i]=sumxc[i-1]+x[i]*c[i];
	}
	for(int i=1;i<=n;++i)
	{
		dp[i]=INF;
		for(int j=0;j<i;++j)
		{
			dp[i]=min(dp[i],dp[j]+2*x[i]*(sumc[i]-sumc[j])-(sumxc[i]-sumxc[j])+s*(sumc[n]-sumc[i]));
		}
	}
	cout<<dp[n];
	return 0;
}

