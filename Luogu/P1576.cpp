//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,a,b,c,f,t;
double dis[2001];
vector <pair<int,int> > w[2001];
bool went[2001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b>>c;
		w[a].push_back(make_pair(c,b));
		w[b].push_back(make_pair(c,a));
	}
	fill(dis,dis+1+n,INF);
	cin>>t>>f;
	dis[f]=100;
	for(int i=2;i<=n;++i)
	{
		int now=0;
		for(int j=1;j<=n;++j)
		{
			if(!went[j]&&dis[now]>dis[j])
			{
				now=j;
			}
		}
		went[now]=true;
		for(int j=w[now].size()-1;j>=0;--j)
		{
			if(dis[w[now][j].second]>dis[now]*100/(100-w[now][j].first))
			{
				dis[w[now][j].second]=dis[now]*100/(100-w[now][j].first);
			}
		}
	}
	cout<<fixed<<setprecision(8)<<dis[t]<<endl;
	return 0;
}

