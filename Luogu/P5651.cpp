//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,q,x,y,v,cnt,head[100001],ans,dis[100001];
bool went[100001];
struct EDGE{
	int n,v,t;
}e[400001];
void add(int a,int b,int c)
{
	++cnt;
	e[cnt].n=head[a];
	e[cnt].t=b;
	e[cnt].v=c;
	head[a]=cnt;
}
void dfs(int now,int sum)
{
	dis[now]=sum;
	for(int i=head[now];i;i=e[i].n)
	{
		if(!went[e[i].t])
		{
			went[e[i].t]=true;
			dfs(e[i].t,sum^e[i].v);
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>x>>y>>v;
		add(x,y,v);
		add(y,x,v);
	}
	dfs(1,0);
	for(int i=1;i<=q;++i)
	{
		cin>>x>>y;
		cout<<(dis[x]^dis[y])<<endl;
	}
	return 0;
}

