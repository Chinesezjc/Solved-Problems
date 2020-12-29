//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int dis[1501][1501],u,v,w,head[1501],n,m;
bool went[1501],did[1501][1501];
struct EDGE{
	int n,t,v,ans;
}e[5001];
struct point{
	int p,dis;
	bool operator < (const point B)const
	{
		return dis>B.dis;
	}
};
priority_queue <point> heap;
point Point(int p,int dis)
{
	point tmp;
	tmp.p=p;
	tmp.dis=dis;
	return tmp;
}
void dfs(int f,int t,int people)
{
	did[f][t]=true;
	if(f==t||dis[f][t]==INF)
	{
		return;
	}
	for(int i=head[f];i;i=e[i].n)
	{
		if(dis[f][t]==dis[e[i].t][t]+e[i].v)
		{
			e[i].ans+=people;
			if(did[e[i].t][t])
			{
				dfs(e[i].t,t,people);
			}
			else
			{
				dfs(e[i].t,t,people+1);
			}
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>u>>v>>w;
		e[i].n=head[u];
		e[i].t=v;
		e[i].v=w;
		head[u]=i;
	}
	for(int i=1;i<=n;++i)
	{
		fill(dis[i]+1,dis[i]+1+n,INF);
		fill(went+1,went+1+n,false);
		dis[i][i]=0;
		heap.push(Point(i,dis[i][i]));
		while(!heap.empty())
		{
			int now=heap.top().p;
			heap.pop();
			if(went[now])
			{
				continue;
			}
			for(int j=head[now];j;j=e[j].n)
			{
				if(dis[i][e[j].t]>dis[i][now]+e[j].v)
				{
					dis[i][e[j].t]=dis[i][now]+e[j].v;
					heap.push(Point(e[j].t,dis[i][e[j].v]));
				}
			}
			went[now]=true;
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(!did[i][j])
			{
				dfs(i,j,1);
			}
		}
	}
	for(int i=1;i<=m;++i)
	{
		cout<<e[i].ans<<endl;
	}
	return 0;
}

