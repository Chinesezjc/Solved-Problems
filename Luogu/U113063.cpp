//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
char map[101][12];
int n,m,dp[2][12],ans=INF;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=n;i>0;--i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>map[i][j];
		}
	}
	dp[0][0]=dp[1][0]=dp[0][m+1]=dp[1][m+1]=INF;
	for(int i=1;i<<1<=n+1;++i)
	{
		for(int j=1;j<=m;++j)
		{
			dp[i&1][j]=min(min(dp[(i-1)&1][j-1],dp[(i-1)&1][j+1]),dp[(i-1)&1][j]+(map[(i<<1)-1][j]-'0'))+map[i<<1][j]-'0';
		}
	}
	for(int i=1;i<=m;++i)
	{
		ans=min(ans,dp[((n+1)>>1)&1][i]);
	}
	cout<<ans<<endl;
	return 0;
}

