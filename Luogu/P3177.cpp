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
vector <int> son[2001];
int n,k,head[2001],to[4001],dis[4001],nex[4001],a,b,c,cnt,size[2001],dp[2001][2001],fad[2001];
bool did[2001];
int findtree(int now)
{
	size[now]=1;
	for(int i=head[now];i;i=nex[i])
	{
		if(!did[to[i]])
		{
			did[to[i]]=true;
			son[now].push_back(to[i]);
			fad[to[i]]=dis[i];
			size[now]+=findtree(to[i]);
		}
	}
	return size[now];
}
void dfs(int now)
{
	int sum=0;
	if(size[now]==1)
	{
		dp[now][1]=fad[now]*(1*(k-1)+(size[now]-1)*(n-k-size[now]+1));
		dp[now][0]=fad[now]*(size[now]*(n-k-size[now]));
		return;
	}
	for(int i=0;i<son[now].size();++i)
	{
		dfs(son[now][i]);
		sum+=size[son[now][i]];
		for(int j=min(sum,k);j>=0;--j)
		{
			dp[now][j]=dp[now][j]+dp[son[now][i]][0];
			int s=min(size[son[now][i]],j);
			for(int l=1;l<=s;++l)
			{
				dp[now][j]=max(dp[now][j],dp[now][j-l]+dp[son[now][i]][l]);
			}
		}
	}
	for(int i=size[now];i;--i)
	{
		dp[now][i]=max(dp[now][i-1],dp[now][i])+fad[now]*(i*(k-i)+(size[now]-i)*(n-k-size[now]+i));
	}
	dp[now][0]=dp[now][0]+fad[now]*(size[now]*(n-k-size[now]));
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>k;
	if(n-k<k)
	{
		k=n-k;
	}
	for(int i=1;i<n;++i)
	{
		cin>>a>>b>>c;
		++cnt;
		to[cnt]=a;
		dis[cnt]=c;
		nex[cnt]=head[b];
		head[b]=cnt;
		++cnt;
		to[cnt]=b;
		dis[cnt]=c;
		nex[cnt]=head[a];
		head[a]=cnt;
	}
	did[1]=true;
	findtree(1);
	for(int i=1;i<=n;++i)
	{
		fill(dp[i]+1,dp[i]+1+n,-INF);
	}
	dfs(1);
	cout<<dp[1][k]<<endl;
	return 0;
}

