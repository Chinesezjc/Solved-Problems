//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int dis[101][101],n,m,k,s,t,c[101],head[101],cnt,ans=INF,x,y,z;
bool learned[101],a[101][101];
struct Edge{
	int n,t,v;
}e[10001];
void add(int x,int y,int z)
{
	++cnt;
	e[cnt].n=head[x];
	e[cnt].t=y;
	e[cnt].v=z;
	head[x]=cnt;
}
bool agree(int now)
{
	for(int i=1;i<=k;++i)
	{
		if(a[now][i]&&learned[i])
		{
			return false;
		}
	}
	return true;
}
void dfs(int now,int sum)
{
	if(dis[now][t]+sum>=ans)
	{
		return;
	}
	if(now==t)
	{
		ans=sum;
		return;
	}
	if(learned[c[t]])
	{
		return;
	}
	for(int i=head[now];i;i=e[i].n)
	{
		if(!learned[c[e[i].t]]&&agree(c[e[i].t])&&!a[c[t]][c[e[i].t]])
		{
			learned[c[e[i].t]]=true;
			dfs(e[i].t,sum+e[i].v);
			learned[c[e[i].t]]=false;
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>k>>m>>t>>s;
	for(int i=1;i<=n;++i)
	{
		cin>>c[i];
		fill(dis[i]+1,dis[i]+1+n,INF);
		dis[i][i]=0;
	}
	for(int i=1;i<=k;++i)
	{
		for(int j=1;j<=k;++j)
		{
			cin>>x;
			a[i][j]=x==1?true:false;
		}
	}
	for(int i=1;i<=m;++i)
	{
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
		dis[x][y]=dis[y][x]=z;
	}
	for(int f=1;f<=n;++f)
	{
		for(int i=1;i<=n;++i)
		{
			if(i==f)
			{
				continue;
			}
			for(int j=1;j<=n;++j)
			{
				if(j==i||j==f)
				{
					continue;
				}
				dis[i][j]=min(dis[i][j],dis[i][f]+dis[f][j]);
			}
		}
	}
	learned[c[s]]=true;
	if(!learned[c[t]]&&dis[s][t]!=INF&&!a[c[t]][c[s]])
	{
		dfs(s,0);
	}
	cout<<(ans==INF?-1:ans);
	return 0;
}

