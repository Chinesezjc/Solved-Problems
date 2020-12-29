//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,to[200001],tim[200001],first,ans=INF,cnt;
void dfs(int now)
{
	if(tim[to[now]])
	{
		if(tim[to[now]]>=tim[first])
		{
			ans=min(ans,tim[now]-tim[to[now]]+1);
		}
	}
	else
	{
		tim[to[now]]=++cnt;
		dfs(to[now]);
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>to[i];
	}
	for(int i=1;i<=n;++i)
	{
		if(!tim[i])
		{
			first=i;
			tim[i]=++cnt;
			dfs(i);
		}
	}
	cout<<ans;
	return 0;
}

