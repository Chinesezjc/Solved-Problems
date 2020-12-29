//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,dp[2501];
char a[2501];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		dp[i]=INF;
	}
	for(int i=1;i<=n;++i)
	{
		int now=0;
		for(int j=i;j>0;--j)
		{
			if(a[j]=='H')
			{
				++now;
			}
			else
			{
				--now;
			}
			if(dp[j-1]+1<dp[i]&&(abs(now)==i-j+1||abs(now)<=m))
			{
				dp[i]=dp[j-1]+1;
			}
		}
	}
	cout<<dp[n];
	return 0;
}

