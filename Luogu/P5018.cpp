//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,ans;
struct NODE{
	int v,l,r,s;
}tree[1000001];
int dfs(int now)
{
	if(now==-1)
	{
		return 0;
	}
	return tree[now].s=1+dfs(tree[now].l)+dfs(tree[now].r);
}
bool check(int a,int b)
{
	return (a==-1&&b==-1)||(tree[a].v==tree[b].v&&check(tree[a].l,tree[b].r)&&check(tree[a].r,tree[b].l));
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>tree[i].v;
	}
	for(int i=1;i<=n;++i)
	{
		cin>>tree[i].l>>tree[i].r;
	}
	dfs(1);
	for(int i=1;i<=n;++i)
	{
		if(check(tree[i].l,tree[i].r))
		{
			ans=max(tree[i].s,ans);
		}
	}
	cout<<ans;
	return 0;
}

