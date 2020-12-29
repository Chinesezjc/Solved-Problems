//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int dp[31][31],n,m;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	dp[0][0]=1;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			dp[i][j%n]=dp[i-1][(j-1)%n]+dp[i-1][(j+1)%n];
		}
	}
	cout<<dp[m][n%n];
	return 0;
}

