//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a[21],n,m,ans;
bool dp[2001],can[21];
void dfs(int i,int cho)
{
	if(cho==m)
	{
		int tmp=0;
		fill(dp+1,dp+2001,false);
		for(int i=1;i<=n;++i)
		{
			if(can[i])
			{
				continue;
			}
			for(int j=2000;j>=a[i];--j)
			{
				dp[j]=dp[j]||dp[j-a[i]];
			}
		}
		for(int i=1;i<=2000;++i)
		{
			if(dp[i])
			{
				++tmp;
			}
		}
		ans=max(tmp,ans);
		return;
	}
	while(i<n)
	{
		++i;
		can[i]=true;
		dfs(i,cho+1);
		can[i]=false;
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	dp[0]=true;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}

