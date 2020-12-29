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
int n,m,dis[1000001],a[1000001],b[1000001],c[1000001],ans,t;
vector <pair<int,int> > w[1000001];
bool init[1000001];
queue <int> q;
void spfa()
{
	init[1]=true;
	q.push(1);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		init[now]=false;
		for(int i=w[now].size()-1;i>=0;--i)
		{
			if(dis[w[now][i].first]>dis[now]+w[now][i].second)
			{
				dis[w[now][i].first]=dis[now]+w[now][i].second;
				if(!init[w[now][i].first])
				{
					init[w[now][i].first]=true;
					q.push(w[now][i].first);
				}
			}
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n>>m;
		for(int i=1;i<=m;++i)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		ans=0;
		fill(dis+2,dis+1+n,INF);
		for(int i=1;i<=n;++i)
		{
			w[i].clear();
		}
		for(int i=1;i<=m;++i)
		{
			w[a[i]].push_back(make_pair(b[i],c[i]));
		}
		spfa();
		for(int i=1;i<=n;++i)
		{
			ans+=dis[i];
		}
		fill(dis+2,dis+1+n,INF);
		for(int i=1;i<=n;++i)
		{
			w[i].clear();
		}
		for(int i=1;i<=m;++i)
		{
			w[b[i]].push_back(make_pair(a[i],c[i]));
		}
		spfa();
		for(int i=1;i<=n;++i)
		{
			ans+=dis[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}

