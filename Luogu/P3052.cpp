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
int n,m,w[19],s;
pair<int,int>dp[1<<18];
pair<int,int>dfs(int now)
{
	if(dp[now].first!=INF&&dp[now].second!=INF)
	{
		return dp[now];
	}
	for(int i=0;i<n;++i)
	{
		if(now&(1<<i))
		{
			pair<int,int>f=dfs(now^(1<<i));
			if(f.second+w[i]<=m)
			{
				f.second+=w[i];
				dp[now]=min(dp[now],f);
			}
			else
			{
				++f.first;
				f.second=w[i];
				dp[now]=min(dp[now],f);
			}
		}
	}
	return dp[now];
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	s=1<<n;
	for(int i=0;i<n;++i)
	{
		cin>>w[i];
	}
	for(int i=1;i<s;++i)
	{
		dp[i].first=dp[i].second=INF;
	}
	pair<int,int>ans=dfs(s-1);
	if(ans.second>0)
	{
		++ans.first;
	}
	cout<<ans.first<<endl;
	return 0;
}

