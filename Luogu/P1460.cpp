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
int n,m,need[30],a[30][30],has[30],nowa[30],now,ansa[30],ans=INF;
bool check()
{
	for(int i=1;i<=n;++i)
	{
		if(has[i]<need[i])
		{
			return false;
		}
	}
	return true;
}
void dfs()
{
	int i=nowa[now];
	if(ans<=now)
	{
		return;
	}
	if(check())
	{
		ans=now;
		for(int j=1;j<=now;++j)
		{
			ansa[j]=nowa[j];
		}
		return;
	}
	while(i<m)
	{
		++i;
		for(int j=1;j<=n;++j)
		{
			has[j]+=a[i][j];
		}
		nowa[++now]=i;
		dfs();
		--now;
		for(int j=1;j<=n;++j)
		{
			has[j]-=a[i][j];
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>need[i];
	}
	cin>>m;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			cin>>a[i][j];
		}
	}
	dfs();
	cout<<ans;
	for(int i=1;i<=ans;++i)
	{
		cout<<' '<<ansa[i];
	}
	return 0;
}

