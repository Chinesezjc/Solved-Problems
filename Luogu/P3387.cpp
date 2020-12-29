//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int fa[2000001],n,m,head[2000001],dfn[2000001],low[2000001],v[2000001],ans[2000001],f,Max;
bool ins[2000001];
stack <int> init;
struct E{
	int n,t;
}e[2000001];
void Tarjan(int now)
{
	ins[now]=true;
	dfn[now]=low[now]=++f;
	init.push(now);
	for(int i=head[now];i;i=e[i].n)
	{
		if(!dfn[e[i].t])
		{
			Tarjan(fa[e[i].t]);
			low[now]=min(low[now],low[e[i].t]);
		}
		else if(ins[fa[e[i].t]])
		{
			low[now]=min(low[now],low[e[i].t]);
		}
	}
	if(dfn[now]==low[now])
	{
		int tmp=init.top();
		while(tmp!=now)
		{
			fa[tmp]=now;
			int i=head[tmp];
			while(e[i].n)
			{
				i=e[i].n;
			}
			e[i].n=head[now];
			head[now]=head[tmp];
			head[tmp]=0;
			ins[tmp]=false;
			v[now]+=v[tmp];
			init.pop();
			tmp=init.top();
		}
		ins[now]=false;
		init.pop();
	}
}
int dfs(int now)
{
	if(ans[now]!=-1)
	{
		return ans[now];
	}
	int tmp=0;
	for(int i=head[now];i;i=e[i].n)
	{
		if(fa[e[i].t]==now)
		{
			continue;
		}
		tmp=max(tmp,dfs(fa[e[i].t]));
	}
	return ans[now]=tmp+v[now];
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>v[i];
		fa[i]=i;
		dfn[i]=0;
		low[i]=0;
		head[i]=0;
		ans[i]=-1;
	}
	for(int i=1;i<=m;++i)
	{
		cin>>f>>e[i].t;
		e[i].n=head[f];
		head[f]=i;
	}
	f=0;
	for(int i=1;i<=n;++i)
	{
		if(!dfn[i])
		{
			Tarjan(i);
		}
	}
	for(int i=1;i<=n;++i)
	{
		Max=max(Max,dfs(i));
	}
	cout<<Max;
	return 0;
}

