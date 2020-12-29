//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,fa[100001],a,b,c,t,buy[100001],sell[100001],money[100001],ans[100001];
vector <pair<int,int> > son[100001];
inline void read(int &now)
{
	now=0;
	register char c=getchar();
	while('0'>c||c>'9')
	{
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		now=(now<<3)+(now<<1)+(c^'0');
		c=getchar();
	}
}
inline void kill(int now)
{
	for(register int i=son[now].size()-1;i>=0;--i)
	{
		if(son[now][i].first==fa[now])
		{
			swap(son[now][i],son[now][son[now].size()-1]);
			son[now].pop_back();
		}
		else
		{
			fa[son[now][i].first]=now;
			kill(son[now][i].first);
		}
	}
}
inline void DFS(int now)
{
	buy[now]=sell[now]=money[now];
	ans[now]=0;
	for(register int i=son[now].size()-1;i>=0;--i)
	{
		DFS(son[now][i].first);
		buy[now]=min(buy[now],buy[son[now][i].first]+son[now][i].second);
		sell[now]=max(sell[now],sell[son[now][i].first]-son[now][i].second);
		ans[now]=max(ans[now],ans[son[now][i].first]);
	}
	ans[now]=max(ans[now],sell[now]-buy[now]);
}
signed main()
{
	read(t);
	while(t)
	{
		--t;
		read(n);
		fill(fa+1,fa+1+n,0);
		for(register int i=1;i<=n;++i)
		{
			read(money[i]);
			son[i].clear();
		}
		for(register int i=1;i<n;++i)
		{
			read(a);
			read(b);
			read(c);
			son[a].push_back(make_pair(b,c));
			son[b].push_back(make_pair(a,c));
		}
		kill(1);
		DFS(1);
		printf("%lld\n",ans[1]);
	}
	return 0;
}

