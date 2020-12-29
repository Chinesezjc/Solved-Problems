//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,sum[21][100001],dp[1<<20],has[1<<20],s,tmp;
int dfs(int now)
{
	if(dp[now]!=INF)
	{
		return dp[now];
	}
	for(int i=0;i<m;++i)
	{
		if(now&(1<<i))
		{
			dp[now]=min(dp[now],dfs(now^(1<<i))+sum[i+1][n]-sum[i+1][has[now]]+sum[i+1][has[now^(1<<i)]]);
		}
	}
	return dp[now];
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			sum[j][i]=sum[j][i-1];
		}
		cin>>tmp;
		++sum[tmp][i];
	}
	s=1<<m;
	for(int i=0;i<s;++i)
	{
		dp[i]=INF;
		for(int j=0;j<m;++j)
		{
			if(i&(1<<j))
			{
				has[i]+=sum[j+1][n];
			}
		}
	}
	dp[0]=0;
	cout<<dfs(s-1)<<endl;
	return 0;
}

