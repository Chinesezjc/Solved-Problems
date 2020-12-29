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
int n,m,a,b,c,dis[4][3001],ans;
bool init[3001],isans[3001];
vector <pair<int,int> > to[3001];
vector <int> from[4][3001];
queue <int> q;
void spfa(int now)
{
	fill(dis[now]+1,dis[now]+1+n,INF);
	dis[now][now]=0;
	q.push(now);
	init[now]=true;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		init[x]=false;
		for(int i=0;i<to[x].size();++i)
		{
			if(dis[now][to[x][i].second]>dis[now][x]+to[x][i].first)
			{
				dis[now][to[x][i].second]=dis[now][x]+to[x][i].first;
				from[now][to[x][i].second].clear();
				if(!init[to[x][i].second])
				{
					q.push(to[x][i].second);
					init[to[x][i].second]=true;
				}
			}
			if(dis[now][to[x][i].second]==dis[now][x]+to[x][i].first)
			{
				from[now][to[x][i].second].push_back(x);
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
		cin>>a>>b>>c;
		to[a].push_back(make_pair(c,b));
		to[b].push_back(make_pair(c,a));
	}
	spfa(1);
	spfa(2);
	spfa(3);
	for(int i=1;i<=n;++i)
	{
		fill(init+1,init+1+n,false);
		isans[i]=true;
		++ans;
		for(int j=1;j<=3&&isans[i];++j)
		{
			if(dis[j][i]==INF)
			{
				cout<<"impossible"<<endl;
				return 0;
			}
			for(int k=0;k<from[j][i].size();++k)
			{
				if(init[from[j][i][k]])
				{
					isans[i]=false;
					--ans;
					break;
				}
				init[from[j][i][k]]=true;
			}
		}
	}
	if(ans==0)
	{
		cout<<"impossible"<<endl;
		return 0;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;++i)
	{
		if(isans[i])
		{
			cout<<i<<' ';
		}
	}
	cout<<endl;
	return 0;
}

