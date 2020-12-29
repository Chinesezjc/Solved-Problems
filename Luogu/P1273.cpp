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
int n,m,k,dp[3001][3001];
bool did[3001];
struct way{
	int to,v;
};
vector <way> to[3001];
int dfs(int now)
{
	if(to[now].size()==0)
	{
		return 1;
	}
	int d[2][3001],sum=0;;
	fill(d[0]+1,d[0]+3001,-INF);
	fill(d[1]+1,d[1]+3001,-INF);
	d[0][0]=d[1][0]=0;
	for(int i=0;i<to[now].size();++i)
	{
		int len=dfs(to[now][i].to);
		sum+=len;
		for(int j=1;j<=sum;++j)
		{
			d[i&1][j]=d[(i+1)&1][j];
		}
		for(int j=1;j<=len;++j)
		{
			for(int k=sum;k>=j;--k)
			{
				d[i&1][k]=max(d[i&1][k],d[(i+1)&1][k-j]+dp[to[now][i].to][j]-to[now][i].v);
			}
		}
	}
	for(int i=1;i<=sum;++i)
	{
		dp[now][i]=d[(to[now].size()+1)&1][i];
	}
	return sum;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n-m;++i)
	{
		cin>>k;
		to[i].resize(k);
		for(int j=0;j<k;++j)
		{
			cin>>to[i][j].to>>to[i][j].v;
		}
	}
	for(int i=1;i<=n;++i)
	{
		fill(dp[i]+1,dp[i]+1+n,-INF);
	}
	for(int i=n-m+1;i<=n;++i)
	{
		cin>>k;
		dp[i][1]=k;
	}
	dfs(1);
	for(int i=m;i>=0;--i)
	{
		if(dp[1][i]>=0)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}

