//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,fa[100001],head[100001],x,y,cnt;
struct way{
	int next,to;
}way[200000];
int dfs(int now)
{
	if(!way[head[now]].next&&now!=1)
	{
		return -1;
	}
	int ans=1,tmp;
	for(int i=head[now];i;i=way[i].next)
	{
		if(fa[now]==way[i].to)
		{
			continue;
		}
		tmp=dfs(way[i].to);
		if(tmp==-1)
		{
			++ans;
			continue;
		}
		ans+=tmp<<1;
	}
	return ans>>1;
}
void add(int f,int t)
{
	++cnt;
	way[cnt].to=t;
	way[cnt].next=head[f];
	head[f]=cnt;
}
void gettree(int now)
{
	for(int i=head[now];i;i=way[i].next)
	{
		if(fa[now]==way[i].to)
		{
			continue;
		}
		fa[way[i].to]=now;
		gettree(way[i].to);
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<n;++i)
	{
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	gettree(1);
	for(int i=1;i<n;++i)
	{
		for(int j=head[i];j;j=way[j].next)
		{
			if(fa[i]==way[j].to)
			{
				continue;
			}
		}
	}
	int ans=dfs(1);
	if(ans==-1)
	{
		ans=0;
	}
	cout<<ans;
	return 0;
}

