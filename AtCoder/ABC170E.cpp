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
priority_queue <pair<int,int>,vector<pair<int,int> >,less<pair<int,int> > > g[200001];
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > ans;
int a[200001],b[200001],c[200001],d[200001],n,q;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>b[i];
		g[b[i]].push(make_pair(a[i],i));
	}
	for(int i=1;i<=200000;++i)
	{
		if(!g[i].empty())
		{
			ans.push(make_pair(g[i].top().first,i));
		}
	}
	for(int i=1;i<=q;++i)
	{
		cin>>c[i]>>d[i];
		int tmp=b[c[i]];
		b[c[i]]=d[i];
		if(g[tmp].top().second==c[i])
		{
			g[tmp].pop();
			while(!g[tmp].empty()&&b[g[tmp].top().second]!=tmp)
			{
				g[tmp].pop();
			}
			if(!g[tmp].empty())
			{
				ans.push(make_pair(g[tmp].top().first,tmp));
			}
		}
		g[d[i]].push(make_pair(a[c[i]],c[i]));
		ans.push(make_pair(g[d[i]].top().first,d[i]));
		while(!ans.empty()&&(g[ans.top().second].empty()||g[ans.top().second].top().first!=ans.top().first))
		{
			ans.pop();
		}
		cout<<ans.top().first<<endl;
	}
	return 0;
}

