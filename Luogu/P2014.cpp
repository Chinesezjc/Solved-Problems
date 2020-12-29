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
int s[301],n,m,k,dp[301][301];
vector <int> son[301];
int dfs(int now)
{
	int sum=1;
	dp[now][1]=s[now];
	for(int i=0;i<son[now].size();++i)
	{
		int len=dfs(son[now][i]);
		sum+=len;
		for(int j=sum;j>1;--j)
		{
			for(int k=1;k<=len&&k<j;++k)
			{
				dp[now][j]=max(dp[now][j],dp[now][j-k]+dp[son[now][i]][k]);
			}
		}
	}
	return sum;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	++m;
	for(int i=1;i<=n;++i)
	{
		cin>>k>>s[i];
		son[k].push_back(i);
	}
	dfs(0);
	cout<<dp[0][m]<<endl;
	return 0;
}

