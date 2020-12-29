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
int n,m,dis[201],a,b,c,s,t;
vector <pair<int,int> > w[201];
bool init[201];
queue <int> q;
void spfa()
{
	init[s]=true;
	q.push(s);
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
	while(cin>>n>>m)
	{
		for(int i=0;i<n;++i)
		{
			w[i].clear();
			dis[i]=INF;
		}
		for(int i=1;i<=m;++i)
		{
			cin>>a>>b>>c;
			w[a].push_back(make_pair(b,c));
			w[b].push_back(make_pair(a,c));
		}
		cin>>s>>t;
		dis[s]=0;
		spfa();
		cout<<(dis[t]>=INF?-1:dis[t])<<endl;
	}
	return 0;
}

