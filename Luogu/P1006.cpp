//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,dp[201][101][101],num[101][101];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			cin>>num[i][j];
		}
	}
	for(int i=1;i<n+m;++i)
	{
		for(int j=1;j<=n&&i-j>=0;++j)
		{
			if(i-j<0)
			{
				continue;
			}
			for(int k=1;k<=n&&i-k>=0;++k)
			{
				if(j==k||i-k<0)
				{
					continue;
				}
				dp[i][j][k]=max(max(dp[i-1][j][k],dp[i-1][j-1][k-1]),max(dp[i-1][j-1][k],dp[i-1][j][k-1]))+num[i-j+1][j]+num[i-k+1][k];
			}
		}
	}
	cout<<max(max(dp[n+m-1][n][n],dp[n+m-1][n-1][n-1]),max(dp[n+m-1][n-1][n],dp[n+m-1][n][n-1]));
	return 0;
}

