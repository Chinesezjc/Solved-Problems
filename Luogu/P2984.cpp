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
int a,b,c,n,m,B,dis[50001];
vector <pair<int,int> > w[50001];
queue <int> q;
bool init[50001];
void spfa()
{
	q.push(1);
	init[1]=true;
	while(!q.empty())
	{
		int now=q.front();
		init[now]=false;
		q.pop();
		for(int i=w[now].size()-1;i>=0;--i)
		{
			if(dis[w[now][i].second]>dis[now]+w[now][i].first)
			{
				dis[w[now][i].second]=dis[now]+w[now][i].first;
				if(!init[w[now][i].second])
				{
					q.push(w[now][i].second);
					init[w[now][i].second]=true;
				}
			}
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>B;
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b>>c;
		w[a].push_back(make_pair(c,b));
		w[b].push_back(make_pair(c,a));
	}
	fill(dis+2,dis+1+n,INF);
	spfa();
	for(int i=1;i<=B;++i)
	{
		cin>>a>>b;
		cout<<dis[a]+dis[b]<<endl;
	}
	return 0;
}

