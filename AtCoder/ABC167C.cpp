//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,x,c[15],g[15][15],ans=INF,l[15],sum[15][15];
bool check()
{
	for(int i=1;i<=m;++i)
	{
		if(l[i]<x)
		{
			return false;
		}
	}
	return true;
}
void dfs(int i,int now)
{
	if(now>=ans)
	{
		return;
	}
	if(check())
	{
		ans=now;
	}
	while(i<n)
	{
		++i;
		for(int j=1;j<=m;++j)
		{
			l[j]+=g[i][j];
		}
		dfs(i,now+c[i]);
		for(int j=1;j<=m;++j)
		{
			l[j]-=g[i][j];
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>x;
	for(int i=1;i<=n;++i)
	{
		cin>>c[i];
		for(int j=1;j<=m;++j)
		{
			cin>>g[i][j];
			sum[i][j]=sum[i-1][j]+g[i][j];
		}
	}
	dfs(0,0);
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

