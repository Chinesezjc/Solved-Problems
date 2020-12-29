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
#define INF 1000000000
using namespace std;
int n,m,dis[3001],h[3001],times[3001],a,b,c,ans;
vector <pair<int,int> > w[3001];
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
queue <int> que;
bool init[3001];
void spfa()
{
	fill(h+1,h+1+n,1);
	que.push(0);
	init[0]=true;
	while(!que.empty())
	{
		int now=que.front();
		init[now]=false;
		que.pop();
		if(times[now]>n)
		{
			cout<<-1<<endl;
			exit(0);
		}
		++times[now];
		for(int i=0;i<w[now].size();++i)
		{
			if(h[w[now][i].second]>h[now]+w[now][i].first)
			{
				h[w[now][i].second]=h[now]+w[now][i].first;
				if(!init[w[now][i].second])
				{
					que.push(w[now][i].second);
					init[w[now][i].second]=true;
				}
			}
		}
	}
}
void dij(int now)
{
	fill(dis+1,dis+1+n,INF);
	fill(init+1,init+1+n,false);
	dis[now]=0;
	q.push(make_pair(0,now));
	while(!q.empty())
	{
		int nxt=q.top().second;
		q.pop();
		if(init[nxt])
		{
			continue;
		}
		init[nxt]=true;
		for(int i=0;i<w[nxt].size();++i)
		{
			if(!init[w[nxt][i].second]&&dis[w[nxt][i].second]>dis[nxt]+w[nxt][i].first)
			{
				dis[w[nxt][i].second]=dis[nxt]+w[nxt][i].first;
				q.push(make_pair(dis[w[nxt][i].second],w[nxt][i].second));
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
		w[a].push_back(make_pair(c,b));
	}
	for(int i=1;i<=n;++i)
	{
		w[0].push_back(make_pair(0,i));
	}
	spfa();
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<w[i].size();++j)
		{
			w[i][j].first-=h[w[i][j].second]-h[i];
		}
	}
	for(int i=1;i<=n;++i)
	{
		dij(i);
		ans=0;
		for(int j=1;j<=n;++j)
		{
			if(dis[j]!=INF)
			{
				ans+=j*(dis[j]-h[i]+h[j]);
			}
			else
			{
				ans+=j*INF;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

