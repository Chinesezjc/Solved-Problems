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
int n,m,dis[101][101],l[101][101],a,b,c,d;
bool good[101][101];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			l[i][j]=INF;
		}
	}
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b>>c;
		l[a][b]=min(l[a][b],c);
		l[b][a]=min(l[b][a],c);
	}
	cin>>d;
	for(int i=1;i<=d;++i)
	{
		cin>>a>>b;
		good[a][b]=true;
		good[b][a]=true;
	}
	cin>>a>>b;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(l[i][j]!=INF)
			{
				dis[i][j]=l[i][j];
				if(!good[i][j])
				{
					dis[i][j]=0;
				}
			}
		}
	}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	cout<<dis[a][b]<<endl;
	return 0;
}

