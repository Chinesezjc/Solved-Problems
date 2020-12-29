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
vector <int> son[151];
int n,p,dp[151][151],a,b,ans;
int dfs(int now)
{
	int sum=1;
	fill(dp[now],dp[now]+n+1,INF);
	dp[now][1]=son[now].size();
	for(int i=0;i<son[now].size();++i)
	{
		int len=dfs(son[now][i]);
		sum+=len;
		for(int j=sum;j>0;--j)
		{
			for(int k=1;k<=len&&k<j;++k)
			{
				dp[now][j]=min(dp[now][j],dp[now][j-k]-1+dp[son[now][i]][k]);
			}
		}
	}
	return sum;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>p;
	for(int i=1;i<n;++i)
	{
		cin>>a>>b;
		son[a].push_back(b);
	}
	dfs(1);
	ans=dp[1][p];
	for(int i=2;i<=n;++i)
	{
		ans=min(ans,dp[i][p]+1);
	}
	cout<<ans<<endl;
	return 0;
}

