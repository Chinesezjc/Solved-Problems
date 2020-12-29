//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int dp[10001][501],n,m,d;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>d;
		for(int j=1;j<=m;++j)
		{
			dp[i][j]=dp[i-1][j-1]+d;
		}
		for(int j=min(m,i);j>=0;--j)
		{
			dp[i][0]=max(dp[i][0],max(dp[i-j][j],dp[i-j][0]));
		}
	}
	cout<<dp[n][0];
	return 0;
}

