//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,c,r,a[17][17],b[17],num[17][17],d[17],ans=INF,dp[17];
void DP()
{
	for(int i=1;i<m;++i)
	{
		for(int j=i+1;j<=m;++j)
		{
			a[i][j]=0;
			for(int k=1;k<=r;++k)
			{
				a[i][j]+=abs(num[d[k]][i]-num[d[k]][j]);
			}
		}
	}
	for(int i=1;i<=m;++i)
	{
		b[i]=0;
		for(int j=1;j<r;++j)
		{
			b[i]+=abs(num[d[j]][i]-num[d[j+1]][i]);
		}
		dp[i]=b[i];
	}
	for(int i=2;i<=c;++i)
	{
		for(int j=m;j>=i;--j)
		{
			dp[j]=dp[i-1]+b[j]+a[i-1][j];
			for(int k=i;k<j;++k)
			{
				dp[j]=min(dp[j],dp[k]+b[j]+a[k][j]);
			}
		}
	}
	for(int i=c;i<=m;++i)
	{
		ans=min(ans,dp[i]);
	}
}
void dfs(int now,int i)
{
	if(now>r)
	{
		DP();
		return;
	}
	for(++i;i<=n;++i)
	{
		d[now]=i;
		dfs(now+1,i);
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>r>>c;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>num[i][j];
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

