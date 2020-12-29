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
vector <pair<int,int> > w[100001];
int n,m,s,t,a,b,c,dis[100001];
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > que;
bool went[100001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b>>c;
		w[a].push_back(make_pair(b,c));
		w[b].push_back(make_pair(a,c));
	}
	fill(dis+1,dis+1+n,INF);
	dis[s]=0;
	que.push(make_pair(0,s));
	while(!que.empty())
	{
		int now=que.top().second;
		que.pop();
		if(went[now])
		{
			continue;
		}
		went[now]=true;
		for(int i=w[now].size()-1;i>=0;--i)
		{
			if(dis[w[now][i].first]>dis[now]+w[now][i].second)
			{
				dis[w[now][i].first]=dis[now]+w[now][i].second;
				que.push(make_pair(dis[w[now][i].first],w[now][i].first));
			}
		}
	}
	cout<<dis[t]<<endl;
	return 0;
}
