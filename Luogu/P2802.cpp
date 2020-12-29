//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<iomanip>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int dp[15][15][10],a[15][15],n,m,endx,endy;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>a[i][j];
			if(a[i][j]==3)
			{
				endx=i;
				endy=j;
			}
		}
	}
	for(int i=0;i<=n+1;++i)
	{
		for(int j=0;j<=m+1;++j)
		{
			if(a[i][j]!=2)
			{
				for(int k=0;k<=9;++k)
				{
					dp[i][j][k]=INF;
				}
			}
			else
			{
				for(int k=7;k<=9;++k)
				{
					dp[i][j][k]=INF;
				}
			}
		}
	}
	for(int t=1;t<=n*m*5;++t)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(a[i][j]==0)
				{
					continue;
				}
				if(a[i][j]==1||a[i][j]==2||a[i][j]==3)
				{
					for(int k=1;k<=6;++k)
					{
						dp[i][j][k]=min(dp[i][j][k],min(min(dp[i][j+1][k+1],dp[i][j-1][k+1]),min(dp[i+1][j][k+1],dp[i-1][j][k+1]))+1);
					}
					continue;
				}
				if(a[i][j]==4)
				{
					for(int k=2;k<=6;++k)
					{
						dp[i][j][6]=min(dp[i][j][6],min(min(dp[i][j+1][k],dp[i][j-1][k]),min(dp[i+1][j][k],dp[i-1][j][k]))+1);
					}
					continue;
				}
			}
		}
	}
	int ans=min(min(min(min(min(dp[endx][endy][1],dp[endx][endy][2]),dp[endx][endy][3]),dp[endx][endy][4]),dp[endx][endy][5]),dp[endx][endy][6]);
	if(ans>=INF)
	{
		cout<<"-1"<<endl;
	}
	else
	{
		cout<<ans<<endl;
	}
	return 0;
}

